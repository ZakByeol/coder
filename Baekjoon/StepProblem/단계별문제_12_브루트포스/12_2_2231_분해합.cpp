#include <cstdio>

int main()
{
    int INPUT_VALUE,SUM_VALUE=0;
    int RESULT_VALUE=0;

    scanf("%d", &INPUT_VALUE);

    for (int i = 1; i < INPUT_VALUE; ++i) {
        SUM_VALUE = 0;
        int STORAGE_I = i;
        SUM_VALUE += STORAGE_I;

        // 자리수를 SUM_VALUE에 대입
        for (int digits = 1000000; digits >= 1; digits/=10) {
            SUM_VALUE += STORAGE_I/digits;
            STORAGE_I %= digits;
        }

        /*
        검사용
        printf("%d : %d\n", i, SUM_VALUE);
         */

        // SUM_VALUE가 INPUT_VALUE와 같으면 RESULT_VALUE에 i를 할당하고, break
        if (SUM_VALUE == INPUT_VALUE)
        {
            RESULT_VALUE = i;
            break;
        }

    }

    printf("%d", RESULT_VALUE);
    return 0;
}