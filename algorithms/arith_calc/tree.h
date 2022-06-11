#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Tree {
  char *value;
  struct Tree *right;
  struct Tree *left;
} t_tree;

t_tree *create_tree(char *value);

bool insert(t_tree *tree, t_tree *n);

void display_tree(t_tree *tree, uint indent);
