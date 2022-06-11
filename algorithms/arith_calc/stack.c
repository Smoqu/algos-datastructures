#include "stack.h"

void stack_push(t_stack *stack, char *value) {
  t_node *node = malloc(sizeof(t_node)); 
  node->value = value;
  node->next = NULL;
  node->next = stack->head;
  stack->head = node;
  stack->length++;
}

t_stack *create_stack(char *head) {
  t_stack *stack = malloc(sizeof(t_stack)); 
  stack_push(stack, head);
  return stack;
};

char *stack_pop(t_stack *stack) {
  if (stack == NULL || stack->length == 0 || stack->head == NULL) return NULL;

  t_node *c = stack->head;
  char *s = c->value;

  if (stack->head->next == NULL)
    stack->head = NULL;
  else stack->head = stack->head->next;

  stack->length--;
  return s;
}

void display_stack(t_stack *stack) {
  char *s = stack_pop(stack);
  t_stack *temp = create_stack(s);
  printf("%s, ", s);
  do {
    s = stack_pop(stack);
    printf("%s, ", s);
    stack_push(temp, s);
  } while (stack->length > 0);

  do {
    s = stack_pop(temp);
    stack_push(stack, s);
  } while (temp->length > 0);
}

