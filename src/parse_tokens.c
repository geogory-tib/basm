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
static directive_t dir_table[4] = {{"byte",VAR_ARGS_DIRECTIVE},{"fill",2},{"org",1},{"word",VAR_ARGS_DIRECTIVE}};

enum Directive_table_Index{
  BYTE_INDEX = 0,
  FILL_INDEX,
  ORG_INDEX,
  WORD_INDEX
};

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
  0,
  0,
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
  size_t len;
}byte_slice;

typedef struct
{
  token_slice input;
  label_slice ltable;
  byte_slice output;
  size_t current_pos;
  u32 pc;
  u32 offset;
}parser_t;

parser_t init_parser(token_slice input)
{
  parser_t ret = {0};
  ret.current_pos = 0;
  ret.input = input;
  ret.output.buf = calloc(1000,sizeof(byte));
  ret.output.cap = 1000;
  ret.output.len = 0;
  ret.ltable.buf = calloc(10,sizeof(label_t));
  ret.ltable.cap = 10;
  ret.ltable.len = 0;
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
size_t determine_directive_size(parser_t *parser,token_t tok,int table_index)
{
  switch(table_index){
  case BYTE_INDEX:
		PANIC("unimplemented");
  case WORD_INDEX:
		PANIC("unimplemented");
  case FILL_INDEX:
	PANIC("unimplemented");
  case ORG_INDEX:
	return 0;
  }
}
//handles both absoulute and zeropage addressing
// abs_bias will be 4 when return absoulte addressing modes check insturctions.h to see numeric values to understand
static inline addrmode_t handle_memory_addressing(parser_t *parser,int abs_bias) 
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
	tok = peek_token(*parser);
  }
  return ZEROPAGE + abs_bias;
}

static inline addrmode_t handle_indirect_addrmode(parser_t *parser)
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
addrmode_t determine_addressing(parser_t *parser,token_t tok,int table_index)
{
  if(table_index >= BRANCH_START && table_index <= BRANCH_END){
	token_t temp_tok = pull_token(parser);
	for(;;){
	  temp_tok = peek_token(*parser);
	  if(temp_tok.type != MNEMONIC && temp_tok.type != LABEL && temp_tok.type != TOK_EOF){
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
	  if(tok.str_len == 2){
		return handle_memory_addressing(parser, ABS_BIAS_VALUE);
	  }
	  return handle_memory_addressing(parser, ABS_BIAS_VALUE);
	  break;
	  
	}
  case DEC_NUMBER:
	{
	  if(tok.value <= 255){
		return handle_memory_addressing(parser,0);
	  }
	  return handle_memory_addressing(parser, ABS_BIAS_VALUE);
	  break;
	}
  case HASHTAG:
	{
	  token_t temp_tok = {0,0,COMMA,0}; // set to comma so it doesn't exit the for loop.
	  for(;temp_tok.type != MNEMONIC && temp_tok.type != TOK_EOF && temp_tok.type != LABEL;){
		temp_tok = pull_token(parser);
		switch(temp_tok.type){
		case COMMA:
		  EXIT_AND_FAIL("invaild addressing mode",temp_tok);
		default:
		  break; 
		}
		temp_tok = peek_token(*parser);
	  }
	  return IMMEDIATE;
	  break;
	}
  case IDENT:
	{
	  if((tok.raw[0] == 'A' && tok.str_len == 1) || (tok.raw[0] == 'a' && tok.str_len == 1)){
		token_t temp_tok = peek_token(*parser);
		if (temp_tok.type != TOK_EOF && temp_tok.type != MNEMONIC && temp_tok.type != LABEL){
		  EXIT_AND_FAIL("Invaild Token after Acummlator Addressed instruction",temp_tok);
		}
		return ACCUMLATOR;
	  }
	  return handle_memory_addressing(parser, ABS_BIAS_VALUE);
	}
  case OPEN_PAREN:
	{
	  return handle_indirect_addrmode(parser);
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
	  int table_index = check_if_valid_instruction(token);
	  if(table_index >= 0){
		token = pull_token(parser);
		addrmode_t addressing_mode = addressing_mode = determine_addressing(parser,token,table_index);
		parser->pc += addrmode_size[addressing_mode];
	  }else if(table_index >= 0){
		table_index = check_if_valid_directive(token);
		parser->pc += determine_directive_size(parser,token,table_index);
	  }else{
		EXIT_AND_FAIL("Invaild mnemonic",token);
	  }
	}else{
	  EXIT_AND_FAIL("Encountered Unexpected Token",token);
	}
	token = pull_token(parser);
  }
}

void parse_tokens(parser_t *parser)
{
  build_label_table(parser);
}
