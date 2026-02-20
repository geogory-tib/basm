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
directive_t dir_table[4] = {{"byte",VAR_ARGS_DIRECTIVE},{"fill",2},{"org",1},{"word",VAR_ARGS_DIRECTIVE}};
typedef struct
{
  char *name;
  byte op_codes[13];
  addrmode_t addr_mode;
}instruction_t;
// this table is just to look up valid opcodes and valid addressing modes
instruction_t ins_table[56] =
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
	return (token_t){0x0,0,TOK_EOF,0x0};
  parser->current_pos++;
  return parser->input.buf[parser->current_pos];
}
token_t peek_token(parser_t parser)
{
  if(parser.current_pos + 1 == parser.input.len)
		return (token_t){0x0,0,TOK_EOF,0x0};
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
  parser->current_pos = -1;
  PANIC("Unimplemented");
  return -1;
}
static inline addrmode_t handle_zeropage_addressing(parser_t *parser,token_t tok)
{
  	token_t temp_tok;
		for(;temp_tok.type != MNEMONIC && temp_tok.type != LABEL;){
		  temp_tok = pull_token(parser);
		  if(temp_tok.type == TOK_EOF){
			return ZEROPAGE;
		  }
		  else if(temp_tok.type == COMMA){
			temp_tok = pull_token(parser);
			if(temp_tok.type == IDENT){
			  switch(tok.raw[0]){
			  case 'Y':
				return ZPY;
				break;
			  case 'y':
				return ZPY;
				break;
			  case 'X':
				return ZPX;
				break;
			  case 'x':
				return ZPX;
				break;
			  default:
				EXIT_AND_FAIL("Unsupported Addressing Mode");
				break;
			  }
			}
			else {
			  switch(temp_tok.type){
			  case IDENT:
				EXIT_AND_FAIL("Unexepected Identifer: Expected comma before second Identifer");
				break;
			  case HASHTAG:
				EXIT_AND_FAIL("Invaild Addressing mode: Hash provided within expression for ZeroPage addressing mode");
				break;
			  default:
				break;
			  }
			}
		  }
		  temp_tok = peek_token(*parser);
		}
		return ZEROPAGE;
}
static inline addrmode_t handle_absoulute_addressing(parser_t *parser,token_t tok)
{
  token_t temp_tok = {0};
		for(;temp_tok.type != MNEMONIC && temp_tok.type != LABEL;){
		  temp_tok = pull_token(parser);
		  if(temp_tok.type == TOK_EOF){
			return ABSOLUTE;
		  }
		  else if(temp_tok.type == COMMA){
			temp_tok = pull_token(parser);
			if(temp_tok.type == IDENT){
			  switch(tok.raw[0]){
			  case 'Y':
				return ABSY;
				break;
			  case 'y':
				return ABSY;
				break;
			  case 'X':
				return ABSX;
				break;
			  case 'x':
				return ABSX;
				break;
			  default:
				EXIT_AND_FAIL("Unsupported Addressing Mode");
				break;
			  }
			}
			else {
			  switch(temp_tok.type){
			  case IDENT:
				EXIT_AND_FAIL("Unexepected Identifer: Expected comma before second Identifer");
				break;
			  case HASHTAG:
				EXIT_AND_FAIL("Invaild Addressing mode: Hash provided within expression for Absolute addressing mode");
				break;
			  default:
				break;
			  }
			}
		  }
		  temp_tok = peek_token(*parser);
		}
		return ABSOLUTE;
}
static inline addrmode_t handle_indirect_addrmode(parser_t *parser,token_t tok)
{
  token_t temp_tok = pull_token(parser);
  for(;;){
	switch(temp_tok.type){
	case MNEMONIC:
	  EXIT_AND_FAIL("Unexpeted mnemonic, expected closed paren");
	case LABEL:
	  EXIT_AND_FAIL("Unexpeted mnemonic, expected closed paren");
	case COMMA:
	  {
		temp_tok = pull_token(parser);
		if(temp_tok.type != IDENT){
		  EXIT_AND_FAIL("Invaild Addressing Mode: Expected Identifer 'X'");
		}
		switch(temp_tok.raw[0]){
		case 'X':
		  {
			temp_tok = pull_token(parser);
			if(temp_tok.type != CLOSED_PAREN){
			  EXIT_AND_FAIL("Invaild Addressing mode: Expected ')' after identifer 'X'");
			}
			temp_tok = peek_token(*parser);
			if(temp_tok.type != LABEL && temp_tok.type != MNEMONIC && temp_tok.type != TOK_EOF){
			  EXIT_AND_FAIL("Expected new mnemonic after end of expression");
			}
			return INDEXIND;
		  }
		case 'x':
		  {
			if(temp_tok.type != CLOSED_PAREN){
			  EXIT_AND_FAIL("Invaild Addressing mode: Expected ')' after identifer 'x'");
			}
			temp_tok = peek_token(*parser);
			if(temp_tok.type != LABEL || temp_tok.type != MNEMONIC || temp_tok.type != TOK_EOF){
			  EXIT_AND_FAIL("Expected new mnemonic after end of expression");
			}
			return INDEXIND;
		  }
		}
		break;
	  }
	case CLOSED_PAREN:
	  goto exit_loop;
	default:
	  break;
	}
	temp_tok = pull_token(parser);
  }
 exit_loop:
  temp_tok = peek_token(*parser);
  if(temp_tok.type ==  MNEMONIC || temp_tok.type == LABEL)
	return INDIRECT;
  else if(tok.type == COMMA){
	if(tok.type == IDENT && temp_tok.str_len == 1){
	  switch(tok.raw[0]){
	  case 'Y': //captial Y should fall through
	  case 'y':
		{
		  temp_tok = peek_token(*parser);
		  if(temp_tok.type != LABEL && temp_tok.type != MNEMONIC && temp_tok.type != TOK_EOF){
			EXIT_AND_FAIL("Expected Mnemonic, Label or EOF after 'y'");
		  }
		  return INDINDEX;
		  break; 
		}
	  default:
		EXIT_AND_FAIL("Invaild Addressing mode");
	  }
	}
	else{
	  EXIT_AND_FAIL("Expected Identifer after comma");
	}
  }
}
addrmode_t determine_addressing(parser_t *parser,token_t tok,int table_index)
{
  if(table_index >= BRANCH_START && table_index <= BRANCH_END){
	token_t temp_tok = pull_token(parser);
	for(;temp_tok.type != MNEMONIC && temp_tok.type != TOK_EOF && temp_tok.type != LABEL;)
	  temp_tok = pull_token(parser);
	return RELATIVE;
  }
  switch(tok.type){
  case HEX_NUMBER:
	{
	  if(tok.str_len == 2){
		return handle_zeropage_addressing(parser, tok);
	  }
	  return handle_absoulute_addressing(parser, tok);
	  break;
	  
	}
  case DEC_NUMBER:
	{
	  if(tok.value <= 255){
		return handle_zeropage_addressing(parser, tok);
	  }
	  return handle_absoulute_addressing(parser, tok);
	  break;
	}
  case HASHTAG:
	{
	  token_t temp_tok = pull_token(parser);
	  for(;temp_tok.type != MNEMONIC && temp_tok.type != TOK_EOF && temp_tok.type != LABEL;){
		switch(temp_tok.type){
		case COMMA:
		  EXIT_AND_FAIL("invaild addressing mode");
		default:
		  break; 
		}
		temp_tok = pull_token(parser);
	  }
	  break;
	}
  case IDENT:
	{
	  if((tok.raw[0] == 'A' && tok.str_len == 1) || (tok.raw[0] == 'a' && tok.str_len == 1)){
		token_t temp_tok = peek_token(*parser);
		if (temp_tok.type != TOK_EOF || temp_tok.type != MNEMONIC || temp_tok.type != LABEL){
		  EXIT_AND_FAIL("Invaild Token after Acummlator Addressed instruction");
		}
		return ACCUMLATOR;
	  }
	  return handle_absoulute_addressing(parser, tok);
	}
  case OPEN_PAREN:
	{
	  return handle_indirect_addrmode(parser,tok);
	}
  default:
	EXIT_AND_FAIL("Unexpected Token");
	break;
  }
  PANIC("This Part Of code Should Never be reached");
  return -1;
}

// first pass just constructs label addresses;
static inline void build_label_table(parser_t *parser)
{
  token_t token = parser->input.buf[parser->current_pos];
  for(;;){
	int table_index = check_if_valid_instruction(token);
	if(table_index >= 0){
	  token = pull_token(parser);
	  determine_addressing(parser,token,table_index);
	}else if(table_index >= 0){
	  table_index = check_if_valid_directive(token);
	  determine_directive_size(parser,token,table_index);
	}else{
	  EXIT_AND_FAIL("Invaild mnemonic");
	}
	token = pull_token(parser);
  }
}

void parse_tokens(parser_t *parser)
{
  build_label_table(parser);
}
