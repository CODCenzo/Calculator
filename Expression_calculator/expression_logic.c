#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "expression_logic.h"

#define MAX_INPUT 100

char *read_expression () {
  //Cria uma string para guardar o input do usuário
  char *expression = malloc (MAX_INPUT * sizeof(char));
  if (expression == NULL) {return NULL;}

  //Lê a string até encontrar uma quebra de linha
  scanf(" %[^\n]", expression);
  return expression;
}

void destroy_expression (char *expression) {
  if (expression) {
    free(expression);
    expression = NULL;
  }
}

void print_expression (char *expression) {
  //Imprime a expressão de input
  printf("Printing Expression---------------\n");
  int tam_expression = strlen(expression);
  for (int i = 0; i < tam_expression; i++) {
    printf("%c",expression[i]);
  }
  printf("\n-------------------------------\n"); 
}

struct token *tokenize_expression (char *expression, unsigned short *total_tokens) {
  //Retorna o tamanho da string sem considerar o \0
  unsigned short tam_expression = strlen(expression);
  struct token *token_vector = malloc (tam_expression * sizeof(struct token));
  if (token_vector == NULL) {return NULL;
  }

  //Aponta para o elemento da string que sera analisado
  const char *ptr = expression;
  unsigned short token_index = 0;

  while (*ptr != '\0') {
    if (isspace(*ptr)) {
      ptr++;
      continue;
    }

    if (isdigit(*ptr)) {
      char *next_segment;
      //Preenche o token com o valor e pula para o próximo elemento da expressão
      token_vector[token_index].value = strtod(ptr, &next_segment);
      token_vector[token_index].type = number;
      token_vector[token_index].operation = 0;
      ptr = next_segment;
    } else if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/') {
      token_vector[token_index].value = 0;
      token_vector[token_index].type = operation;
      token_vector[token_index].operation = *ptr;
      ptr++;
    } else if (*ptr == '(') {
      token_vector[token_index].value = 0;
      token_vector[token_index].type = opened_parentheses;
      token_vector[token_index].operation = *ptr;
      ptr++;
    } else if (*ptr == ')') {
      token_vector[token_index].value = 0;
      token_vector[token_index].type = closed_parentheses;
      token_vector[token_index].operation = *ptr;
      ptr++;
    } else {
      printf("Invalid character\n");
      free(token_vector);
      token_vector = NULL;
      return NULL;
    }
    token_index ++;
  }

  *total_tokens = token_index;
  token_vector = (struct token *) realloc (token_vector, *total_tokens * sizeof(struct token));
  
  return token_vector;
}

void destroy_token_vector (struct token *vector) {

  if(vector) {
    free(vector);
    vector = NULL;
  }
}

void print_token_vector (struct token *vector, unsigned short total_tokens) {
  if (!vector) {return;}

  for (int i = 0; i < total_tokens; i++) {
    printf("Token %d: ", i);
    switch (vector[i].type) {
      case number:
        printf("[Número] %lf\n", vector[i].value);
        break;
      case operation:
        printf("[Operador] %c\n", vector[i].operation);
        break;
      case opened_parentheses:
        printf("[Parêntese] (\n");
        break;
      case closed_parentheses:
        printf("[Parêntese] )\n");
        break;
      default:
        printf("[Desconhecido]\n");
    }
  }
}