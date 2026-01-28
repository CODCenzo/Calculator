#ifndef __STACK__
#define __STACK__

#include "expression_logic.h"

struct node_t {
  struct token data;
  struct node_t *next;
};

struct stack_t {
  struct node_t *top_node;
  unsigned short size;
  unsigned short capacity;
};

//Cria um nodo a partir de um token
struct node_t *stack_node_create (struct token t);

//Destroi o nodo e retorna NULL
struct node_t *stack_node_destroy (struct node_t *n);

//Aloca uma pilha com a capacidade desejada
struct stack_t *stack_create (unsigned short capacity);

//Retorna NULL caso a pilha tenha sido destruída
struct stack_t *stack_destroy (struct stack_t *s);

//Insere o elemento no topo da pilha
//Retorna o tamanho da pilha caso a inserção tenha sido bem sucedida
//Caso contrário retorna -1
short stack_insert (struct stack_t *s, struct node_t *n);

//Remove o elemento do topo da pilha
//Retorna o próprio elemento
//Caso contrário retorna NULL
struct node_t *stack_remove (struct stack_t *s);

//Busca um elemento e retorna ele mesmo
//Caso contrário retorna NULL
struct node_t *stack_find (struct stack_t *s, struct node_t *n);

//Retorna o elemento que esta no topo
//Caso contrário retorna NULL
struct node_t *stack_peek (struct stack_t *s);

//Imprime a pilha
void stack_print (struct stack_t *s);

#endif