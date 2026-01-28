#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "math_operators.h"
#include "expression_logic.h"
#include "shunting_yard.h"
#include "stack.h"

int main () {

  printf("Insert an expression: ");
  char *expression = read_expression();
  unsigned short total_tokens = 0;

  struct token *token_vector = tokenize_expression(expression, &total_tokens);

  print_token_vector(token_vector, total_tokens);

  //Gera uma expressão polonesa da expressão incial
  //Generates polish expression
  struct token *output = shunting_yard_algorithm(token_vector, &total_tokens);

  printf("\nPRINTING POLISH EXPRESSION:\n");
  print_token_vector(output,total_tokens);

  double final_result = evaluate_polish_expression(output, total_tokens);

  printf("\nFINAL RESULT: %lf\n", final_result);

  destroy_expression(expression);

  destroy_token_vector(token_vector);

  free(output);

  return 0;
}