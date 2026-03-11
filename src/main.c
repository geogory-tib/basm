#include <stdio.h>
#include <stdlib.h>

#include "include/common.h"
#include "include/lexer.h"
#include "include/io.h"
#include "include/parser.h"
#include "include/typedefs.h"
int main(int argc, char **argv)
{
  if(argc <= 2 ){
	fprintf(stderr,"%s",BASM_HELP_MSG);
	exit(EXIT_FAILURE);
  }
  size_t file_size;
  char *file_data = read_file(argv[1], &file_size);
  lexer_t lexer = init_lexer(file_data, file_size);
  token_slice lexer_output = lex_tokens(&lexer);
  parser_t parser = init_parser(lexer_output);
  parse_tokens(&parser);
  FILE *output_file = fopen(argv[2],"wb+");
  if(output_file == NULL){
	PANIC("Failed to open output file");
  }
  int code  = fwrite(parser.output.buf, sizeof(byte), parser.pc, output_file);
  fclose(output_file);
  return 0;
}
