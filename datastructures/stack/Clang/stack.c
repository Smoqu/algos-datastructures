#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


stack_t *init_stack(int head, unsigned int size) {

  if (size == 0) return NULL;

  stack_t *s = malloc(sizeof(stack_t));
  node_t *_head = malloc(sizeof(node_t));

  _head->value = head;
  _head->next = NULL;

  s->size = size;
  s->head = _head;
  s->length = 1;

  return s;

}

int s_get_size(const stack_t *stack) {
  return stack->size;
}

void s_push(stack_t *stack, int value) {
  if (stack->length < s_get_size(stack)) {
    node_t *tmp = malloc(sizeof(node_t));
    tmp->value= value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->length++;
  }
}

int s_get_head(const stack_t *stack) {
    return stack->head->value;
}

int s_pop(stack_t *stack) {

  node_t *h = stack->head;
  int old_value = h->value;
  if (stack->head->next == NULL) {
    stack->head = NULL;
    stack->length--;
    return old_value;
  }

  node_t *new_head = h->next;

  stack->head = new_head;
  stack->length--;

  return old_value; 
}

void s_dump(stack_t *stack) {

  int length = stack->length;
  int x = s_pop(stack);
  printf("\t%d\n", x);
  stack_t *tmp = init_stack(x, length);

  while (stack->length > 0) {
    x = s_pop(stack);
    printf("\t%d\n", x);
    s_push(tmp, x);
  }

  while (tmp->length > 0) {
    x = s_pop(tmp);
    s_push(stack, x);
  }

}
