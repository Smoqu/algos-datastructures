#include <stdio.h>
#include "colors.h"
#include "format.h"

void printList(int list[], int length, int newLine) {
  for (int j = 0; j < length; j++) {
    printf(BOLDRED);
    if (j == 0) printf("[%d, ", list[j]);
    else if (j == length - 1) printf("%d]", list[j]);
    else printf("%d, ", list[j]);
    printf(RESET);
  }

  if (newLine == 1) printf("\n");

}
