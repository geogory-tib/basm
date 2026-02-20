#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "include/typedefs.h"
#include "include/instructions.h"
#include "include/tokens.h"
#include "include/common.h"

typedef enum{
  MNEMONIC = 0,
  LABEL,
  IDENT,
  DEC_NUMBER,
  HEX_NUMBER,
  HASHTAG,
  COMMA,
  PLUS,
  MINUS,
  MULT,
  DIV,
  OPEN_PAREN,
  CLOSED_PAREN,
  TOK_EOF
}toktype_t;

typedef struct
{
  size_t current_pos;
  size_t len;
  char *input;
  char current_ch;
}lexer_t;

typedef struct
{
  char *raw;
  int str_len;
  toktype_t type;
  int value; //used for number constants in code
}token_t;

typedef struct
{
  token_t *buf;
  size_t len;
  size_t cap; 
}token_slice;

static int append_slice(token_slice *slice,token_t tok)
{
  if (slice->len == slice->cap){
	void *tmp = realloc(slice->buf,(sizeof(token_t) * (slice->cap + 25)));
	if(!tmp)
	  return -1;
	slice->buf = tmp;
	slice->cap += 25;
  }
  slice->buf[slice->len] = tok;
  slice->len++;
  return 0;
}

lexer_t init_lexer(char *input,size_t len)
{
  lexer_t ret;
  ret.current_pos = 0;
  ret.len = len;
  ret.input = input;
  ret.current_ch = input[0];
  return ret;
}

static inline char peek_char(lexer_t lexer)
{
  if(lexer.current_pos + 1 == lexer.len)
	return 0;
  return (lexer.input[lexer.current_pos + 1]);
}
static inline char prev_char(lexer_t lexer)
{
  if(!lexer.current_pos)
	return 0;
  return (lexer.input[lexer.current_pos - 1]);
}
static inline char pull_char(lexer_t *lexer)
{
  if(lexer->current_pos + 1 == lexer->len)
	return 0;
  lexer->current_pos++;
  lexer->current_ch = lexer->input[lexer->current_pos];
  return lexer->input[lexer->current_pos];
}

static inline int check_if_identifer(lexer_t lexer)
{
  
  for(int i = (lexer.current_pos - 1);i >= 0;i--){
	char ch = lexer.input[i];
	if(ch == ' ')
	  continue;
	if(isalpha(ch) || ispunct(ch))
	  return 1;
	if(ch == '\n' || '\t')
	  break;
  }
  return 0;
}

static inline void pull_str(lexer_t *lexer,token_t * tok)
{
  char ch = peek_char(*lexer);
  char *str = &lexer->input[lexer->current_pos];
  tok->str_len++;
  while(isalpha(ch) || ch == '_'){
	ch = pull_char(lexer);
	tok->str_len++;
	ch = peek_char(*lexer);
  }
  tok->raw = str;
}

int check_if_valid_hex(char ch)
{
  if(isalpha(ch)){
	if(islower(ch))
	  ch ^= 32;
	if(ch > 'F' || ch < 'A')
	  return 0;
	return 1;
  }
  if(isdigit(ch))
	return 1;
  return 0;
}

