#include<stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int result_array[1000001];

    result_array[1] = 0;
    result_array[2] = 1;
    result_array[3] = 1;


    for (int i = 4; i <= N; i++)
    {
        result_array[i] = result_array[i - 1] + 1;

        if (i % 2 == 0)
            if (result_array[i] > result_array[i/2] + 1)
                result_array[i] = result_array[i/2] + 1;
        if (i % 3 == 0)
            if (result_array[i] > result_array[i/3] + 1)
                result_array[i] = result_array[i/3] + 1;

    }

    printf("%d", result_array[N]);
}