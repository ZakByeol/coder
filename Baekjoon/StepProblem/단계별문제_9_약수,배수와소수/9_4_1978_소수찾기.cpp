#include <cstdio>

int main()
{
    int NumValue;
    int INPUT_VALUE,COUNT_VALUE=0;

    scanf("%d", &NumValue);
    for (int i = 0; i < NumValue; ++i) {
        scanf("%d", &INPUT_VALUE);
        for (int j = 2; j <=INPUT_VALUE; ++j) {
            if (j == INPUT_VALUE) COUNT_VALUE++;
            if (INPUT_VALUE%j == 0) break; // 소수가 아님
        }
    }
    printf("%d",COUNT_VALUE);
    return 0;
}