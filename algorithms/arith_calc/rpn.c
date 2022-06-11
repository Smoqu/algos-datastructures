#include <stdbool.h>
#include <string.h>
#include "ctype.h"
#include "stack.h"
#include "queue.h"
#include "common.h"


typedef struct Sign {
  char *sign;
  int precedence;
  bool left_associativity;
} t_sign;

t_sign plus = {.sign="+", .precedence=2, .left_associativity=true};
t_sign minus = {.sign="-", .precedence=2, .left_associativity=true};
t_sign divide = {.sign="/", .precedence=3, .left_associativity=true};
t_sign multiply = {.sign="*", .precedence=3, .left_associativity=true};
t_sign power = {.sign="^", .precedence=4, .left_associativity=false};

char *shunting_yard(char *exp) {
  int i = 0;
  t_queue *output = create_queue(NULL);
  t_stack *operators = create_stack(NULL);
  char *res;
  char *num = "";
  while (exp[i] != '\0') {
    if (isdigit(exp[i])) {
      while (isdigit(exp[++i]) || exp[i] == '.') {
        strncat(num, &exp[i], 1);
      }
      queue_push(output, num);
      num = "";
    } else if (is_sign(exp[i])) {
    }
    i++;
  }

  return res;
}
