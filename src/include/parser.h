#ifndef PARSER_H
#define PARSER_H
#include "typedefs.h"
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
parser_t init_parser(token_slice input);
void parse_tokens(parser_t *parser);
#endif
