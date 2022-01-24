#include <stdio.h>

int binary_search(int list[], int value, int length)
{

  int start = 0;
  int end = length - 1;

  while (start <= end)
  {
    int middle = (int)((start + end) / 2);

    if (list[middle] == value)
      return 1;

    if (value > list[middle])
      start = middle + 1;
    else
      end = middle - 1;
  }

  return 0;
}

int binary_search_r(int list[], int value, int start, int end)
{
  if (end - start == 1)
    return 0;

  int middle = (int)((start + end) / 2);

  if (value == list[middle])
    return 1;
  else if (value < list[middle])
    return binary_search_r(list, value, start, middle);
  else
    return binary_search_r(list, value, middle, end);
}

int main()
{

  int list[] = {1, 2, 4, 5, 6, 7, 8, 9, 10, 256, 500};
  int length = sizeof(list) / sizeof(int);
  int found = binary_search_r(list, 7, 0, length);
  printf("%d\n", found);
  found = binary_search_r(list, 525, 0, length);
  printf("%d\n", found);

  return 0;
}
