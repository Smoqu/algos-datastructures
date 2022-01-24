#include <stdio.h>
#include <stdlib.h>

typedef struct bin_tree_t {
  int value;
  struct bin_tree_t *left;
  struct bin_tree_t *right;
  int init;
} bin_tree_t;


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


void insert(bin_tree_t *tree, int value) {
  
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
    insert(tree->right, value);
  } else if (tree->value > value) {
    insert(tree->left, value);
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

int seek(const bin_tree_t *tree, int value) {

  if (!tree->init) return -1;

  if (tree->value < value) {
    return seek(tree->right, value);
  } else if (tree->value > value){
    return seek(tree->left, value);
  } 
  
  return 1;
}


int main() {

  bin_tree_t *tree = init_tree(2);

  insert(tree, 1);
  insert(tree, 5);
  insert(tree, 3);
  insert(tree, -2);


  dump(tree, 0);

  int found = seek(tree, 5);
  printf("Found: %d\n", found);
  found = seek(tree, 10);
  printf("Found: %d\n", found);


  return 0;
}
