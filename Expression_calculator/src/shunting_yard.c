#include <stdlib.h>

#include "shunting_yard.h"
#include "stack.h"
#include "expression_logic.h"
#include "math_operators.h"
#include "stdio.h"

//Cria um hash map que guarda a precedencia e número de argumentos de um operador.
//Creates a hash map that stores the precedence and number of arguments.
static struct operation map_ops[256]; 

void inicialize_map_ops () {
  map_ops['('] = (struct operation){0,2};
  map_ops[')'] = (struct operation){0,2};
  map_ops['-'] = (struct operation){1,2};
  map_ops['+'] = (struct operation){1,2};
  map_ops['*'] = (struct operation){2,2};
  map_ops['/'] = (struct operation){2,2};  
}

//Retorna um vetor de tokens com a notação polonesa da expressão
struct token *shunting_yard_algorithm (struct token *input, unsigned short *total_tokens) {
  struct stack_t *operator_stack = stack_create(*total_tokens);
  struct token *output = malloc (sizeof(struct token)* (*total_tokens));

  //Inicializa hash table
  inicialize_map_ops(map_ops);

  int output_index = 0;
  for (int input_index = 0; input_index < *total_tokens; input_index ++) {
    //Se for um parenteses aberto, devemos inserir na stack
    if (input[input_index].type == opened_parentheses) {
      struct node_t *opened_par_node = stack_node_create(input[input_index]);
      stack_insert(operator_stack,opened_par_node);
    }

    //Se for um parenteses fechado, devemos dar flush nos operadores que estão entre os parenteses
    if (input[input_index].type == closed_parentheses) {
      struct node_t *removed;

      //Flush inside parenteses
      while (operator_stack->size > 0 && stack_peek(operator_stack)->data.type != opened_parentheses) {
        removed = stack_remove(operator_stack);
        output[output_index++] = removed->data;
        free(removed);
      } 

      //Remove o parenteses aberto
      removed = stack_remove(operator_stack);
      free(removed);
    }

    //Se for numero, insere direto no output
    if (input[input_index].type == number) {
      output[output_index] = input[input_index];
      output_index ++;
    }

    //É um operador
    if (input[input_index].type == operation) {
      struct node_t *novo_operador = stack_node_create(input[input_index]);

      // Enquanto houver operador no topo E a precedência do topo >= precedência do novo
      while (operator_stack->size > 0 && 
        operator_stack->top_node->data.type == operation &&
        map_ops[(unsigned char)operator_stack->top_node->data.operation].precedence >= map_ops[(unsigned char)input[input_index].operation].precedence) {
      
        struct node_t *removed = stack_remove(operator_stack);
        output[output_index++] = removed->data;
        free(removed);
      }
      stack_insert(operator_stack, novo_operador);
    }
  }

  //Da flush nos operadores que restaram na operator stack
  if (operator_stack->size > 0) {
    while (operator_stack->top_node != NULL) {
      struct node_t *nodo_removed = stack_remove(operator_stack);
      output[output_index] = nodo_removed->data;
      output_index++;
      free(nodo_removed);
      nodo_removed = NULL;
    } 
  }
  *total_tokens = (unsigned short) output_index;

  stack_destroy(operator_stack);
  return output;
}


double evaluate_polish_expression (struct token *polish_expression, unsigned short total_tokens) {
  struct stack_t *result_stack = stack_create(total_tokens);
  double arg_1;
  double arg_2;
  double op_result;

  for (int i = 0; i < total_tokens; i ++) {

    //Se for numero é só empilhar
    if (polish_expression[i].type == number) {
      struct node_t *nodo_numerico = stack_node_create(polish_expression[i]);
      stack_insert(result_stack, nodo_numerico);
    }
    //Se for operação devemos computar os dois valores do topo da pilha
    else if (polish_expression[i].type == operation) {

      struct node_t *node_2 = stack_remove(result_stack);
      struct node_t *node_1 = stack_remove(result_stack);

      if (node_1 == NULL || node_2 == NULL) {
        printf("\nErro ao formar expressão\n");
        exit(EXIT_FAILURE);
      }

      arg_2 = node_2->data.value;
      arg_1 = node_1->data.value;

      switch (polish_expression[i].operation){
        case '+':
          op_result = addition(arg_1,arg_2);
          break;
        case '-':
          op_result = subtraction(arg_1, arg_2);
          break;
        case '*':
          op_result = multiplication(arg_1, arg_2);
          break;
        case '/':
          op_result = division(arg_1, arg_2);
          break;
        default:
          printf("\nERROR\n");
          break;
      }

      //Insere o resultado da computação de volta na pilha
      struct token res_token;
      res_token.type = number;
      res_token.value = op_result;

      stack_insert(result_stack, stack_node_create(res_token));

      free(node_1);
      free(node_2);
    }
  }
  struct node_t *final_node = stack_remove(result_stack);
  double result = final_node->data.value;
  free(final_node);
  free(result_stack);

  return result;
}