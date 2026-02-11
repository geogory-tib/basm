#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <stdlib.h>
// Common Macros Shared accrossed project
#define EXIT_AND_FAIL(msg)						\
  fprintf(stderr,"%s\n",msg);					\
  exit(EXIT_FAILURE);
#define PANIC(msg) \
  fprintf(stderr,"PANIC: %s in file:%s:%d in function %s \n",msg,__FILE__,__LINE__,__func__);\
  abort();
#endif
