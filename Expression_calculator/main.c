#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "math_operators.h"
#include "expression_logic.h"

int main () {

  printf("Insert an expression: ");

  char *expression = read_expression();
  unsigned short total_tokens = 0;

  print_expression(expression);

  struct token *token_vector = tokenize_expression(expression, &total_tokens);

  print_token_vector(token_vector, total_tokens);

  destroy_expression(expression);

  destroy_token_vector(token_vector);

  return 0;
}