#include "tree.h"

t_tree *create_tree(char *value) {
  t_tree *tree = malloc(sizeof(t_tree));
  tree->value = value;
  t_tree *left = malloc(sizeof(t_tree));
  tree->left = left;
  t_tree *right = malloc(sizeof(t_tree));
  tree->right = right;
  return tree;
}

bool insert(t_tree *tree, t_tree *new) {
  if (tree == new) return false;
  if (tree->left == NULL) tree->left = new;
  else if (tree->right == NULL) tree->right = new; 
  else return false;
  return true;
}

void display_tree(t_tree *tree, uint indent) {
  if (tree != NULL && tree->value != NULL) {
    if (tree->right != NULL) display_tree(tree->right, indent+1);
    for (int i = 1; i < indent; i++)
      printf("\t");
    if (indent > 0)
      printf("────────");
    printf("%s\n", tree->value);
    if (tree->left != NULL) display_tree(tree->left,indent+1);
  } 
}

