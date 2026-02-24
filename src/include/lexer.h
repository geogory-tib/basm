#ifndef LEXER_H
#define LEXER_H
typedef enum{
  MNEMONIC = 0,
  LABEL,
  IDENT,
  DEC_NUMBER,
  HEX_NUMBER,
  HASHTAG,
  COMMA,
  PLUS,
  MINUS,
  MULT,
  DIV,
  OPEN_PAREN,
  CLOSED_PAREN,
  TOK_EOF
}toktype_t;

typedef struct
{
  char *input;
  size_t current_pos;
  size_t len;
  size_t current_line;
  size_t current_col;
  char current_ch;
}lexer_t;
typedef struct
{
  char *raw;
  int str_len;
  toktype_t type;
  int value; //used for number constants in code
  int col;
  int row;
}token_t;

typedef struct
{
  token_t *buf;
  size_t len;
  size_t cap; 
}token_slice;

lexer_t init_lexer(char *input,size_t len);

token_slice lex_tokens(lexer_t *lexer);

#endif
