#ifndef PARSER_H
#define PARSER_H
#include "typedefs.h"
#include "instructions.h"
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

typedef struct
{
  byte *buf;
  size_t cap;
}byte_slice;

typedef struct{
  token_t *buf;
  size_t len;
  size_t cap;
}expr_t;

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

parser_t init_parser(token_slice input);
void parse_tokens(parser_t *parser);
#endif
