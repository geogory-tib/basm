#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/instructions.h"
#include "include/lexer.h"
#include "include/common.h"
#include "include/typedefs.h"
#define VAR_ARGS_DIRECTIVE -1
#define BRANCH_START 3
#define BRANCH_END 10
#define INSTRUCTION_TABLE_SIZE 56
#define DIRECTIVE_TABLE_SIZE 4

typedef struct
{
  char *name;
  int arg_no;
}directive_t;
static directive_t dir_table[4] = {{"byte",1},{"fill",2},{"org",1},{"word",1}};

enum Directive_table_Index{
  BYTE_INDEX = 0,
  FILL_INDEX,
  ORG_INDEX,
  WORD_INDEX
};
typedef struct{
  token_t *buf;
  size_t len;
  size_t cap;
}expr_t;

int append_expression(expr_t *expr,token_t tok)
{
  if (expr->len == expr->cap){
	void *tmp = realloc(expr->buf,(sizeof(token_t) * (expr->cap + 25)));
	if(!tmp)
	  return -1;
	expr->buf = tmp;
	expr->cap += 25;
  }
  expr->buf[expr->len] = tok;
  expr->len++;
  return 0;
}
typedef struct{
  token_t start_tok;
  expr_t expr;
  addrmode_t addr_mode;
  int table_indx;
  byte is_dir;
}parsed_mnemonic;

typedef struct{
  parsed_mnemonic *buf;
  size_t cap;
  size_t len;
}mnemonic_slice;

int append_mnemonic_slice(mnemonic_slice *slice,parsed_mnemonic mnemonic)
{
  if (slice->len == slice->cap){
	void *tmp = realloc(slice->buf,(sizeof(parsed_mnemonic) * (slice->cap + 25)));
	if(!tmp)
	  return -1;
	slice->buf = tmp;
	slice->cap += 25;
  }
  slice->buf[slice->len] = mnemonic;
  slice->len++;
  return 0;
}

typedef struct
{
  char *name;
  byte op_codes[13];
  addrmode_t addr_mode;
}instruction_t;
// this table is just to look up valid opcodes and valid addressing modes
static instruction_t ins_table[56] =
{
  {"adc", ADC_OPS, 0},
  {"and", AND_OPS, 0},
  {"asl", ASL_OPS, 0},
  {"bcc", BCC_OPS, 0},
  {"bcs", BCS_OPS, 0},
  {"beq", BEQ_OPS, 0},
  {"bmi", BMI_OPS, 0},
  {"bne", BNE_OPS, 0},
  {"bpl", BPL_OPS, 0},
  {"bvc", BVC_OPS, 0},
  {"bvs", BVS_OPS, 0},
  {"brk", BRK_OPS, 0},
  {"bit", BIT_OPS, 0},
  {"clc", CLC_OPS, 0},
  {"cld", CLD_OPS, 0},
  {"cli", CLI_OPS, 0},
  {"clv", CLV_OPS, 0},
  {"cmp", CMP_OPS, 0},
  {"cpx", CPX_OPS, 0},
  {"cpy", CPY_OPS, 0},
  {"dec", DEC_OPS, 0},
  {"dex", DEX_OPS, 0},
  {"dey", DEY_OPS, 0},
  {"eor", EOR_OPS, 0},
  {"inc", INC_OPS, 0},
  {"inx", INX_OPS, 0},
  {"iny", INY_OPS, 0},
  {"jmp", JMP_OPS, 0},
  {"jsr", JSR_OPS, 0},
  {"lda", LDA_OPS, 0},
  {"ldx", LDX_OPS, 0},
  {"ldy", LDY_OPS, 0},
  {"lsr", LSR_OPS, 0},
  {"nop", NOP_OPS, 0},
  {"ora", ORA_OPS, 0},
  {"pha", PHA_OPS, 0},
  {"php", PHP_OPS, 0},
  {"pla", PLA_OPS, 0},
  {"plp", PLP_OPS, 0},
  {"rol", ROL_OPS, 0},
  {"ror", ROR_OPS, 0},
  {"rti", RTI_OPS, 0},
  {"rts", RTS_OPS, 0},
  {"sbc", SBC_OPS, 0},
  {"sec", SEC_OPS, 0},
  {"sed", SED_OPS, 0},
  {"sei", SEI_OPS, 0},
  {"sta", STA_OPS, 0},
  {"stx", STX_OPS, 0},
  {"sty", STY_OPS, 0},
  {"tax", TAX_OPS, 0},
  {"tay", TAY_OPS, 0},
  {"tsx", TSX_OPS, 0},
  {"txa", TXA_OPS, 0},
  {"txs", TXS_OPS, 0},
  {"tya", TYA_OPS, 0}
};

