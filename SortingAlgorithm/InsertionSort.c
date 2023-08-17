// Insertion Sort
#include "stdio.h"

int main()
{
    int arr[10] = {5, 3, 2, 4, 6, 9, 4, 5, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < n; i++)
    {
        int v = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > v)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = v;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d \n", arr[i]);
    }
}