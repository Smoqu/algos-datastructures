#include <stdio.h>


int binary_search(int list[], int value, int length) {

  int start = 0;
  int end = length - 1;

  while (start <= end) {
    int middle = (int)((start + end) / 2);

    if (list[middle] == value)
      return 1;
    

    if (value > list[middle]) start = middle + 1;
    else end = middle - 1;
  }

  return 0;

}

int main() {

  int list[] = {1, 2, 4, 5, 6, 7, 8, 9, 10, 256, 500};
  int length = sizeof(list) / sizeof(int);
  int found = binary_search(list, 500, length);
  int found2 = binary_search(list, 11, length);

  printf("%d\n%d\n", found, found2);

  return 0;
}


