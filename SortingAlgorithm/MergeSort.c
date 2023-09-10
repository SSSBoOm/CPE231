#include "stdio.h"
#include "stdlib.h"

int merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int i = 0, j = 0, k = 0;
    int *b = calloc(n1 + n2, sizeof(int));

    while (i < n1 && j < n2)
    {
        if (arr[left + i] < arr[mid + 1 + j])
        {
            b[k] = arr[left + i];
            i++;
        }
        else
        {
            b[k] = arr[mid + 1 + j];
            j++;
        }
        k++;
    }

    if (i == n1)
    {
        for (int z = j; z < n2; z++)
        {
            b[k] = arr[mid + z + 1];
            k++;
        }
    }
    else
    {
        for (int z = i; z < n1; z++)
        {
            b[k] = arr[left + z];
            k++;
        }
    }

    for (int z = 0; z < (n1 + n2); z++)
    {
        arr[left + z] = b[z];
    }

    return 1;
}

int mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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
    int arr[] = {75, 73, 78, 71, 77, 79, 78, 71, 75, 85, 84, 85, 78, 73, 86, 69, 82, 83, 73, 84, 89};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    printArray(arr, n);
}