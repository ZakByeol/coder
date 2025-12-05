#include <stdio.h>

#define MAX_N 41

int main() {
    int number_case, input_search;

    // 상향식 ( BOTTOM_UP )
    int array_zero[MAX_N] = {1, 0};
    int array_one[MAX_N] = {0, 1};
    for (int i = 2; i < MAX_N; i++) {
        array_zero[i] = array_zero[i-1] + array_zero[i-2];
        array_one[i] = array_one[i-1] + array_one[i-2];
    }

    scanf("%d", &number_case);
    while (number_case--) {
        scanf("%d", &input_search);
        printf("%d %d\n", array_zero[input_search], array_one[input_search]);
    }

    return 0;
}