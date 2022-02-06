#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} node_t;

typedef struct stack {
  int size;
  int length;
  struct node *head;
} stack_t;

stack_t *init_stack(int head, unsigned int size);

int s_get_size(const stack_t *stack);

void s_push(stack_t *stack, int value);

int s_get_head(const stack_t *stack);

int s_jpop(stack_t *stack);

void s_dump(stack_t *stack);
