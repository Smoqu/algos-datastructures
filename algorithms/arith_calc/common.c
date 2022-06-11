#include "common.h"

bool is_sign(const char s) {
  char signs[] = "+-/*^";

  if (strlen(&s) > 2) return false;

  for (int i = 0; signs[i] != '\0'; i++) {
    if (s == signs[i]) return true;
  }
  return false;
}
