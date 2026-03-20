#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <stdlib.h>
// Common Macros Shared accrossed project
#ifndef DEBUG
#define EXIT_AND_FAIL(msg,tok)						\
  fprintf(stderr,"(%d:%d) %s : '%.*s'\n",(tok).row + 1,(tok).col+1,msg,(tok).str_len,(tok).raw); \
  exit(EXIT_FAILURE);
#else
#define EXIT_AND_FAIL(msg, tok) \
  fprintf(stderr,"(%d:%d) %s : '%.*s' @ %s:%d\n",(tok).row + 1,(tok).col+1,msg,(tok).str_len,(tok).raw,__FILE__,__LINE__); \
  exit(EXIT_FAILURE);
#endif
#define PANIC(msg) \
  fprintf(stderr,"PANIC: %s in file:%s:%d in function %s \n",msg,__FILE__,__LINE__,__func__);\
  abort();

#define BASM_HELP_MSG \
  "Basm --- The Bad Assembler For The 6502 Instruction set\n"\
  "USAGE: basm input output\n" \
  "Written By Samuel Alan Johnson In his free time\n"
#endif
