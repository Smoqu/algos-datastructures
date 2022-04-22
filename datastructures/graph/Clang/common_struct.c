#include <stdio.h>
#include <stdlib.h>
#include "common_struct.h"

g_node_t *vector(int length)
{
  g_node_t *nodes = malloc(sizeof(g_node_t) * length);

  return nodes;
}

g_node_t *grow(g_node_t *vec, int length)
{
  g_node_t *new = vector(length * 2);
  for (int i = 0; i < length; i++)
  {
    new[i] = vec[i];
  }

  free(vec);

  return new;
}

g_node_t *shrink(g_node_t *vec, int length)
{
  g_node_t *new = vector((int)(length / 2));

  for (int i = 0; i < length; i++)
  {
    if (i == length / 2)
      new[i] = vec[i];
  }

  return new;
}

int main()
{

  g_node_t n1 = {.value = 'c'};
  g_node_t n2 = {.value = 'e'};
  g_node_t n3 = {.value = 'd'};
  g_node_t n4 = {.value = 'r'};
  g_node_t n5 = {.value = 'i'};
  g_node_t n6 = {.value = 'k'};

  g_node_t *v = vector(3);

  v[0] = n1;
  v[1] = n2;
  v[2] = n3;

  v = grow(v, 3);

  v[3] = n4;
  v[4] = n5;
  v[5] = n6;

  for (int i = 0; i < 6; i++)
    printf("%c\n", v[i].value);

  g_node_t *vec = shrink(v, 6);
  for (int i = 0; i < 3; i++)
    printf("%s\n", vec[i].value);

  return 0;
}
