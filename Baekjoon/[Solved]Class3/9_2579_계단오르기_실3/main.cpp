#include <stdio.h>
#include <stdlib.h>

int getvalue_max(int a, int b);

int main() {

    int max_stairs;
    int* dynamic_pointer = NULL;
    int* stair_pointer = NULL;

    scanf("%d", &max_stairs);
    dynamic_pointer = (int*) malloc((max_stairs+1) * sizeof (int));
    stair_pointer = (int*) malloc((max_stairs+1) * sizeof (int));
    for (int i = 1; i <= max_stairs; i++) {
        scanf("%d", stair_pointer+i);
    }

    // allocate Initial value
    dynamic_pointer[0] = 0;
    dynamic_pointer[1] = stair_pointer[1];
    dynamic_pointer[2] = stair_pointer[1] + stair_pointer[2];

    // allocate max_value
    // 상향식 Botton-up
    for (int i = 3; i <= max_stairs; i++) {
        dynamic_pointer[i] = stair_pointer[i] + getvalue_max(dynamic_pointer[i - 2], stair_pointer[i - 1] + dynamic_pointer[i - 3]);
    }

    // print result
    printf("%d\n", dynamic_pointer[max_stairs]);

    free(dynamic_pointer);
    free(stair_pointer);
    return 0;
}

int getvalue_max(int a, int b)
{
    return a > b? a:b;
}