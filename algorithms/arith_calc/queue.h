#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct Queue {
  t_node *head; 
  int length;
} t_queue;

t_queue *create_queue(char *head);
void queue_push(t_queue *queue, char *value);
char *queue_pop(t_queue *queue);
void display_queue(t_queue *queue);
t_node *queue_get_head(t_queue *queue);

