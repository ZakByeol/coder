#include <cstdio>

int main()
{
    while (1)
    {
        int InputValue;
        int SumValue=0;
        scanf("%d", &InputValue);

        if (InputValue == -1) break;

        for (int i = 1; i < InputValue; ++i) {
            if (InputValue%i == 0) SumValue += i;
        }

        if (SumValue == InputValue)
        {
            printf("%d = 1", InputValue);
            for (int i = 2; i < InputValue; ++i) {
                if (InputValue%i == 0) printf(" + %d", i);
            }
            printf("\n");
        }
        else
        {
            printf("%d is NOT perfect.\n", InputValue);
        }
    }
    return 0;
}