static byte addrmode_size[13] = {
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  3,
  3,
  3,
  3,
  2,
  2
};

typedef struct
{
  char *name;
  size_t strlen;
  u32 addr;
}label_t;
typedef struct
{
  label_t *buf;
  size_t cap;
  size_t len;
}label_slice;
int append_label_slice(label_slice *slice,label_t label)
{
  if (slice->len == slice->cap){
	void *tmp = realloc(slice->buf,(sizeof(label_t) * (slice->cap + 25)));
	if(!tmp)
	  return -1;
	slice->buf = tmp;
	slice->cap += 25;
  }
  slice->buf[slice->len] = label;
  slice->len++;
  return 0;
}

typedef struct
{
  byte *buf;
  size_t cap;
}byte_slice;

typedef struct
{
  token_slice input;
  label_slice ltable;
  mnemonic_slice mslice;
  byte_slice output;
  size_t current_pos;
  u32 pc;
  u32 offset;
}parser_t;

extern int pratt_parse(parser_t *parser,expr_t expr,int local);

static inline void append_byte_slice(parser_t *parser,byte *input,int len){
  for(int i = 0; i < len;i++){
	if(parser->pc >= parser->output.cap){
	  parser->output.buf = realloc(parser->output.buf, parser->output.cap + 25);
	  parser->output.cap += 25;
	}
	parser->output.buf[parser->pc] = input[i];
	parser->pc++;
  }
}