static inline token_t lex_symbol(lexer_t *lexer)
{
  token_t result_token = {0};
  char last_char = prev_char(*lexer);
  if(last_char == ' ' || last_char == '\t' || isgraph(last_char)){
	if(check_if_identifer(*lexer)){
	  pull_str(lexer, &result_token);
	  result_token.type = IDENT;
	}
	else{
	  pull_str(lexer, &result_token);
	  result_token.type = MNEMONIC;
	}
  }
  else{
	  pull_str(lexer, &result_token);
	  result_token.type = LABEL;
  }
  return result_token;
}
static inline token_t parse_hex(lexer_t *lexer)
{
  token_t tok = {0};
  char hex_value[5];
  int value_i = 0;
  for(;;){
	char ch = peek_char(*lexer);
	if(!check_if_valid_hex(ch))
	  break;
	pull_char(lexer); //pull it off the lexer;
	hex_value[value_i] = ch;
	value_i++;
	if (value_i >= 4){
	  EXIT_AND_FAIL("HEX NUMBER TOO LARGE");
	}
  }
  char *endptr;
  hex_value[value_i + 1] = '\0';
  tok.value = strtoul(hex_value, &endptr, 16);
  tok.raw = &lexer->input[lexer->current_pos - value_i];
  tok.type = HEX_NUMBER;
  tok.str_len = value_i;
  return tok;
}
static inline token_t lex_dec(lexer_t *lexer)
{
  token_t tok = {0};
  tok.raw = &lexer->input[lexer->current_pos];
  char ch = lexer->input[lexer->current_pos];
  char number_buf[6]; //max str length for 16 bit number;
  int value_i = 0;
  number_buf[value_i] = ch;
  value_i++;
  for(;;){
	ch = peek_char(*lexer);
	if(!isdigit(ch))
	  break;
	ch = pull_char(lexer);
	if(value_i >= 5){
	  EXIT_AND_FAIL("DECIMAL VALUE LARGER THAN 16 BITS");
	}
	number_buf[value_i] = ch;
	value_i++;
  }
  char *endptr;
  tok.value = strtol(number_buf,&endptr, 10);
  tok.type = DEC_NUMBER;
  tok.str_len = value_i;
  return tok;
}
token_slice lex_tokens(lexer_t *lexer)
{
  token_slice tokbuf;
  tokbuf.buf = calloc(100,sizeof(token_t));
  tokbuf.cap = 100;
  tokbuf.len = 0;
  char ch = lexer->input[lexer->current_pos];
  for(;;){
	if(isalpha(ch)){
	  token_t tok = lex_symbol(lexer);
	  append_slice(&tokbuf, tok);
	}
	if(isdigit(ch)){
	  token_t tok = lex_dec(lexer);
	  append_slice(&tokbuf, tok);
	}
	switch(ch){
	case '(':
	  {
		token_t tok = {
		  &lexer->input[lexer->current_pos],
		  1,
		  OPEN_PAREN,
		  0x2
		};
		append_slice(&tokbuf, tok);
		break;
	  }
	case ')':
	  {
		token_t tok = {
		  &lexer->input[lexer->current_pos],
		  1,
		  CLOSED_PAREN,
		  0x2
		};
		append_slice(&tokbuf, tok);
		break;
	  }
	case '#':
	  {
		token_t tok = {
		  &lexer->input[lexer->current_pos],
		  1,
		  HASHTAG,
		  0x0
		};
		append_slice(&tokbuf, tok);
		break;
	  }
	case '$':
	  {
		token_t tok = parse_hex(lexer);
		append_slice(&tokbuf,tok);
		break;
	  }
	case '*':
	  {
		token_t tok = {
		  &lexer->input[lexer->current_pos],
		  1,
		  MULT,
		  0x1
		};
		append_slice(&tokbuf, tok);
		break;
	  }
	case '/':
	  {
		token_t tok = {
		  &lexer->input[lexer->current_pos],
		  1,
		  DIV,
		  0x1
		};
		append_slice(&tokbuf, tok);
		break;
	  }
	case '+':
	  token_t tok = {
		  &lexer->input[lexer->current_pos],
		  1,
		  PLUS,
		  0x0
		};
		append_slice(&tokbuf, tok);
		break;
	case '-':
	  {
		token_t tok = {
		  &lexer->input[lexer->current_pos],
		  1,
		  MINUS,
		  0x0
		};
		append_slice(&tokbuf, tok);
		break;
	  }
	case ',':
	  {
		token_t tok = {
		  &lexer->input[lexer->current_pos],
		  1,
		  COMMA,
		  0x0
		};
		append_slice(&tokbuf, tok);
		break;
	  }
	case 0:
	  {
		token_t tok ={
		NULL,
		0,
 		TOK_EOF,
		0x0
	  };
	  append_slice(&tokbuf, tok);
	  goto exit;
	  break;
	  }
	}
	ch = pull_char(lexer);
  }
 exit:
  return tokbuf;
}

