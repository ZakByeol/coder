#include <cstdio>
#include <cstdlib>

typedef struct
{
    int price;
    int number_optimal;
}coin;

int count = 0;
int greedy_Feasibility(int coin_price, int remain_sum);

int main()
{
    // input - type,sum
    int number_type,sum_price;
    scanf("%d %d", &number_type, &sum_price);

    // malloc
    coin* coin_list = NULL;
    coin_list = (coin*) malloc(number_type * sizeof (coin));

    // input - coin price
    for (int i = 0; i < number_type; ++i)
    {
        scanf(" %d", &coin_list[i].price);
    }

    // greedy
    for (int i = number_type-1; i >= 0; --i) {
        if (sum_price == 0)
            break;

        count += greedy_Feasibility(coin_list[i].price, sum_price);
        sum_price -= coin_list[i].price * greedy_Feasibility(coin_list[i].price, sum_price);
    }

    printf("%d", count);
    free(coin_list);
    return 0;
}

int greedy_Feasibility(int coin_price, int remain_sum)
{
    int try_count = 0;
    while (true)
    {
        if (coin_price * try_count <= remain_sum)
            try_count += 1;
        else
        {
            try_count -= 1;
            break;
        }
    }

    return try_count;
}