#include "tree.h"
#include "stack.h"
#include "queue.h"

bool is_valid_char(const char c, const char *l) {
  bool res = true;
  for (int i = 0; l[i] != '\0'; i++) {
    res = !(c == l[i]);
  }

  return res;
}



t_tree *from_exp(char *exp) {
  int i = 0;
  int paran = 0;
  while (exp[i] != '\0') {
    if (exp[i] == '(') paran++;
    else if (exp[i] == ')') paran--;
    printf("%c", exp[i]); 
    i++;
  }
  return NULL;
}

double power(double x, int n) {
  double res = 0;
  for (int i = 1; i < n; i++) res += x * x;
  return res;
}

double evaluate(t_tree *tree) {
  double res = 0;
  if (tree != NULL && tree->value != NULL) {
    if (is_sign(*tree->value)) {
      double lv = evaluate(tree->left);
      double rv = evaluate(tree->right);
      switch (*tree->value) {
        case '+':
          res += lv + rv;
          break;
        case '-':
          res += lv - rv;
          break;
        case '*':
          res += lv * rv;
          break;
        case '/':
          res += lv / rv;
          break;
        case '^':
          res += power(lv, rv);
          break;
      }
    } else res = atof(tree->value);
  }
  return res;
}

int main() {

  return 0;
}
