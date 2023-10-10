#include "stdio.h"
#include "string.h"
#include "time.h"

void swapInt(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int Search(int arr[], int n, int mobile)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == mobile)
        {
            return i + 1;
        }
    }
}

int getMobile(int arr[], int arrow[], int n)
{
    int prev = 0;
    int mobile = 0;

    for (int i = 0; i < n; i++)
    {
        if (arrow[arr[i] - 1] == 0 && i != 0)
        {
            if (arr[i] > arr[i - 1] && arr[i] > prev)
            {
                mobile = arr[i];
                prev = mobile;
            }
        }

        if (arrow[arr[i] - 1] == 1 && i != n - 1)
        {
            if (arr[i] > arr[i + 1] && arr[i] > prev)
            {
                mobile = arr[i];
                prev = mobile;
            }
        }
    }
    if (mobile == 0 && prev == 0)
    {
        return 0;
    }
    else
    {
        return mobile;
    }
}

void printPerm(int arr[], int arrow[], int n)
{
    int mobile = getMobile(arr, arrow, n);
    int pos = Search(arr, n, mobile);

    if (arrow[arr[pos - 1] - 1] == 0)
    {
        swapInt(&arr[pos - 1], &arr[pos - 2]);
    }
    else if (arrow[arr[pos - 1] - 1] == 1)
    {
        swapInt(&arr[pos], &arr[pos - 1]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mobile)
        {
            if (arrow[arr[i] - 1] == 1)
            {
                arrow[arr[i] - 1] = 0;
            }
            else if (arrow[arr[i] - 1] == 0)
            {
                arrow[arr[i] - 1] = 1;
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%c ", arr[i] + 96);
    // }
    // printf("\n");
}

void Johnson(int n)
{
    int arr[n];
    int arrow[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        arrow[i] = 0;
    }

    for (int i = 1; i < fact(n); i++)
    {
        printPerm(arr, arrow, n);
    }
}

void Reverse(char str[], int l, int r)
{
    while (l < r)
    {
        swap(&str[l], &str[r]);
        l++;
        r--;
    }
}

void permute(char arr[], int l, int r)
{
    int i;
    if (l == r)
        // printf("%s\n", arr);
        printf("");
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((arr + l), (arr + i));
            permute(arr, l + 1, r);
            swap((arr + l), (arr + i));
        }
    }
}

void BruteForce(int n)
{
    char arr[n + 1];
    arr[0] = 'a';
    for (size_t i = 1; i < n; i++)
    {
        arr[i] = arr[i - 1] + 1;
    }
    arr[n] = '\0';
    permute(arr, 0, n - 1);
}

int main()
{
    int n;
    printf("Enter the number :");
    scanf("%d", &n);

    clock_t start_time, end_time;
    double cpu_time_used1, cpu_time_used2;

    start_time = clock();
    Johnson(n);
    end_time = clock();

    cpu_time_used1 = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    start_time = clock();
    BruteForce(n);
    end_time = clock();

    cpu_time_used2 = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Johnson time: %lf\n", cpu_time_used1);
    printf("Brute Force time: %lf\n", cpu_time_used2);

    return 0;
}
