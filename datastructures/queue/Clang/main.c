#include "queue.h"

int main() {
  queue_t *q = init_queue(5);
  q_append(q, 7);
  q_append(q, 9);

  printf("Listing:\n");
  q_dump(q);

  q_pop(q);

  printf("Listing:\n");
  q_dump(q);

}
