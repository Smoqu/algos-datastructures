#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "node.h"

typedef struct Stack {
  t_node *head; 
  int length;
} t_stack;

t_stack *create_stack(char *head);
void stack_push(t_stack *stack, char *value);
char *stack_pop(t_stack *stack);
void display_stack(t_stack *stack);
