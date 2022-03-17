#include "tree.h"

int main() {

  bin_tree_t *tree = init_tree(2);

  t_insert(tree, 1);
  t_insert(tree, 5);
  t_insert(tree, 3);
  t_insert(tree, -2);


  t_dump(tree);

  int found = t_seek(tree, 5);
  printf("Found: %d\n", found);
  found = t_seek(tree, 10);
  printf("Found: %d\n", found);


  return 0;
}
