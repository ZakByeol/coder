#include <cstdio>

int main()
{
    int INPUT_VALUE,VALUE_I =2;
    scanf("%d", &INPUT_VALUE);

    while (1)
    {

        if (INPUT_VALUE%VALUE_I == 0)
        {
            INPUT_VALUE /= VALUE_I;
            printf("%d\n", VALUE_I);
        }
        else VALUE_I++;

        if (INPUT_VALUE == 1) break;
    }

    return 0;
}