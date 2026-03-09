#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/common.h"
#include "include/lexer.h"
#include "include/typedefs.h"
#include "include/parser.h"
/*
  This is a really basic pratt parser
  ---
  TODO - implement uniary operators

 */
static token_t current_token = {0};

static int precedence_table[TOK_AMBSAN ] = {
  -2,
  -2,
  0,
  0,
  0,
  -2,
  -2,
  1,
  1,
  2,
  2,
  -2,
  -2,
  0,
  3,
  3,
  0
};
static inline int get_precedence(token_t tok){
  return precedence_table[tok.type];
}
static inline void pull_token(parser_t *parser,expr_t expr)
{
  if(parser->current_pos + 1 > expr.len){
	current_token = (token_t){0x0,0,TOK_EOF,0x0,0,0};
	return;
  }
 current_token = expr.buf[parser->current_pos];
 parser->current_pos++;
}

static inline token_t peek_token(parser_t *parser,expr_t expr)
{
  if(parser->current_pos >= expr.len)
	return (token_t){0x0,0,TOK_EOF,0x0,0,0};
  return expr.buf[parser->current_pos];
}
static inline int extract_value(token_t tok,parser_t *parser){
  switch(tok.type){
  case HEX_NUMBER:
  case DEC_NUMBER:
	{
	  return tok.value;
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
		return (parser->ltable.buf[i].addr + parser->offset);
		break;
	  }
  case TOK_AMBSAN:
	return (parser->pc + parser->offset);
  default:
	break;
  }
  EXIT_AND_FAIL("Unexpected Token", tok);
  return -1;
}
int apply_op(token_t operation,int left,int right){
  int val = 0;
  switch(operation.type){
  case MULT:
	val = left * right;
	break;
  case DIV:
	val = left / right;
	break;
  case MINUS:
	val = left - right;
	break;
  case PLUS:
	val = left + right;
	break;
  default:
	EXIT_AND_FAIL("Unexpected Token",operation);
	break;
  }
  return val;
}
/* static inline token_t prev_token(expr_t parser) */
/* { */
/*   if(current_pos - 1 < 0) */
/* 	return (token_t){0x0,0,TOK_EOF,0x0,0,0}; */
/*   return parser.buf[current_pos - 1]; */
/* } */
int pratt_parse(parser_t *parser,expr_t expr,int weight){
  int left = 0;
  int right = 0;
  token_t op;
  pull_token(parser, expr);
  left = extract_value(current_token, parser);
  token_t next_tok = peek_token(parser, expr);
  while(get_precedence(peek_token(parser, expr)) > weight){
	pull_token(parser,expr);
	op = current_token;
	right = pratt_parse(parser, expr, get_precedence(op));
	left = apply_op(op, left, right);
	
  }
  if(peek_token(parser, expr).type == TOK_EOF && weight == 0)
	parser->current_pos = 0;
  return left;
}




