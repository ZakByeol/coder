/*#include <cstdio>

int main()
{
    int A,B,C,D,E,F;
    scanf("%d %d %d %d %d %d", &A,&B,&C,&D,&E,&F);
    int RESULT_Y = ((C-(A*F)/D)/(B-(A*E)/D));
    int RESULT_X = ((-B*RESULT_Y+C)/A);

    printf("%d %d", RESULT_X, RESULT_Y);
    return 0;

    // x와 y가 각각 -999 ~ 999 사이의 정수일때, 출력이 허용됨
}*/

#include <cstdio>

int main()
{
    int A,B,C,D,E,F;
    scanf("%d %d %d %d %d %d", &A,&B,&C,&D,&E,&F);

    // x와 y가 각각 -999 ~ 999 사이의 정수일때, 출력이 허용되도록 조건문을 통해서 코드를 짬
    for (int i = -999; i <= 999; ++i)
    {
        for (int j = -999; j <= 999; ++j) {
            if (A * i + B * j == C && D * i + E * j == F) {
                printf("%d %d", i, j);
                break;
            }
        }
    }
    return 0;
}




