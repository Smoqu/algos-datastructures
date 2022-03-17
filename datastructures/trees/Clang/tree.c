#include "tree.h"

bin_tree_t *init_tree(int root) {
  bin_tree_t *tree = malloc(sizeof(bin_tree_t));
  tree->value = root;
  tree->left = malloc(sizeof(bin_tree_t));
  tree->right = malloc(sizeof(bin_tree_t)); 
  tree->init = 1;
  tree->right->init = 0;
  tree->left->init = 0;

  return tree;
}


void t_insert(bin_tree_t *tree, int value) {
  
  if (!tree->init) {
    tree->value = value;
    tree->left = malloc(sizeof(bin_tree_t));
    tree->right = malloc(sizeof(bin_tree_t));
    tree->init = 1;
    tree->right->init = 0;
    tree->left->init = 0;
    return;
  }

  if (tree->value < value) {
    t_insert(tree->right, value);
  } else if (tree->value > value) {
    t_insert(tree->left, value);
  }
}

void indent(int level) {
  for (int i = 0; i < level; i++) {
    printf("\t");
  }
} 


void dump(const bin_tree_t *tree, int level) {
  if (!tree->init) {
    indent(level);
    printf("Empty\n");
    return;
  }

  indent(level);
  printf("root: %d\n", tree->value);
  indent(level);
  printf("left:\n");
  dump(tree->left, level+1);
  indent(level);
  printf("right:\n");
  dump(tree->right, level+1);
}

void t_dump(const bin_tree_t *tree) {
  dump(tree, 0);
}

int t_seek(const bin_tree_t *tree, int value) {

  if (!tree->init) return -1;

  if (tree->value < value) {
    return t_seek(tree->right, value);
  } else if (tree->value > value){
    return t_seek(tree->left, value);
  } 
  
  return 1;
}

