#include <stdio.h>
#include "../../../utils/format.h"


void insertion_sort(int list[], int length) {

  for (int i = 0; i < length; i++) {
    int actual = list[i];
    for (int j = i-1; j >= 0 && list[j] > actual; j--) {
      printf("j %d i %d\n", j, i);
      printf("List: ");
      printList(list, length, 1);
      if (actual < list[j]) {
        list[j+1] = list[j];
        list[j] = actual; 
      }
    }

  }

}


int main() {

  int list[] = {6, 5, 3, 1, 8, 7, 2, 4};
  int length = sizeof(list) / sizeof(int);

  printList(list, length, 1);

  insertion_sort(list, length);
  printList(list, length, 1);

  return 0;
}
