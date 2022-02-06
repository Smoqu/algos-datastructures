#include "stack.h"

int main() {

  stack_t *s = init_stack(0, 6);

  for (int i = 1; i < s_get_size(s); i++)
    s_push(s, i); 

  printf("Length: %d\n", s->length);

  s_dump(s);

  return 0;
}
