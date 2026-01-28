#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "expression_logic.h"

struct node_t *stack_node_create (struct token t) {
  struct node_t *n = malloc (sizeof(struct node_t));
  if (n == NULL) {return NULL;} 

  n->data = t;
  n->next = NULL;

  return n;
}

//Destroi o nodo e retorna NULL
struct node_t *stack_node_destroy (struct node_t *n) {
  if (n == NULL) {return NULL;}

  free(n);
  n = NULL;

  return NULL;
};

//Aloca uma pilha com a capacidade desejada
struct stack_t *stack_create (unsigned short capacity) {
  if (capacity <= 0) {return NULL;}

  struct stack_t *new_stack = malloc (sizeof(struct stack_t));
  if (new_stack == NULL) {return NULL;}

  new_stack->capacity = capacity;
  new_stack->size = 0;
  new_stack->top_node = NULL;

  return new_stack;
}

//Retorna NULL caso a pilha tenha sido destruída
struct stack_t *stack_destroy (struct stack_t *s) {
  if (s == NULL) {return NULL;}
  struct node_t *aux;

  while (s->top_node != NULL) {
    aux = s->top_node;
    s->top_node = s->top_node->next;
    free(aux);
    aux = NULL;
    s->size--;
  }
  free(s);
  s = NULL;

  return NULL;
}

//Insere o elemento no topo da pilha
//Retorna o tamanho da pilha caso a inserção tenha sido bem sucedida
//Caso contrário retorna -1
short stack_insert (struct stack_t *s, struct node_t *n) {
  if (n == NULL || s == NULL) {return -1;}

  if (s->size >= s->capacity) {
    printf("\nUnable to insert, stack is full\n");
    return -1;
  }

  n->next = s->top_node;
  s->top_node = n;
  s->size++;
  return s->size;
}

//Remove o elemento do topo da pilha
//Retorna o próprio elemento
//Caso contrário retorna NULL
struct node_t *stack_remove (struct stack_t *s) {
  if (s == NULL || s->size <= 0) {return NULL;}

  struct node_t *aux;

  aux = s->top_node;
  s->top_node = s->top_node->next;
  s->size --;

  return aux;
}

//Retorna o elemento que esta no topo
//Caso contrário retorna NULL
struct node_t *stack_find (struct stack_t *s, struct node_t *n){
  if (s == NULL || n == NULL) {return NULL;}

  struct node_t *aux;

  aux = s->top_node;
  for (int i = 0; i < s->size; i++) {
    if (aux == n) {return aux;}
    aux = aux->next;
  }
  return NULL;
}

//Retorna o elemento que esta no topo
//Caso contrário retorna NULL
struct node_t *stack_peek (struct stack_t *s) {
  if (s == NULL || s->size <= 0) {return NULL;}

  return s->top_node;
}

//Imprime a pilha
void stack_print (struct stack_t *s) {
  if (s == NULL || s->size <= 0) {
    printf("\nPrint stack error");
    return;
  }

  printf("\nPrinting STACK:\n");
  printf("\n----------------------------------------\n");

  struct node_t *ptr = s->top_node;
  int i = 0;

  while (ptr != NULL) {
    printf("Token %d: ", i);
    switch (ptr->data.type) {
      case number:
        printf("[Number] %lf\n", ptr->data.value);
        break;
      case operation:
        printf("[Operator] %c\n", ptr->data.operation);
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
    ptr = ptr->next;
    i++;
  }
  printf("\n----------------------------------------\n");
}