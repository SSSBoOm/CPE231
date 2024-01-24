#include "stdio.h"
#include "time.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int LomutoPartition(int arr[], int l, int r)
{
    int p = arr[l];
    int s = l;
    for (int i = l + 1; i <= r; i++)
    {
        if (arr[i] < p)
        {
            s++;
            swap(&arr[s], &arr[i]);
        }
    }
    swap(&arr[l], &arr[s]);
    return s;
}

int hoarePartition(int arr[], int l, int r)
{
    int p = arr[l];
    int i = l;
    int j = r + 1;

    while (i < j)
    {
        do
        {
            i++;
        } while (i < r && arr[i] <= p);

        do
        {
            j--;
        } while (j >= l && arr[j] > p);

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[l], &arr[j]);
    return j;

    return j;
}

int QuickSelectLomutoPartition(int arr[], int l, int r, int k)
{
    int s = LomutoPartition(arr, l, r);
    if (s == k - 1)
        return arr[s];
    else if (s > k - 1)
        return QuickSelectLomutoPartition(arr, l, s - 1, k);
    else
        return QuickSelectLomutoPartition(arr, s + 1, r, k);
}

int QuickSelecthoarePartition(int arr[], int l, int r, int k)
{
    int s = hoarePartition(arr, l, r);
    if (s == k - 1)
        return arr[s];
    else if (s > k - 1)
        return QuickSelecthoarePartition(arr, l, s - 1, k);
    else
        return QuickSelecthoarePartition(arr, s + 1, r, k);
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1,6,3,4,5,2,7,8,9,10};
    
    int result1, result2;
    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();
    result1 = QuickSelectLomutoPartition(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, 12334);
    end_time = clock();

    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("time (%lf) lomuto : %d\n", cpu_time_used, result1);

    start_time = clock();
    result2 = QuickSelecthoarePartition(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, 12334);
    end_time = clock();

    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("time (%lf) hoare : %d\n", cpu_time_used, result2);
}