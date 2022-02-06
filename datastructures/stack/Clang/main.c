#include <stdio.h>
#include <stdlib.h>


typedef struct node_t {
  int value;
  struct node_t *next;
} node_t;

typedef struct stack_t {
  int size;
  int length;
  struct node_t *head;
} stack_t;


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

int stack_get_size(const stack_t *stack) {
  return stack->size;
}

void push(stack_t *stack, int value) {
  if (stack->length < stack_get_size(stack)) {
    node_t *tmp = malloc(sizeof(node_t));
    tmp->value= value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->length++;
  }
}

int get_head(const stack_t *stack) {
    return stack->head->value;
}

int pop(stack_t *stack) {

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

void dump(stack_t *stack) {

  int length = stack->length;
  int x = pop(stack);
  printf("\t%d\n", x);
  stack_t *tmp = init_stack(x, length);

  while (stack->length > 0) {
    x = pop(stack);
    printf("\t%d\n", x);
    push(tmp, x);
  }

  while (tmp->length > 0) {
    x = pop(tmp);
    push(stack, x);
  }

}

int main() {

  stack_t *s = init_stack(0, 6);

  for (int i = 1; i < stack_get_size(s); i++)
    push(s, i); 

  printf("Length: %d\n", s->length);

  dump(s);

  return 0;
}
