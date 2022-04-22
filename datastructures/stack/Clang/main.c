#include "stack.h"

int main()
{

  stack_t *s = init_stack(0, 6);

  for (int i = 1; i < s_get_size(s); i++)
    s_push(s, i);

  printf("Length: %d\n", s->length);

  /*dump(&s);*/

  /*int x = pop(s);*/
  /*stack_t *tmp = init_stack(x, s->length);*/
  for (int i = 0; i < stack_get_size(s); i++)
  {
    printf("%d\n", get_head(s));
    pop(s);
  }
  s_dump(s);

  return 0;
}
