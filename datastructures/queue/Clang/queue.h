#include <stdio.h>
#include <stdlib.h>

typedef struct node_q {
  int value;
  struct node_q *next;
} q_node_t;

typedef struct queue {
  struct node_q *head; 
  int length;
} queue_t;

queue_t *init_queue(int head);
int *q_get_head(queue_t *q);
void q_append(queue_t *q, int value);
int q_pop(queue_t *q);
void q_dump(queue_t *q);