parser_t init_parser(token_slice input)
{
  parser_t ret = {0};
  ret.input = input;
  return ret;
}
token_t pull_token(parser_t *parser)
{
  if(parser->current_pos + 1 == parser->input.len)
	return (token_t){0x0,0,TOK_EOF,0x0,0,0};
  parser->current_pos++;
  return parser->input.buf[parser->current_pos];
}
token_t peek_token(parser_t parser)
{
  if(parser.current_pos + 1 == parser.input.len)
	return (token_t){0x0,0,TOK_EOF,0x0,0,0};
  return parser.input.buf[parser.current_pos + 1];
}
int check_if_valid_instruction(token_t tok)
{
  for(int i = 0; i < INSTRUCTION_TABLE_SIZE;i++){
	if(!strncasecmp(tok.raw, ins_table[i].name,tok.str_len))
	  return i;
  }
  return -1;
}
int check_if_valid_directive(token_t tok)
{
  for(int i = 0; i < DIRECTIVE_TABLE_SIZE;i++){
	if(!strncasecmp(tok.raw, dir_table[i].name,tok.str_len))
	  return i;
  }
  return -1;
}
size_t determine_directive_size(parser_t *parser,token_t tok,int table_index,expr_t *expr)
{
  token_t temp_tok;
  switch(table_index){
  case BYTE_INDEX:
	temp_tok = peek_token(*parser);
	for(;temp_tok.type != LABEL && temp_tok.type != MNEMONIC && temp_tok.type != TOK_EOF;){
	  temp_tok = pull_token(parser);
	  append_expression(expr, temp_tok);
	  temp_tok = peek_token(*parser);
	}
	return 1;
  case WORD_INDEX:
	temp_tok = peek_token(*parser);
	for(;temp_tok.type != LABEL && temp_tok.type != MNEMONIC && temp_tok.type != TOK_EOF;){
	  temp_tok = pull_token(parser);
	  append_expression(expr, temp_tok);
	  temp_tok = peek_token(*parser);
	}
	return 2;
  case FILL_INDEX:
	temp_tok = peek_token(*parser);
	for(;temp_tok.type != LABEL && temp_tok.type != MNEMONIC && temp_tok.type != TOK_EOF;){
	  temp_tok = pull_token(parser);
	  switch(temp_tok.type){
	  case COMMA:
		temp_tok = pull_token(parser);
		goto exit_loop;
	  default:
		append_expression(expr, temp_tok);
		break;
	  }
	  temp_tok = peek_token(*parser);
	}
	EXIT_AND_FAIL("Unexpected mnemonic", temp_tok);
  exit_loop:
	size_t final_size = temp_tok.value;
	temp_tok = peek_token(*parser);
	if(temp_tok.type != LABEL && temp_tok.type != MNEMONIC && temp_tok.type != TOK_EOF){
	  EXIT_AND_FAIL("Unexpected Token", temp_tok);
	}
	return final_size; // number of bytes they want to fill;
	// will be stored in the addrmode of this directive;
  case ORG_INDEX:
	temp_tok = peek_token(*parser);
	for(;temp_tok.type != LABEL && temp_tok.type != MNEMONIC && temp_tok.type != TOK_EOF;){
	  temp_tok = pull_token(parser);
	  append_expression(expr, temp_tok);
	  temp_tok = peek_token(*parser);
	}	
	return 0;
  default:
	EXIT_AND_FAIL("mnemonic is neither a vaild instruction nor directive", tok);
  }
}
//handles both absoulute and zeropage addressing
// abs_bias will be 4 when return absoulte addressing modes check insturctions.h to see numeric values to understand
static inline addrmode_t handle_memory_addressing(parser_t *parser,int abs_bias,expr_t *expr) 
{
  token_t tok = peek_token(*parser);
  for(;tok.type != MNEMONIC && tok.type != LABEL && tok.type != TOK_EOF;){
	tok = pull_token(parser);
	if(tok.type == COMMA){
	  tok = peek_token(*parser);
	  if(tok.type != IDENT){
		EXIT_AND_FAIL("Expected Identifer After Comma", tok);
	  }
	 tok =  pull_token(parser);
	 if(tok.str_len > 1){
	   EXIT_AND_FAIL("Invaild Addresing Mode", tok);
	 }
	 switch(tok.raw[0]){
	 case 'X':
	 case 'x':
	   return ZPX + abs_bias;
	 case 'Y':
	 case 'y':
	   return ZPY + abs_bias;
	 default:
	   EXIT_AND_FAIL("Invaild Addressing Mode", tok);
	 }
	}
	append_expression(expr, tok);
	tok = peek_token(*parser);
  }
  return ZEROPAGE + abs_bias;
}

