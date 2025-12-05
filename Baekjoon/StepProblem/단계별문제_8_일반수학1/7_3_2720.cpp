#include <cstdio>

int main()
{
    int NumTry,Input_Left;
    int NumQuarter = 0, NumDime = 0, NumNickel = 0, NumPenny = 0;
    scanf("%d", &NumTry);

    for (int i = 0; i < NumTry; ++i) {
        scanf("%d", &Input_Left);
        NumQuarter = Input_Left/25;
        Input_Left -= NumQuarter*25;

        NumDime = Input_Left/10;
        Input_Left -= NumDime*10;

        NumNickel = Input_Left/5;
        Input_Left -= NumNickel*5;

        NumPenny = Input_Left;

        printf("%d %d %d %d\n", NumQuarter, NumDime, NumNickel, NumPenny);
    }
    return 0;
}