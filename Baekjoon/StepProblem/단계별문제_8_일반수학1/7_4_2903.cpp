#include <cstdio>

int main()
{
    int Input_N,Result_Value = 1;
    scanf("%d", &Input_N);

    for (int i = 0; i < Input_N; ++i) {
        Result_Value *= 2;
    }
    Result_Value += 1;
    Result_Value *= Result_Value;
    printf("%d", Result_Value);
    return 0;
}