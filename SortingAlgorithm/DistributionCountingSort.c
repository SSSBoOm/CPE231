#include "stdio.h"
#include "stdlib.h"

int *DistributionCountingSort(int arr[], int l, int u, int n)
{
    int d[u - l + 1];
    int *s = malloc(sizeof(int) * n);
    for (int j = 0; j < u - l + 1; j++)
        d[j] = 0;
    for (int i = 0; i < n; i++)
    {
        int v = arr[i] - l;
        d[v] = d[v] + 1;
    }
    for (int j = 1; j < u - l + 1; j++)
    {
        d[j] = d[j - 1] + d[j];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int j = arr[i] - l;
        s[d[j] - 1] = arr[i];
        d[j] = d[j] - 1;
    }
    printf("\n");

    return s;
}

int main()
{
    int arr[6] = {13, 11, 12, 13, 12, 12};

    int *arr2 = DistributionCountingSort(arr, 11, 13, 6);

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr2[i]);
    }
}