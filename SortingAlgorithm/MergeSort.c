#include "stdio.h"

int Merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int i = 0, j = 0, k = 0;
    int b[left + right];

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
        int z = j;
        for (; z <= n2 - 1; z++)
        {
            b[k + z - j] = arr[z + mid + 1];
        }
        k = k + z - j;
    }
    else
    {
        int z = i;
        for (; z <= n1 - 1; z++)
        {
            b[k + z - i] = arr[z + left];
        }
        k = k + z - i;
    }
    for (int z = 0; z < k; z++)
    {
        arr[z + left] = b[z];
    }

    return 1;
}

int MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        Merge(arr, left, mid, right);
    }

    return 1;
}

int main()
{
    int arr[] = {75, 73, 78, 71, 77, 79, 78, 71, 75, 85, 84, 85, 78, 73, 86, 69, 82, 83, 73, 84, 89};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    MergeSort(arr, 0, arr_size - 1);

    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%c ", arr[i]);
    }
}