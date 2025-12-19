#ifndef __EXPRESSION_LOGIC__
#define __EXPRESSION_LOGIC__

typedef enum {
  number,
  operation,
  opened_parentheses,
  closed_parentheses,
  end
} token_type;

struct token {
  token_type type;
  double value;
  char operation;
};

char *read_expression ();

void destroy_expression (char *expression);

void print_expression (char *expression);

struct token *tokenize_expression (char *expression, unsigned short *total_tokens);

void destroy_token_vector (struct token *vector);

void print_token_vector (struct token *vector, unsigned short total_tokens);

#endif