static inline addrmode_t handle_indirect_addrmode(parser_t *parser,expr_t *expr)
{
  token_t tok = peek_token(*parser);
  if(tok.type == MNEMONIC || tok.type == LABEL || tok.type == TOK_EOF){
	EXIT_AND_FAIL("Expected Closing Parenethes", tok);
  }
  for(;tok.type != MNEMONIC && tok.type != LABEL && tok.type != TOK_EOF;){
	tok = pull_token(parser);
	if(tok.type == COMMA){
	  tok = peek_token(*parser);
	  if(tok.type != IDENT){
		EXIT_AND_FAIL("Expected Identifer After Comma", tok);
	  }
	  tok = pull_token(parser);
	  if(tok.str_len > 1){
		EXIT_AND_FAIL("Invaild Addresing Mode", tok);
	  }
	  switch(tok.raw[0]){
	  case 'X':
	  case 'x':
		tok = peek_token(*parser);
		if(tok.type != CLOSED_PAREN){
		  EXIT_AND_FAIL("Expected Close Paren", tok);
		} 
		tok = pull_token(parser);
		return INDEXIND;
	  default:
		EXIT_AND_FAIL("Invaild Addressing Mode", tok);
	  }
	 
	}
	if(tok.type == CLOSED_PAREN)
	  break;
	append_expression(expr, tok);
	tok = peek_token(*parser);
  }
  tok = peek_token(*parser);
  if(tok.type == COMMA){
	tok = pull_token(parser);
	tok = peek_token(*parser);
	if(tok.type != IDENT){
	  EXIT_AND_FAIL("Expected Identifer after Comma", tok);
	}
	tok = pull_token(parser);
	if(tok.str_len > 1){
	  EXIT_AND_FAIL("Invaild Addressing mode", tok);
	}
	switch(tok.raw[0]){
	case 'Y':
	case 'y':
	  tok = peek_token(*parser);
	  if(tok.type != LABEL &&  tok.type != MNEMONIC && tok.type != TOK_EOF){
		EXIT_AND_FAIL("Unexpected Token After Y", tok);
	  }
	  return INDINDEX;
	}
  }
  return INDIRECT;
}
addrmode_t determine_addressing(parser_t *parser,token_t tok,int table_index,expr_t *expr)
{
  if(table_index >= BRANCH_START && table_index <= BRANCH_END){
	token_t temp_tok = pull_token(parser);
	for(;;){
	  temp_tok = peek_token(*parser);
	  if(temp_tok.type != MNEMONIC && temp_tok.type != LABEL && temp_tok.type != TOK_EOF){
		append_expression(expr, temp_tok);
		temp_tok = pull_token(parser);
	  }else{
		break;
	  }
	}
	return RELATIVE;
  }
  switch(tok.type){
  case HEX_NUMBER:
	{
	  append_expression(expr, tok);
	  if(tok.str_len == 2){
		return handle_memory_addressing(parser, ABS_BIAS_VALUE,expr);
	  }
	  return handle_memory_addressing(parser, ABS_BIAS_VALUE,expr);
	  break;
	  
	}
  case DEC_NUMBER:
	{
	  append_expression(expr, tok);
	  if(tok.value <= 255){
		return handle_memory_addressing(parser,0,expr);
	  }
	  return handle_memory_addressing(parser, ABS_BIAS_VALUE,expr);
	  break;
	}
  case HASHTAG:
	{
	  token_t temp_tok = tok; 
	  for(;temp_tok.type != MNEMONIC && temp_tok.type != TOK_EOF && temp_tok.type != LABEL;){
		if(temp_tok.type == COMMA){
		  EXIT_AND_FAIL("Unexpected Token", temp_tok);
		}
		temp_tok = pull_token(parser);
		if(temp_tok.type == COMMA){
		  EXIT_AND_FAIL("Unexpected Token", temp_tok);
		}
		append_expression(expr, temp_tok);
		temp_tok = peek_token(*parser);
	  }
	  return IMMEDIATE;
	  break;
	}
  case IDENT:
	{
	  append_expression(expr, tok);
	  if((tok.raw[0] == 'A' && tok.str_len == 1) || (tok.raw[0] == 'a' && tok.str_len == 1)){
		token_t temp_tok = peek_token(*parser);
		if (temp_tok.type != TOK_EOF && temp_tok.type != MNEMONIC && temp_tok.type != LABEL){
		  EXIT_AND_FAIL("Invaild Token after Acummlator Addressed instruction",temp_tok);
		}
		return ACCUMLATOR;
	  }
	  return handle_memory_addressing(parser, ABS_BIAS_VALUE,expr);
	}
  case OPEN_PAREN:
	{
	  return handle_indirect_addrmode(parser,expr);
	}
  case TOK_EOF: // if there is no operands assume it's just implicit
  case LABEL:
  case MNEMONIC:
	parser->current_pos--; //back the current postion back so the main loop can pull it off next since this is the next mnemonic
	break;
  default:
	EXIT_AND_FAIL("Unexpected Token",tok);
	break;
  }
  return IMPLICIT;
}


