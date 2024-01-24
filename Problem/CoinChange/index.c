#include "stdio.h"
#include "string.h"

void CoinChange(int total, int coin[], int coin_length)
{
    size_t i, j;
    int minCoin[total + 1], coin_use[total + 1];
    minCoin[0] = 0, coin_use[0] = 0;

    for (i = 1; i <= total; i++)
    {
        int min = total, tempMin, tempCoin;
        for (int j = coin_length - 1; j >= 0; j--)
        {
            if (i >= coin[j])
            {
                tempMin = 1 + minCoin[i - coin[j]];
                if (tempMin < min)
                {
                    min = tempMin;
                    tempCoin = coin[j];
                }
            }
        }
        minCoin[i] = min;
        coin_use[i] = tempCoin;
    }

    int coin_amount[coin_length];
    memset(coin_amount, 0, sizeof(coin_amount));

    int length = minCoin[total];

    for (i = 0; i <= length; i++)
    {
        for (j = 0; j < coin_length; j++)
        {
            if (coin_use[total] == coin[j])
            {
                total -= coin_use[total];
                coin_amount[j] += 1;
            }
        }
    }

    for (i = 0; i < coin_length; i++)
    {
        printf("%d: %d\n", coin[i], coin_amount[i]);
    }
}

int main()
{
    int total;
    size_t coin_length;
    scanf("%d %zd", &total, &coin_length);

    int coin[coin_length];
    for (size_t i = 0; i < coin_length; i++)
    {
        scanf("%d", &coin[i]);
    }

    CoinChange(total, coin, coin_length);
}