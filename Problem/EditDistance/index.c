#include "stdio.h"
#include "string.h"

int min(int a, int b)
{
    return a <= b ? a : b;
}

int distance(char str1[], char str2[], int lengthstr1, int lengthstr2)
{
    int dist[lengthstr1][lengthstr2];
    dist[0][0] = 0;

    size_t i, j;
    for (i = 1; i < lengthstr2; i++)
    {
        dist[0][i] = i;
        dist[1][i] = i - 1;
    }

    dist[1][0] = 1;

    for (i = 1; i < lengthstr1; i++)
    {
        dist[i][0] = i;
        for (j = 1; j < lengthstr2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dist[i][j] = dist[i - 1][j - 1];
            else
                dist[i][j] = min(min(dist[i][j - 1], dist[i - 1][j]), dist[i - 1][j - 1]) + 1;
        }
    }

    return dist[lengthstr1 - 1][lengthstr2 - 1];
}

int main()
{
    char str1[101], str2[101];
    scanf("%s", str1);
    scanf("%s", str2);

    printf("%d\n", distance(str1, str2, strlen(str1) + 1, strlen(str2) + 1));
}