#include <stdio.h>

int main()
{
    double num;
    scanf("%lf", &num);

    unsigned long long n = *(unsigned long long *)&num;
    for (int i = 63; i >= 0; i--)
    {
        printf("%llu", ((n >> i) & 1));
        if (i == 63 || i == 52)
            printf(" ");
    }
    printf("\n");

    return 0;
}