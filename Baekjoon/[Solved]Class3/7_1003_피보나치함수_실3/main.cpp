#include <cstdio>
#include <cstdlib>

typedef struct
{
    int number_zero;
    int number_one;
}count;

void fibo(count* count_array, int input_value);

int main()
{
    int number_case,input_value;
    scanf("%d", &number_case);

    count* count_array = NULL;

    for (int i = 0; i < number_case; ++i) {
        // input
        scanf("%d", &input_value);
        if (input_value == 0)
        {
            printf("%d %d\n", 1, 0);
            continue;
        }
        else if (input_value == 1)
        {
            printf("%d %d\n", 0, 1);
            continue;
        }
        count_array = (count*) malloc(input_value * sizeof (count ));

        // insert fibo N= 0,1 case
        count_array[0].number_one = 0;
        count_array[0].number_zero = 1;
        count_array[1].number_one = 1;
        count_array[1].number_zero = 0;

        // next fibo ( 2~ input_value )
        fibo(count_array, input_value);

        printf("%d %d\n", count_array[input_value].number_zero, count_array[input_value].number_one);
        free(count_array);
    }
    return 0;
}

void fibo(count* count_array, int input_value)
{
    for (int j = 2; j <= input_value; ++j) {
        count_array[j].number_one = count_array[j-1].number_one + count_array[j-2].number_one;
        count_array[j].number_zero = count_array[j-1].number_zero + count_array[j-2].number_zero;
    }
}