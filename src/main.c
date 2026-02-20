#include <stdio.h>
#include <stdlib.h>

#include "include/common.h"
#include "include/lexer.h"
#include "include/io.h"
#include "include/parser.h"
int main(int argc, char **argv)
{
  if(argc <= 1 ){
	EXIT_AND_FAIL("No input provided");
  }
  size_t file_size;
  char *file_data = read_file(argv[1], &file_size);
  lexer_t lexer = init_lexer(file_data, file_size);
  token_slice lexer_output = lex_tokens(&lexer);
  parser_t parser = init_parser(lexer_output);
  parse_tokens(&parser);
  return 0;
}
