#include <stdio.h>


int partition(int list[], int low, int high) {
  int pivot = list[high];

  int i = low-1;

  for (int j = low; j < high; j++) {
    if (list[j] <= pivot) {

      i++;

      int iCopy = list[i];
      list[i] = list[j];
      list[j] = iCopy;
    }


  }

  int i1Copy = list[i+1];
  list[i+1] = list[high];
  list[high] = i1Copy;

  return i+1;

}


void quicksort(int list[], int low, int high) {
  if (high == 1) return;

  if (low < high) {
    int pivot = partition(list, low, high);
    quicksort(list, low, pivot - 1);
    quicksort(list, pivot + 1, high);
  }
}


int main() {

  int list[] = {5, 6, 4, 9, 1, -56, 256, 100};
  int length = sizeof(list) / sizeof(int) - 1;
  quicksort(list, 0, length);

  for (int i = 0; i < length+1; i++) printf("Value: %d\n", list[i]);

  return 0;
}
