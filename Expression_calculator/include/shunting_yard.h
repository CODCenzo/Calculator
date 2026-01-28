#ifndef __SHUNTING_YARD__
#define __SHUNTING_YARD__

struct operation {
  char precedence;
  char arguments;
};

//Transforma a expressão contida no vetor de tokens em expressão polonesa
//Transforms the expression contained in the token vector into a Polish expression.
struct token *shunting_yard_algorithm (struct token *input, unsigned short *total_tokens);

//Utiliza uma pilha para computar o resultado da expressão polonesa
//Uses a stack to compute the result of the Polish expression.
double evaluate_polish_expression (struct token *polish_expression, unsigned short total_tokens);

#endif