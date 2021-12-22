#include <stdio.h>
#include "../../../utils/format.h"

void selectionSort(int array[], int length) {
  for (int i = 0; i < length; i++) {
    int pivotInd = i;
    for (int j = i; j < length; j++) {
      if (array[j] < array[pivotInd]) {
        printList(array, length, 1);
        pivotInd = j; 

      } 
    }
    
    int copy = array[i];
    array[i] = array[pivotInd];
    array[pivotInd] = copy;

  }
}

int main() {

  int array[] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
  int length = sizeof(array) / sizeof(int);
  selectionSort(array, length);
  printList(array, length, 1);

  return 0;
}
