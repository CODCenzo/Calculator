#include <stdio.h>
#include "math_operators.h"

int main () {
  char operator;
  double num_1, num_2, result;

  printf("Insert first number: ");
  scanf("%lf", &num_1); //%g representa um real, tbm pode ser %lf (long float)
  printf("Insert second number: ");
  scanf("%lf", &num_2);
  printf("Insert operator (*,/,+,-): ");
  scanf(" %s", &operator); // O espaço remove whitespace

  switch (operator) {
    case '+':
      result = addition(num_1, num_2);
      break;
    case '-':
      result = subtraction(num_1, num_2);
      break;
    case '*':
      result = multiplication(num_1, num_2);
      break;
    case '/':
      result = division(num_1, num_2);
      break;
    default:
      printf("Operador não reconhecido.\n");
      break;
  }

  printf("The result is: %.3lf\n", result);

  return 0;
}