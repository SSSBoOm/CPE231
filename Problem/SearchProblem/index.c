#include "stdio.h"

int binarySearch(int arr[], int size, int search)
{
    int l = 0, r = size - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (arr[m] == search)
            return m;

        if (arr[m] < search)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

int main()
{
    size_t n, k, i;
    scanf("%zd", &n);
    scanf("%zd", &k);

    int L[n], Search[k];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &L[i]);
    }
    for (i = 0; i < k; i++)
    {
        scanf("%d", &Search[i]);
    }

    for (i = 0; i < k; i++)
    {
        printf("%d\n", binarySearch(L, n, Search[i]));
    }
}