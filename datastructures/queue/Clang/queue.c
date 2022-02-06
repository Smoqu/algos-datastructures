#include "queue.h"

queue_t *init_queue(int head) {
  q_node_t *node = malloc(sizeof(q_node_t));

  node->value = head;
  node->next = NULL;

  queue_t *q = malloc(sizeof(queue_t));

  q->head = node;
  q->length = 1;
  
  return q;
}


int *q_get_head(queue_t *q) {
  if (q->head != NULL)
    return &q->head->value;

  return NULL;
}

void q_append(queue_t *q, int value) {
  q_node_t *node = malloc(sizeof(q_node_t));
  node->value = value;
  node->next = NULL;

  if (q->head == NULL) q->head = node;

  q_node_t *current = q->head;

  while (current->next != NULL) current = current->next;

  current->next = node;

  q->length++;
}

int q_pop(queue_t *q) {
  if (q->length == 0) return 0;

  int v = q->head->value;
  
  q_node_t *next = q->head->next;
  q->head = NULL;

  if (next) q->head = next; 
  
  return v;
}

void q_dump(queue_t *q) {
  q_node_t *current = q->head; 

  while (current != NULL) { 
    printf("\t%d\n", current->value);
    current = current->next;
  }
}
