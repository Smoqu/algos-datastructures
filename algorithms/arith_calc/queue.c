#include "queue.h"

void queue_push(t_queue *queue, char *value) {
  t_node *node = malloc(sizeof(t_node));
  node->value = value;
  node->next = NULL;

  if (queue->head == NULL) queue->head = node;
  else {
    t_node *c = queue->head;

    while(c->next != NULL) {
      c = c->next;
    }
    c->next = node;
  }
  
  queue->length++;
}

t_queue *create_queue(char *head) {
  t_queue *queue = malloc(sizeof(t_queue)); 
  queue_push(queue, head);
  return queue;
}

char *queue_pop(t_queue *queue) {
  if (queue == NULL || queue->length == 0 || queue->head == NULL) return NULL;

  char *s = queue->head->value;
  t_node *next = queue->head->next; 
  queue->head = NULL;

  if (next) queue->head = next;
  queue->length--;

  return s; 
}

void display_queue(t_queue *queue) {
  char *s = queue_pop(queue);
  t_queue *temp = create_queue(s);
  printf("%s, ", s);
  do {
    s = queue_pop(queue);
    printf("%s, ", s);
    queue_push(temp, s);
  } while (queue->length > 0);

  do {
    s = queue_pop(temp);
    queue_push(queue, s);
  } while (temp->length > 0);
}

t_node *queue_get_head(t_queue *queue) {
  return queue->head;
}

