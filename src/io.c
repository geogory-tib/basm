#include <stdio.h>
#include <stdlib.h>

#include "include/common.h"
/*
  Basic IO routines used throughout the program

 */

char *read_file(const char*name,size_t *size)
{
  char buf[512];
  FILE *input_file = fopen(name,"r");
  char *ret_buf;
  ret_buf = calloc(1024,sizeof(char));
  size_t buf_size = 1024;
  size_t len = 0;
  while(!feof(input_file)){
	int read = fread(buf,sizeof(char),512,input_file);
	if(len >= buf_size){
	  buf_size += 512;
	  void *temp = realloc(ret_buf,(sizeof(char) * buf_size));
	  if(!temp){
		EXIT_AND_FAIL("realloc failure: Out of Memory");
	  }
	  ret_buf = temp;
	}
	if (read != 0){
	  for(int i = 0; i < read; i++){
		ret_buf[i + len] = buf[i];
	  }
	  len += read;
	}
  }
  fclose(input_file);
  *size = len;
  return ret_buf;
}
