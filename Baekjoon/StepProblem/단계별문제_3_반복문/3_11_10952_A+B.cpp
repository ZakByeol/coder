#include <cstdio>

int main()
{
    int INPUT_A,INPUT_B;
    while (1)
    {
        scanf("%d %d", &INPUT_A, &INPUT_B);
        if (INPUT_A == 0 && INPUT_B == 0) break;
        printf("%d\n", INPUT_A+INPUT_B);
    }
    return 0;
}