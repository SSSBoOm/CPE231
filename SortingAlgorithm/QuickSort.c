#include "stdio.h"

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int left, int right)
{
    int p = arr[left];
    int i = left + 1;
    int j = right;

    while (i <= j)
    {
        while (arr[i] < p)
            i++;

        while (arr[j] > p)
            j--;

        swap(&arr[i], &arr[j]);
    }
    swap(&arr[i], &arr[j]);
    swap(&arr[left], &arr[j]);

    return j;
}

int quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int s = partition(arr, left, right);

        quickSort(arr, left, s - 1);
        quickSort(arr, s + 1, right);
    }

    return 1;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[10] = {3, 4, 2, 8, 6, -9, 7, 5, -5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, 10 - 1);

    printArray(arr, n);
}