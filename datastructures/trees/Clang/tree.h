#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
  int value;
  struct tree *left;
  struct tree *right;
  int init;
} bin_tree_t;

bin_tree_t *init_tree(int root);
void insert(bin_tree_t *tree, int value);
void t_dump(const bin_tree_t *tree);
int t_seek(const bin_tree_t *tree, int value);
void t_insert(bin_tree_t *tree, int value);