// first pass just constructs label addresses;
static inline void build_label_table(parser_t *parser)
{
  token_t token = parser->input.buf[parser->current_pos];
  for(;token.type != TOK_EOF;){
	if (token.type == LABEL){
	  label_t new_label = {0};
	  new_label.addr = parser->pc;
	  new_label.name = token.raw;
	  new_label.strlen = token.str_len;
	  append_label_slice(&parser->ltable, new_label);
	}else if(token.type == MNEMONIC){
	  parsed_mnemonic mnemonic = {0};
	  volatile int table_index = check_if_valid_instruction(token);
	  if(table_index >= 0){
		token = pull_token(parser);
		addrmode_t addressing_mode = addressing_mode = determine_addressing(parser,token,table_index,&mnemonic.expr);
		mnemonic.addr_mode = addressing_mode;
		mnemonic.is_dir = 0;
		mnemonic.table_indx = table_index;
		append_mnemonic_slice(&parser->mslice,mnemonic);
		parser->pc += addrmode_size[addressing_mode];
		mnemonic.start_tok = token;
	  }else{
		table_index = check_if_valid_directive(token);
		size_t size = determine_directive_size(parser,token,table_index,&mnemonic.expr);
		mnemonic.table_indx = table_index;
		mnemonic.addr_mode = size; // this is the total bytes to fill;
		parser->pc += size;
		mnemonic.is_dir = 1;
		mnemonic.start_tok = token;
		append_mnemonic_slice(&parser->mslice,mnemonic);
	  }
	}else{
	  EXIT_AND_FAIL("Unexpected Token", token);
	}
	token = pull_token(parser);
  }
}
void handle_dir(parser_t *parser,parsed_mnemonic mnem, int val){
  switch(mnem.table_indx){
  case  BYTE_INDEX:
	{
	  if(val > 255){
		EXIT_AND_FAIL("Expression value too large for byte", mnem.start_tok);
	  }
	  byte bval = (byte)val;
	  append_byte_slice(parser,&bval,1);
	  break;
	}
  case ORG_INDEX:
	{
	  parser->offset = val;
	  break;
	}
  case WORD_INDEX:
	{
	  if(val > 65535){
		EXIT_AND_FAIL("Expression value too large for word", mnem.start_tok);
	  }
	  u16 wval = (u16)val;
	  append_byte_slice(parser,(byte *)&wval,2);
	  break;
	}
  case FILL_INDEX:
	{
	  byte bval = (u16)val;
	  for(int i = 0; i < mnem.addr_mode;i++){
		append_byte_slice(parser, &bval, 1);
	  }
	  break;
	}
  }
}
void parse_and_output(parser_t *parser){
  for(int i = 0; i < parser->mslice.len;i++){
	parsed_mnemonic mnemonic = parser->mslice.buf[i];
    if(mnemonic.is_dir){
	  int val = pratt_parse(parser, mnemonic.expr, 0);
	  handle_dir(parser, mnemonic, val);
	}else{
	  byte byte_code_buf[3];
	  byte byte_code_len = addrmode_size[mnemonic.addr_mode];
	  if(mnemonic.addr_mode == IMPLICIT || mnemonic.addr_mode == ACCUMLATOR){
		byte_code_buf[0] = ins_table[mnemonic.table_indx].op_codes[mnemonic.addr_mode];
		append_byte_slice(parser, byte_code_buf, byte_code_len);
		continue;
	  }
	  int val = pratt_parse(parser,mnemonic.expr,0);
	  if(byte_code_len == 2){
		if(val > 0xFF){
		  EXIT_AND_FAIL("Expression value too large for byte", mnemonic.start_tok);
		}
		byte bval = (byte)val;
		byte_code_buf[0] = ins_table[mnemonic.table_indx].op_codes[mnemonic.addr_mode];
		byte_code_buf[1] = bval;
		append_byte_slice(parser, byte_code_buf, byte_code_len);
	  }else if(byte_code_len == 3){
		if(val > 0xFFFF){
		  EXIT_AND_FAIL("Expression value too large for word", mnemonic.start_tok);
		}
		u16 wval = (u16)val;
		byte_code_buf[0] = ins_table[mnemonic.table_indx].op_codes[mnemonic.addr_mode];
		byte_code_buf[1] = ((byte *)&wval)[0];
		byte_code_buf[2] = ((byte *)&wval)[1];
		append_byte_slice(parser,byte_code_buf,byte_code_len);
	  }
	}
  }
}

void parse_tokens(parser_t *parser)
{
  build_label_table(parser);
  parser->current_pos = 0;
  parser->pc = 0;
  parse_and_output(parser);
}
