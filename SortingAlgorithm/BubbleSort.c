// Bubble Sort
#include "stdio.h"

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j + 1] < arr[j])
            {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {5, 3, 2, 4, 6, 9, 4, 5, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}