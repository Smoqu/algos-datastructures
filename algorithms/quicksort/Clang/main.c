#include <stdio.h>
#include "../../../utils/colors.h"
#include "../../../utils/format.h"



int partition(int list[], int low, int high) {
  int pivot = list[high];
  int i = low-1;
  printf("Pivot: %d, i: %d\n", pivot, i);
  printf("Array: ");
  printList(list, high+1, 0);


  for (int j = low; j < high; j++) {
    if (list[j] <= pivot) {

      i++;

      printf("\n ==> i Evo: %d (j: %d) ", i, j);
      printf(GREEN);
      printf("(Meaning: %d <= %d | %d (j) <= %d (i))", list[j], pivot, list[j], list[i]);
      printf(RESET);

      printf("\n\t (Not swapped) ==> ");
      printList(list, high+1, 1);

      int iCopy = list[i];
      list[i] = list[j];
      list[j] = iCopy;

      printf("\n\t (Swapped)     ==> ");
      printList(list, high+1, 1);
    }


  }

  printf("\n\t (Swap i+1: %d and high: %d)", i+1, high);
  int i1Copy = list[i+1];
  list[i+1] = list[high];
  list[high] = i1Copy;

  printf("\nNew array: ");
  printList(list, high+1, 1);

  return i+1;

}


void quicksort(int list[], int low, int high) {

  if (low < high) {
    printf("=============================\n");
    printf("Low: %d; High: %d\n", low, high);
    int pivot = partition(list, low, high);
    printf("QS Pivot Index: %d, Value: %d\n", pivot, list[pivot]);
    printf("=============================\n");
    quicksort(list, low, pivot - 1);
    quicksort(list, pivot + 1, high);
  }
}


int main() {

  /*int list[] = {5, 6, 4, 9, 1, -56, 256, 100};*/
  int list[] = {104, 244, -246, 240, 120, -255, -55, -200, 9, -117, 150, -216, -205, -54, 201, -136, -148, 231}; 
  int length = sizeof(list) / sizeof(int);
  printf("Base Array: ");
  printList(list, length, 1);
  printf("\n");
  quicksort(list, 0, length-1);

  printf("Final: ");
  printList(list, length, 0);

  return 0;
}
