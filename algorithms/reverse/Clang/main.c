#include <stdio.h>
#include "../../../utils/format.h"

void reverse(int list[], int length) {
  int i, j;
  i = 0;
  j = length - 1;

  while (i <= j) {
    int copy = list[i];
    list[i] = list[j];
    list[j] = copy;

    i++;
    j--;
  }
}

int main() {
  int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int length = sizeof(list) / sizeof(int);

  printList(list, length, 1);
  reverse(list, length);
  printList(list, length, 1);

  return 0;
}
