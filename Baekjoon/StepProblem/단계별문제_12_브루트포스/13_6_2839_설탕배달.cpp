#include <cstdio>

int main()
{
    int Input_kg;
    int Num_5kg = 0, Num_3kg = 0;
    scanf("%d", &Input_kg);
    while (1)
    {
        if ((Input_kg / 5) > 0)
        {
            Num_5kg++;
            Input_kg-=5;
        }
        if ((Input_kg/5) == 0 )
        {

        }
    }
    return 0;
}