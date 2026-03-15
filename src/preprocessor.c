#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "include/typedefs.h"
#include "include/common.h"
#define TABLE_LEN 2
enum dt_index{
  INCLUDE_IND = 0,
  DEFINE_IND
};
static char directive_table[][10] =
  {
	"include",
	"define"
  };

/* typedef struct { */
/*   char *start; */
/*   size_t size; */
/* }macro_t; */

/* typedef struct{ */
/*   macro_t *buf; */
/*   size_t len; */
/*   size_t cap; */
/* }macro_slice; */
typedef struct{
  char *name;
  size_t nlen;
  char *contents;
  size_t clen;
}define_t;

typedef struct{
  define_t *buf;
  size_t len;
  size_t cap;
}define_slice;

static int append_define_slice(define_slice *slice,define_t define)
{
  if (slice->len == slice->cap){
	void *tmp = realloc(slice->buf,(sizeof(define_t) * (slice->cap + 25)));
	if(!tmp)
	  return -1;
	slice->buf = tmp;
	slice->cap += 25;
  }
  slice->buf[slice->len] = define;
  slice->len++;
  return 0;
}

typedef struct{
  char *start;
  size_t size;
}chunk_t;


typedef struct{
  char *buf;
  size_t cap;
  size_t len;
}charslice;
static int append_char_slice(charslice *slice,char *input,size_t isize)
{
  if ((slice->len + isize) >= slice->cap){
	slice->cap += isize;
	void *tmp = realloc(slice->buf,(sizeof(char) * (slice->cap * 2)));
	if(!tmp)
	  return -1;
	slice->buf = tmp;
  }
  for(int i = 0; i < isize;i++){
	slice->buf[slice->len + i] = input[i];
  }
  slice->len += isize;
  return 0;
}
typedef struct{
  char *input;
  size_t input_len;
  charslice output;
  define_slice define_tabe;
  chunk_t current_chunk;
  size_t current_pos;
}pprocessor_t;

static inline char pull_token(pprocessor_t *pproc)
{
  char ret;
  if(pproc->current_pos < pproc->input_len){
	ret = pproc->input[pproc->current_pos];
	pproc->current_pos++;
  }else{
	ret = 0;
  }
  return ret;
}
static inline char peek_token(pprocessor_t *pproc)
{
  char ret;
  if(pproc->current_pos < pproc->input_len){
	ret = pproc->input[pproc->current_pos];
  }else{
	ret = 0;
  }
  return ret;
}
// this should be a macro honestly
static inline void write_current_chunk(pprocessor_t *pproc){
  append_char_slice(&pproc->output, pproc->current_chunk.start, pproc->current_chunk.size);
}

int check_if_dir(char *buf,int size){
  int i;
  for(i = 0; i < TABLE_LEN;i++){
	if(!strncmp(buf,directive_table[i],size)){
	  return i;
	}
  }
  return -1;
}
int check_if_define(pprocessor_t *pproc,charslice str){
  int i;
  for(i = 0; i < pproc->define_tabe.len;i++){
	if(!strncmp(str.buf,pproc->define_tabe.buf[i].name,str.len)){
	  return i;
	}
  }
  return -1;
}

charslice pull_space_delim_str(pprocessor_t *pproc)
{
  charslice ret = {0};
  ret.buf = &pproc->input[pproc->current_pos];
  ret.cap = 0;
  for(char ch  = pull_token(pproc);!iscntrl(ch) && !isspace(ch); ch = pull_token(pproc)){
	ret.len++;
  }
  return ret;
}
void build_define(pprocessor_t *pproc)
{
  define_t define;
  charslice name = pull_space_delim_str(pproc);
  define.name = name.buf;
  define.nlen = name.len;
  charslice contents = pull_space_delim_str(pproc);
  define.contents = contents.buf;
  define.clen = contents.len;
  append_define_slice(&pproc->define_tabe, define);
}

void handle_invocation(pprocessor_t *pproc)
{
  charslice call_name = pull_space_delim_str(pproc); //this is a view do not append;
  int table_index = check_if_dir(call_name.buf, call_name.len);
  if(table_index != -1){
	switch(table_index){
	case INCLUDE_IND:
	  PANIC("TODO -- INCLUDE");
	  break;
	case DEFINE_IND:
	  build_define(pproc);
	  break;
	default:
	  PANIC("UNKNOWN DIRECTIVE");
	}
  }else{
	table_index = check_if_define(pproc, call_name);
	if(table_index != -1){
	  append_char_slice(&pproc->output, pproc->define_tabe.buf[table_index].contents, pproc->define_tabe.buf[table_index].clen);
	}
  }
  pproc->current_chunk.start = &pproc->input[pproc->current_pos];
  pproc->current_chunk.size = 0;
}

void map_and_build_tokens(pprocessor_t *pproc)
{
  pproc->current_chunk.start =  pproc->input;
  char ch = 1;
  for(;ch != 0;){
	ch = pull_token(pproc);
	if(ch ==  '!'){
	  write_current_chunk(pproc);
	  handle_invocation(pproc);
	}else
	  pproc->current_chunk.size++;
  }
  write_current_chunk(pproc);
}
void preprocess(char **buf,size_t *size)
{
  pprocessor_t pproc = {0};
  pproc.input = *buf;
  pproc.input_len = *size;
  map_and_build_tokens(&pproc);
  free(*buf);
  *buf = pproc.output.buf;
  *size = pproc.output.len;
}
