#include <stdio.h>

int *bubblesort(int length, int array[]) {
  int k = length;

  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < k - 1; ++j) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }

  for (int i = 0; i < length; ++i) printf("%d\n", array[i]);

  return array;

}

int main() {
  
  int array[12] = {8, 7, 5, 6, 9, 8, 9, 7, 256, 14, 21, -2};
  int length = sizeof(array) / sizeof(int);
  bubblesort(length, array);

  return 0;
}


