#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "include/typedefs.h"
#include "include/common.h"
#include "include/io.h"
#define TABLE_LEN 4
enum dt_index{
  INCLUDE_IND = 0,
  DEFINE_IND,
  DEFMAC_IND,
  ENDMAC_IND
};

  												
static char directive_table[][10] =
  {
	"include",
	"define",
	"defmac",
	"endmac"
  };


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
  charslice *buf;
  size_t cap;
  size_t len;
}charslice_slice;

static int append_charslice_slice(charslice_slice *slice,charslice str)
{
  if (slice->len == slice->cap){
	void *tmp = realloc(slice->buf,(sizeof(charslice) * ((slice->cap + 1) * 2)));
	if(!tmp)
	  return -1;
	slice->buf = tmp;
	slice->cap += 1;
	slice->cap *= 2;
  }
  slice->buf[slice->len] = str;
  slice->len++;
  return 0;
}


typedef struct{
  charslice body;
  charslice name;
  size_t arg_no;
}macro_t;
// because macros are a string view I am using the CAP as the current POS
static char pull_macro_char(macro_t *macro)
{
  char ret;
  if(macro->body.cap < macro->body.len){
	ret = macro->body.buf[macro->body.cap];
	macro->body.cap++;
  }else{
	ret = 0;
  }
  return ret;
}
static char peek_macro_char(macro_t *macro)
{
  char ret;
  if(macro->body.cap < macro->body.len){
	ret = macro->body.buf[macro->body.cap];
  }else{
	ret = 0;
  }
  return ret;
}

typedef struct{
  macro_t *buf;
  size_t cap;
  size_t len;
}macro_slice;

static int append_macro_slice(macro_slice *slice,macro_t macro)
{
  if (slice->len == slice->cap){
	void *tmp = realloc(slice->buf,(sizeof(macro_t) * (slice->cap + 25)));
	if(!tmp)
	  return -1;
	slice->buf = tmp;
	slice->cap += 25;
  }
  slice->buf[slice->len] = macro;
  slice->len++;
  return 0;
}

typedef struct{
  char *input;
  size_t input_len;
  char *file_name;
  charslice output;
  define_slice define_tabe;
  macro_slice macro_table;
  chunk_t current_chunk;
  size_t current_pos;
  size_t current_line;
  size_t current_col;
}pprocessor_t;

__attribute__((noreturn)) void pre_proc_failure(pprocessor_t *pproc,charslice fault,char *msg){
  printf("%s: '%.*s' @ %d:%d:%s\n",msg,fault.len,fault.buf,pproc->current_line + 1,pproc->current_col + 1,pproc->file_name);
  exit(EXIT_FAILURE);
}

