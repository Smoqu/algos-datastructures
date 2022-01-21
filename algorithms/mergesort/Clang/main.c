#include <stdio.h>
#include "../../../utils/format.h"

void merge(int left[], int ll, int right[], int lr, int result[])
{
    int l, r, x;
    l = r = x = 0;

    while (l < ll && r < lr)
    {
        if (left[l] < right[r])
        {
            result[x] = left[l];
            l++;
        }
        else
        {
            result[x] = right[r];
            r++;
        }
        x++;
    }

    for (int i = l; i < ll; i++)
    {
        result[x] = left[l];
        l++;
        x++;
    }

    for (int i = r; r < lr; i++)
    {
        result[x] = right[r];
        r++;
        x++;
    }
}

void mergesort(int array[], int length)
{
    printList(array, length, 1);
    int middle = (int)(length / 2);
    if (length == 1)
        return;

    int leftLen = middle;
    int rightLen = length - middle;

    int l[leftLen];
    int r[rightLen];

    for (int i = 0; i < leftLen; i++)
        l[i] = array[i];

    int j = middle;
    for (int i = 0; i < rightLen; i++)
    {
        r[i] = array[j];
        j++;
    }

    mergesort(l, leftLen);
    mergesort(r, rightLen);

    merge(l, leftLen, r, rightLen, array);
    printList(array, length, 1);
}

int main()
{

    int array[] = {-9, 8, 5, 2, -1, 9, 7};
    int length = sizeof(array) / sizeof(int);

    mergesort(array, length);
    printList(array, length, 1);

    return 1;
}