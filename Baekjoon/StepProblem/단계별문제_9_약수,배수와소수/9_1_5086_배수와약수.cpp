#include <cstdio>

int main()
{
    while (1)
    {
        int Input_1=0,Input_2 =0;
        scanf("%d %d", &Input_1, &Input_2);
        if (Input_1 == 0 && Input_2 == 0) break;

        if (Input_2%Input_1 == 0 && Input_1<Input_2)
        {
            printf("factor\n");
            continue;
        }
        else if (Input_1%Input_2 == 0 && Input_1>Input_2)
        {
            printf("multiple\n");
            continue;
        }

        if (Input_1%Input_2 !=0 || Input_2%Input_1 != 0)
        {
            printf("neither\n");
            continue;
        }
    }
    return 0;
}