static inline char pull_token(pprocessor_t *pproc)
{
  char ret;
  if(pproc->current_pos < pproc->input_len){
	ret = pproc->input[pproc->current_pos];
	pproc->current_pos++;
	pproc->current_col++;
	if(ret == '\n'){
	  pproc->current_col = 0;
	  pproc->current_line++;
	}
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

static int check_if_dir(char *buf,int size){
  int i;
  for(i = 0; i < TABLE_LEN;i++){
	if(size != strlen(directive_table[i]))
	  continue;
	if(!strncmp(buf,directive_table[i],size)){
	  return i;
	}
  }
  return -1;
}
static int check_if_define(pprocessor_t *pproc,charslice str){
  int i;
  for(i = 0; i < pproc->define_tabe.len;i++){
	if(str.len != pproc->define_tabe.buf[i].nlen)
	  continue;
	if(!strncmp(str.buf,pproc->define_tabe.buf[i].name,str.len)){
	  return i;
	}
  }
  return -1;
}

static int check_if_macro(pprocessor_t *pproc,charslice str){
  int i;
  for(i = 0; i < pproc->macro_table.len;i++){
	if(str.len != pproc->macro_table.buf[i].name.len)
	  continue;
	if(!strncmp(str.buf,pproc->macro_table.buf[i].name.buf,str.len)){
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
  for(char ch  = pull_token(pproc);!iscntrl(ch) && !isspace(ch) && ch != '('; ch = pull_token(pproc)){
	ret.len++;
  }
  return ret;
}
charslice macro_pull_space_delim_str(macro_t *macro)
{
  charslice ret = {0};
  ret.buf = &macro->body.buf[macro->body.cap];
  ret.cap = 0;
  for(char ch = pull_macro_char(macro);!iscntrl(ch) && !isspace(ch) && ch != '('; ch = pull_macro_char(macro)){
	ret.len++;
  }
  return ret;
}

charslice pull_macro_args(pprocessor_t *pproc)
{
  charslice ret = {0};
  ret.buf = &pproc->input[pproc->current_pos];
  ret.cap = 0;
  for(char ch  = pull_token(pproc);;ch = pull_token(pproc)){
	ret.len++;
	if(ch == ')')
	  break;
  }
  return ret;
}
charslice macro_pull_macro_args(macro_t *macro)
{
  charslice ret = {0};
  ret.buf = &macro->body.buf[macro->body.cap];
  ret.cap = 0;
  for(char ch  = pull_macro_char(macro);;ch = pull_macro_char(macro)){
	ret.len++;
	if(ch == ')')
	  break;
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

int decstr_to_int(charslice num){
  size_t ret;
  int accum = 0;
  num.cap = num.len;
  for(int i = 0; i < num.cap; i++){
	char num_ch = num.buf[i];
	int number = num_ch - 48;
	for(int place = (num.cap - 1) - i;i != 0; i--){
	  number *= 10;
	  num.cap--;
	}
	accum += number;
  }
  return accum;
}
void build_macro(pprocessor_t *pproc){
  macro_t new_macro = {0};
  new_macro.name = pull_space_delim_str(pproc);
  charslice number_of_args = pull_space_delim_str(pproc);
  new_macro.arg_no = decstr_to_int(number_of_args);
  size_t start_pos = pproc->current_pos;
  new_macro.body.buf = &pproc->input[pproc->current_pos];
  while(1){
	char ch = pull_token(pproc);
	if(ch == '!'){
	  size_t prev_pos = pproc->current_pos - 1;
	  charslice call_name = pull_space_delim_str(pproc);
	  if(call_name.len == strlen(directive_table[ENDMAC_IND])){
		if(!strncmp(call_name.buf, directive_table[ENDMAC_IND], call_name.len)){
		  new_macro.body.len = prev_pos - start_pos;
		  append_macro_slice(&pproc->macro_table, new_macro);
		  return;
		}
	  }
	}
  }
}

void map_and_build_tokens(pprocessor_t *pproc);
 
void handle_include(pprocessor_t *pproc)
{
  charslice qouted_file_name = pull_space_delim_str(pproc);
  charslice filenames = {0};
  if(qouted_file_name.buf[0] != '"')
	pre_proc_failure(pproc,qouted_file_name,"Expected Qouted file name");
  for(int i = 1; i < qouted_file_name.len;i++){
	if(qouted_file_name.buf[i] == '"')
	  break;
	append_char_slice(&filenames, &qouted_file_name.buf[i],1);
  }
  if(filenames.len != qouted_file_name.len - 2){
	pre_proc_failure(pproc,qouted_file_name, "File Name needs to be incased in qoutes");
  }
  char null_term = '\0';
  append_char_slice(&filenames,&null_term, 1);
  size_t file_size = 0;
  char *file_contents = read_file(filenames.buf,&file_size);
  size_t prev_pos = pproc->current_pos;
  size_t prev_col = pproc->current_col;
  size_t prev_line = pproc->current_line;
  char *prev_input = pproc->input;
  size_t prev_len = pproc->input_len;
  char *prev_filename = pproc->file_name;
  pproc->file_name = filenames.buf;
  pproc->current_col = 0;
  pproc->input = file_contents;
  pproc->input_len = file_size;
  pproc->current_pos = 0;
  pproc->current_line = 0;
  pproc->current_chunk.size = 0;
  map_and_build_tokens(pproc);
  pproc->input = prev_input;
  pproc->input_len = prev_len;
  pproc->current_col = prev_col;
  pproc->current_line = prev_line;
  pproc->current_pos = prev_pos;
  pproc->file_name = prev_filename;
}
charslice_slice extract_macro_args(charslice paren_args)
{
  charslice args = {.buf = paren_args.buf, .cap = 0, args.len = 0};
  charslice_slice ret = {0};
  for(int i = 0; i < paren_args.len && paren_args.buf[i] != ')';i++){
	if(paren_args.buf[i] == ','){
	  append_charslice_slice(&ret, args);
	  i++;
	  args.buf = &paren_args.buf[i];
	  args.len = 0;
	}
	args.len++;
  }
  append_charslice_slice(&ret, args);
  return ret;
}
//invocations within macros have to be handled seprately
void handle_macro(pprocessor_t *pproc,macro_t invoked_macro,charslice_slice args);
 void handle_invocation_in_macro(pprocessor_t *pproc,macro_t *current_macro)
 {
  char check_if_comment = peek_macro_char(current_macro);
  if(check_if_comment == '#'){
	check_if_comment = pull_macro_char(current_macro);
	while(check_if_comment != '\n'){
	  check_if_comment = pull_macro_char(current_macro);
	  check_if_comment = peek_macro_char(current_macro);
	}
	goto end;
  }
  charslice call_name = macro_pull_space_delim_str(current_macro); 
  int table_index = check_if_define(pproc, call_name);
  if(table_index != -1){
	append_char_slice(&pproc->output, pproc->define_tabe.buf[table_index].contents, pproc->define_tabe.buf[table_index].clen);
	goto end;
  }
  table_index = check_if_macro(pproc, call_name);
  if(table_index != -1){
	macro_t invoked_macro = pproc->macro_table.buf[table_index];
	if(current_macro->body.buf[current_macro->body.cap - 1] != '('){
	  pre_proc_failure(pproc, pproc->macro_table.buf[table_index].name, "Arguments must be placed within Parenethes when invoking a macro");
	}
	charslice paren_args = macro_pull_macro_args(current_macro);
	charslice_slice split_macro_args = extract_macro_args(paren_args);
	if(split_macro_args.len > invoked_macro.arg_no)
	  pre_proc_failure(pproc, pproc->macro_table.buf[table_index].name, "Too many Arguments supplied to macro");
	handle_macro(pproc,invoked_macro,split_macro_args);
	goto end;
  }else{
	pre_proc_failure(pproc, call_name, "Invaild Preprocessor invocation inside of a macro. Directives are not allowed within macros");
  }
 end:
  pproc->current_chunk.start = &current_macro->body.buf[current_macro->body.cap];
  pproc->current_chunk.size = 0;
 }
// TODO fix labels in macros
void handle_macro(pprocessor_t *pproc,macro_t invoked_macro,charslice_slice args)
{
  append_char_slice(&pproc->output, "\n", 1);
  pproc->current_chunk.size = 0;
  pproc->current_chunk.start = invoked_macro.body.buf;
  char ch = 1;
  for(;ch != 0;){
	ch = pull_macro_char(&invoked_macro);
	if(ch == '!'){
	  write_current_chunk(pproc);
	  handle_invocation_in_macro(pproc, &invoked_macro);
	}else if(ch == '%'){
	  write_current_chunk(pproc);
	  charslice arg_no = macro_pull_space_delim_str(&invoked_macro);
	  int arg_index = decstr_to_int(arg_no);
	  if(arg_index >= invoked_macro.arg_no){
		pre_proc_failure(pproc, arg_no, "Arg number greater than macro's specified arg count");
	  }
	  append_char_slice(&pproc->output, args.buf[arg_index].buf, args.buf[arg_index].len);
	  append_char_slice(&pproc->output, "\n",1);
	  pproc->current_chunk.size = 0;
	  pproc->current_chunk.start = &invoked_macro.body.buf[invoked_macro.body.cap];
	}else{
	  pproc->current_chunk.size++;
	}
  }
}
 
void handle_invocation(pprocessor_t *pproc)
{
  char check_if_comment = peek_token(pproc);
  if(check_if_comment == '#'){
	check_if_comment = pull_token(pproc);
	while(check_if_comment != '\n'){
	  check_if_comment = pull_token(pproc);
	  check_if_comment = peek_token(pproc);
	}
	goto end;
  }
  charslice call_name = pull_space_delim_str(pproc); //this is a view do not append;
  int table_index = check_if_dir(call_name.buf, call_name.len);
  if(table_index != -1){
	switch(table_index){
	case INCLUDE_IND:
	  handle_include(pproc);
	  break;
	case DEFINE_IND:
	  build_define(pproc);
	  break;
	case DEFMAC_IND:
	  build_macro(pproc);
	  break;
	default:
	  pre_proc_failure(pproc,call_name,"Unknown pre-processor directive");
	}
  }else{
	table_index = check_if_define(pproc, call_name);
	if(table_index != -1){
	  append_char_slice(&pproc->output, pproc->define_tabe.buf[table_index].contents, pproc->define_tabe.buf[table_index].clen);
	  goto end;
	}
	table_index = check_if_macro(pproc, call_name);
	if(table_index != -1){
	  macro_t invoked_macro = pproc->macro_table.buf[table_index];
	  if(pproc->input[pproc->current_pos - 1] != '('){
		pre_proc_failure(pproc, pproc->macro_table.buf[table_index].name, "Arguments must be placed within Parenethes when invoking a macro");
	  }
	  charslice paren_args = pull_macro_args(pproc);
	  charslice_slice split_macro_args = extract_macro_args(paren_args);
	  if(split_macro_args.len > invoked_macro.arg_no)
		pre_proc_failure(pproc, pproc->macro_table.buf[table_index].name, "Too many Arguments supplied to macro");
	  handle_macro(pproc,invoked_macro,split_macro_args);
	}else
	  pre_proc_failure(pproc,call_name,"Unknown pre-processor directive or macro");
	
  }
 end: 
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
void preprocess(char **buf,size_t *size,char *filename)
{
  pprocessor_t pproc = {0};
  pproc.file_name = filename;
  pproc.input = *buf;
  pproc.input_len = *size;
  map_and_build_tokens(&pproc);
  free(*buf);
  *buf = pproc.output.buf;
  *size = pproc.output.len;
}
