#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/common.h"
#include "include/lexer.h"
#include "include/typedefs.h"
#include "include/parser.h"
static int accumulator = 0;
static size_t current_pos = 0; 
static token_t current_token = {0};
static inline token_t pull_token(expr_t parser)
{
if(current_pos + 1 >= parser.len)
	return (token_t){0x0,0,TOK_EOF,0x0,0,0};
 current_pos++;
 return parser.buf[current_pos];
}

static inline token_t peek_token(expr_t parser)
{
  if(current_pos + 1 >= parser.len)
	return (token_t){0x0,0,TOK_EOF,0x0,0,0};
  return parser.buf[current_pos + 1];
}
/* static inline token_t prev_token(expr_t parser) */
/* { */
/*   if(current_pos - 1 < 0) */
/* 	return (token_t){0x0,0,TOK_EOF,0x0,0,0}; */
/*   return parser.buf[current_pos - 1]; */
/* } */
int pratt_parse(parser_t *parser,expr_t expr,int local){
  int local_accum = local;
  if(current_pos == 0){
	current_token = expr.buf[current_pos];
  }
  for(;current_pos < expr.len;){
	switch(current_token.type){
	case PLUS:
	  {
		break;
	  }
	case MINUS:
	  {
		break;
	  }
	case MULT:
	  {
		break;
	  }
	case DIV:
	  {
		break;
	  }
	case TOK_GTHEN:
	  {
		break;
	  }
	case TOK_LTHEN:
	  {
		break;
	  }
	case DEC_NUMBER:
	case HEX_NUMBER:
	  {
		accumulator = current_token.value;
		break;
	  }
	case IDENT:
	  {
		int i;
		for(i = 0;i < parser->ltable.len;i++){
		  if(!strncasecmp(current_token.raw, parser->ltable.buf[i].name, current_token.str_len)){
			goto pass;
		  }
		}
		EXIT_AND_FAIL("Undeclared Label", current_token);
	  pass:
		accumulator = (parser->ltable.buf[i].addr + parser->offset);
		break;
	  }
	case TOK_EOF:
	  goto exit;
	default:
	  {
		break;
	  }
	}
	current_token = pull_token(expr);
  }
 exit:
  current_pos = 0;
  return accumulator;
}


