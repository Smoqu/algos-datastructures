#include <stdio.h>


int partition(int list[], int low, int high) {
  int pivot = list[high];

  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (list[j] <= pivot) {

      i++;
    int iCopy = list[i];
    list[i] = list[j];
    list[j] = iCopy;
    }


  }

  return i;

}


void quicksort(int list[], int low, int high) {
  if (low >= 0 && high >= 0 && low < high) {
    int pivot = partition(list, low, high);
    printf("Pivot: %d\n", pivot);
    quicksort(list, low, pivot - 1);
    quicksort(list, pivot + 1, high);
  }
}


int main() {

  int list[] = {5, 6, 4, 9, 1, -56, 256, 100};
  int length = sizeof(list) / sizeof(int);
  quicksort(list, 1, length);

  for (int i = 0; i < length; i++) printf("%d\n", list[i]);

  return 0;
}
