#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "expression_logic.h"

#define MAX_INPUT 100

char *read_expression () {
  //Aloca uma string para guardar o input do usuário
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
  printf("\n------------------------------\n");
  printf("PRINTING EXPRESSION:\n");

  int expression_size = strlen(expression);
  for (int i = 0; i < expression_size; i++) {
    printf("%c",expression[i]);
  }
  printf("\n-------------------------------"); 
}

struct token *tokenize_expression (char *expression, unsigned short *total_tokens) {
  //Retorna o tamanho da string sem considerar o \0
  unsigned short expression_size = strlen(expression);
  struct token *token_vector = malloc (expression_size * sizeof(struct token));
  if (token_vector == NULL) {return NULL;}

  //Aponta para o elemento da string que sera analisado
  const char *ptr = expression;
  unsigned short token_index = 0;

  while (*ptr != '\0') {
    //ignora os espaços entre a expressão
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
      printf("\nInvalid character\n");
      free(token_vector);
      token_vector = NULL;
      return NULL;
    }
    token_index ++;
  }

  *total_tokens = token_index;

  //Redimensiona o vetor com base no número de tokens gerados
  struct token *temp = (struct token *) realloc (token_vector, *total_tokens * sizeof(struct token));
  if (temp) {
    token_vector = temp;
  }
  else {
    perror("\nReallocate ERROR\n");
    exit(EXIT_FAILURE);
  }

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

  printf("----------------------------------------\n");
  printf("\nPrinting token VECTOR:\n");

  for (int i = 0; i < total_tokens; i++) {
    printf("Token %d: ", i);
    switch (vector[i].type) {
      case number:
        printf("[Number] %lf\n", vector[i].value);
        break;
      case operation:
        printf("[Operator] %c\n", vector[i].operation);
        break;
      case opened_parentheses:
        printf("[Parenthesis] (\n");
        break;
      case closed_parentheses:
        printf("[Parenthesis] )\n");
        break;
      default:
        printf("[Unknown char]\n");
    }
  }
  printf("\n----------------------------------------\n");
}