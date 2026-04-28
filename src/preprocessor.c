#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "include/typedefs.h"
#include "include/common.h"
#include "include/io.h"
typedef enum{
  MNEMONIC = 0,
  LABEL,
  IDENT,
  DEC_NUMBER,
  HEX_NUMBER,
  QOUTE,
  OPEN_PAREN,
  CLOSED_PAREN,
  COMMA,
  PREPOC_INVOKE,
  NEW_LINE,
  TOK_PERCENT,
  UNUSED_CHAR,
  TOK_EOF
}toktype_t;

enum dt_index{
  INCLUDE_IND = 0,
  DEFINE_IND,
  DEFMAC_IND,
  ENDMAC_IND,
  COMMENT,
  NOT_DIR,
  __dt_index_end
};
									
static char directive_table[][10] =
  {
	"include",
	"define",
	"defmac",
	"endmac"
  };


typedef struct
{
  char *raw;
  int str_len;
  toktype_t type;
  int value; //used for numbers && directive types
  int col;
  int row;
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

typedef struct
{
  char *buf;
  size_t len;
  size_t cap;
}char_slice;
static inline void append_char_slice(char_slice *slice,char *input,int len){
  for(int i = 0; i < len;i++){
	if(slice->len >= slice->cap){
	  slice->buf = realloc(slice->buf,(slice->cap + 1) * 2);
	  slice->cap = (slice->cap + 1) * 2;
	}
	slice->buf[slice->len] = input[i];
	slice->len++;
  }
}
typedef struct{
  char *name;
  size_t nlen;
  token_t token;
}define_t;

typedef struct{
  define_t *buf;
  size_t len;
  size_t cap;
}define_slice;

static int append_define_slice(define_slice *slice,define_t define)
{
  if (slice->len == slice->cap){
	void *tmp = realloc(slice->buf,(sizeof(define_t) * ((slice->cap + 1) * 2)));
	if(!tmp)
	  return -1;
    slice->buf = tmp;
	slice->cap = (slice->cap + 1) * 2;
  }
  slice->buf[slice->len] = define;
  slice->len++;
  return 0;
}

typedef struct{
  token_slice toks;
  char_slice output;
  define_slice d_table;
  char *current_file;
  char *input;
  size_t len;
  size_t current_line;
  size_t current_col;
  size_t current_pos;
}preproc_t;

static inline char peek_char(preproc_t pproc)
{
  if(pproc.current_pos + 1 == pproc.len)
	return 0;
  return (pproc.input[pproc.current_pos + 1]);
}
static inline char prev_char(preproc_t pproc)
{
  if(!pproc.current_pos)
	return 0;
  return (pproc.input[pproc.current_pos - 1]);
}
static inline char pull_char(preproc_t *pproc)
{
  if(pproc->current_pos + 1 == pproc->len)
	return 0;
  pproc->current_pos++;
  pproc->current_col++;
  return pproc->input[pproc->current_pos];
}
static inline void pull_str(preproc_t *pproc,token_t * tok)
{
  char ch = peek_char(*pproc);
  char *str = &pproc->input[pproc->current_pos];
  tok->str_len++;
  while(isalnum(ch) || ch == '_'){
	ch = pull_char(pproc);
	tok->str_len++;
	ch = peek_char(*pproc);
  }
  tok->raw = str;
}
static inline int check_if_identifer(preproc_t pproc)
{
  
  for(int i = (pproc.current_pos - 1);i >= 0;i--){
	char ch = pproc.input[i];
	if(ch == ' ')
	  continue;
	if(isalpha(ch) || ispunct(ch))
	  return 1;
	if(ch == '\n' || '\t')
	  break;
  }
  return 0;
}

static inline token_t lex_symbol(preproc_t *pproc)
{
  token_t result_token = {0};
  result_token.col = pproc->current_col;
  result_token.row = pproc->current_line;
  char last_char = prev_char(*pproc);
  if(last_char == ' ' || last_char == '\t' || isgraph(last_char)){
	if(check_if_identifer(*pproc)){
	  pull_str(pproc, &result_token);
	  result_token.type = IDENT;
	}
	else{
	  pull_str(pproc, &result_token);
	  result_token.type = MNEMONIC;
	}
  }
  else{
	  pull_str(pproc, &result_token);
	  result_token.type = LABEL;
  }
  return result_token;
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

static inline token_t parse_hex(preproc_t *pproc)
{
  token_t tok = {0};
  tok.col = pproc->current_col;
  tok.row = pproc->current_line;
  tok.str_len = 1; //include the '$'
  char hex_value[12];
  int value_i = 0;
  for(;;){
	char ch = peek_char(*pproc);
	if(!check_if_valid_hex(ch))
	  break;
	pull_char(pproc); //pull it off the pproc;
	hex_value[value_i] = ch;
	value_i++;
	if (value_i > 4){
	  EXIT_AND_FAIL("HEX NUMBER TOO LARGE",tok);
	}
  }
  char *endptr;
  hex_value[value_i + 1] = '\0';
  tok.value = strtoul(hex_value, &endptr, 16);
  tok.raw = &pproc->input[pproc->current_pos - value_i];
  tok.type = HEX_NUMBER;
  tok.str_len += value_i;
  return tok;
}

static inline token_t lex_dec(preproc_t *pproc)
{
  token_t tok = {0};
  tok.col = pproc->current_col;
  tok.row = pproc->current_line;
  tok.raw = &pproc->input[pproc->current_pos];
  char ch = pproc->input[pproc->current_pos];
  char number_buf[6]; //max str length for 16 bit number;
  int value_i = 0;
  number_buf[value_i] = ch;
  value_i++;
  for(;;){
	ch = peek_char(*pproc);
	if(!isdigit(ch))
	  break;
	ch = pull_char(pproc);
	if(value_i >= 5){
	  EXIT_AND_FAIL("DECIMAL VALUE LARGER THAN 16 BITS",tok);
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

token_t handle_invoke_token(preproc_t *pproc){
  token_t ret = {0};
  ret.col = pproc->current_col;
  ret.row = pproc->current_line;
  if(peek_char(*pproc) == '#'){
	pull_char(pproc);
	ret.type = PREPOC_INVOKE;
	ret.value = COMMENT;
	ret.raw = &pproc->input[pproc->current_col];
	for(char ch  = peek_char(*pproc);ch != '\n';ch = peek_char(*pproc))
	  pull_char(pproc);
	return ret;
  }
  pull_char(pproc);
  pull_str(pproc, &ret);
  ret.type = PREPOC_INVOKE;
  ret.value = NOT_DIR;
  for(int i = 0; i < COMMENT; i++ ){
	if(ret.str_len != strlen(directive_table[i]))
	  continue;
	if(!strncasecmp(ret.raw, directive_table[i], ret.str_len)){
	  ret.value = i;
	  break;
	}
  }

  return ret;
}

void lex_preproc_tokens(preproc_t *pproc)
{
 
  char ch = pproc->input[pproc->current_pos];
  for(;;ch = pull_char(pproc)){
	if(isalpha(ch)){
	  token_t tok = lex_symbol(pproc);
	  append_slice(&pproc->toks, tok);
	  continue;
	}
	if(isdigit(ch)){
	  token_t tok = lex_dec(pproc);
	  append_slice(&pproc->toks, tok);
	  continue;
	}
	switch(ch){
	case '%':
	  {
		token_t tok = {
		  &pproc->input[pproc->current_pos],
		  1,
		  TOK_PERCENT,
		  0x2,
		  pproc->current_col,
		  pproc->current_line
		};
		append_slice(&pproc->toks, tok);
		break;
	  }
	case '"':
	  {
		token_t tok = {
		  &pproc->input[pproc->current_pos],
		  1,
		  QOUTE,
		  0x2,
		  pproc->current_col,
		  pproc->current_line
		};
		append_slice(&pproc->toks, tok);
		break;
	  }
	case '!':
	  {
		token_t tok = handle_invoke_token(pproc);
		append_slice(&pproc->toks, tok);
		break;
	  }
	case '(':
	  {
		token_t tok = {
		  &pproc->input[pproc->current_pos],
		  1,
		  OPEN_PAREN,
		  0x2,
		  pproc->current_col,
		  pproc->current_line
		};
		append_slice(&pproc->toks, tok);
		break;
	  }
	case ')':
	  {
		token_t tok = {
		  &pproc->input[pproc->current_pos],
		  1,
		  CLOSED_PAREN,
		  0x2,
		  pproc->current_col,
		  pproc->current_line
		};
		append_slice(&pproc->toks, tok);
		break;
	  }
	case '$':
	  {
		token_t tok = parse_hex(pproc);
		append_slice(&pproc->toks,tok);
		break;
	  }
	case ',':
	  {
		token_t tok = {
		  &pproc->input[pproc->current_pos],
		  1,
 		  COMMA,
		  0x0,
		  pproc->current_col,
		  pproc->current_line
		};
		append_slice(&pproc->toks, tok);
		break;
	  }
	case '\n':
	  token_t tok = {
		 &pproc->input[pproc->current_pos],
		  1,
		  NEW_LINE,
		  0x0,
		  pproc->current_col,
		  pproc->current_line
		};
	  pproc->current_line++;
	  pproc->current_col = 0;
	  append_slice(&pproc->toks, tok);
	  break;
	case 0:
	  {
		token_t tok ={
		NULL,
		0,
 		TOK_EOF,
		-1,
		0,
		0
	  };
	  append_slice(&pproc->toks, tok);
	  return;
	  break;
	  }
	default:
	  {
		if(ch == ' ' || ch == '\t'){
		  break;
		}
		token_t tok = {
		  &pproc->input[pproc->current_pos],
		  1,
		  UNUSED_CHAR,
		  0x2,
		  pproc->current_col,
		  pproc->current_line
		};
		append_slice(&pproc->toks, tok);
		break;
	  }
	}
  }
}

static token_t pull_token(preproc_t *pproc)
{
  if(pproc->current_pos + 1 == pproc->toks.len)
	return (token_t){0x0,0,TOK_EOF,0x0,0,0};
  pproc->current_pos++;
  return pproc->toks.buf[pproc->current_pos];
}
static token_t peek_token(preproc_t pproc)
{
  if(pproc.current_pos + 1 == pproc.toks.len)
	return (token_t){0x0,0,TOK_EOF,0x0,0,0};
  return pproc.toks.buf[pproc.current_pos + 1];
}

static int check_if_define(preproc_t *pproc,token_t tok){
  int i;
  for(i = 0; i < pproc->d_table.len;i++){
	if(tok.str_len != pproc->d_table.buf[i].nlen)
	  continue;
	if(!strncmp(tok.raw,pproc->d_table.buf[i].name,tok.str_len)){
	  return i;
	}
  }
  return -1;
}
static void write_token(preproc_t *pproc,token_t tok)
{
  switch(tok.type){
  case IDENT:
	  {
		append_char_slice(&pproc->output, tok.raw, tok.str_len);
		append_char_slice(&pproc->output, " ",1);
		break;
	  }
  case LABEL:
	{
	  append_char_slice(&pproc->output, tok.raw, tok.str_len);
	  token_t new_line = pull_token(pproc);
	  append_char_slice(&pproc->output, new_line.raw,new_line.str_len);
	  break;
	}
  case MNEMONIC:
	  {
		append_char_slice(&pproc->output, "\t", 1);
		append_char_slice(&pproc->output, tok.raw, tok.str_len);
		append_char_slice(&pproc->output," ",1);
		break;
	  }
  case HEX_NUMBER:
	  {
		append_char_slice(&pproc->output, tok.raw, tok.str_len);
		break;
	  }
  case DEC_NUMBER:
  case COMMA:
  case NEW_LINE:
  case OPEN_PAREN:
  case CLOSED_PAREN:
  case UNUSED_CHAR:
	{
	  append_char_slice(&pproc->output, tok.raw, tok.str_len);
	  break;
	}
  case PREPOC_INVOKE:
	PANIC("INVAILD STATE");
  case EOF:
	PANIC("INVALD STATE");
  }
}
static void handle_invo(preproc_t *pproc,token_t tok)
{
  switch(tok.value){
  case COMMENT:
	
  case DEFINE_IND:
	{
	  define_t new_def ={0};
	  token_t name_tok = pull_token(pproc);
	  new_def.name = name_tok.raw;
	  new_def.nlen = name_tok.str_len;
	  new_def.token = pull_token(pproc);
	  append_define_slice(&pproc->d_table, new_def);
	  break;
	}
  case NOT_DIR:
	{
	  int table_index = check_if_define(pproc, tok);
	  if(table_index != -1){
		token_t define_token = pproc->d_table.buf[table_index].token;
		write_token(pproc, define_token);
	  }else{
		EXIT_AND_FAIL("Unknown define or macro", tok);
	  }
	  break;
	}
	default:
	  	PANIC("unreachable state");
  }
  
}

static void handle_tokens(preproc_t *pproc){
  for(token_t tok = pproc->toks.buf[pproc->current_col]; tok.type != EOF;tok = pull_token(pproc)){
	switch(tok.type){
	case PREPOC_INVOKE:
	  {
		handle_invo(pproc, tok);
		break;
	  }
	case TOK_EOF:
	  return;
	default:
	  write_token(pproc, tok);
	}
  }
}
void preprocess(char **buf,size_t *size,char *filename)
{
  preproc_t pproc = {0};
  pproc.input = *buf;
  pproc.len = *size;
  pproc.current_file = filename;
  lex_preproc_tokens(&pproc);
  pproc.current_pos = 0;
  handle_tokens(&pproc);
  free(*buf);
  *size = pproc.output.len;
  *buf = pproc.output.buf;
}
