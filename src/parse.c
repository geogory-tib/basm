#include <stdio.h>
#include <stdlib.h>

#include "include/typedefs.h"
#include "include/lexer.h"
#include "include/instructions.h"
#define DIRECT_VAR_ARGS -1
typedef struct
{
  int args_count;
}direct_t;
typedef struct
{
  char *name;
  size_t strlen;
  u16 addr;
}label_t;

typedef struct
{
  label_t *buf;
  size_t len;
  size_t cap;
}label_slice;
typedef struct
{
 
  byte *output;
  instruct_t instrt_table[56];
  direct_t directives_table[4];
  label_t *lable_array;
  u16 pc;
}parser_t;


parser_t *init_parser(token_slice input)
{
 
}
