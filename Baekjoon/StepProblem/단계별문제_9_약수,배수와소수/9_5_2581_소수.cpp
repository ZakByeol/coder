#include <cstdio>

int main()
{
    int INPUT_M,INPUT_N;
    int SUM_DECIMAL = 0;
    int MIN_DECIMAL_VALUE =0;

    while (1)
    {
        scanf("%d", &INPUT_M);
        if (INPUT_M <= 10000 && INPUT_M > 0) break;
        else printf("재입력 :\n");
    }
    while (1)
    {
        scanf("%d", &INPUT_N);
        if (INPUT_N <= 10000 && INPUT_N > 0 && INPUT_N >= INPUT_M) break;
        else printf("재입력 :\n");
    }

    for (int i = INPUT_M; i <= INPUT_N; ++i)
    {
        for (int j = 2; j <= i; ++j) {
            if (j == i)
            {
                if (MIN_DECIMAL_VALUE == 0) MIN_DECIMAL_VALUE = i;
                SUM_DECIMAL += i;
            }
            if (i%j == 0) break;
        }


    }

    if (SUM_DECIMAL == 0) printf("-1");
    else
    {
        printf("%d\n", SUM_DECIMAL);
        printf("%d", MIN_DECIMAL_VALUE);
    }

    return 0;
}