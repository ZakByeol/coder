#include <cstdio>

int main()
{
    int Input_Count,Count2=0,Result_X=1,Result_Y=1;
    scanf("%d", &Input_Count);
    Input_Count -= 1;

    while (Input_Count != 0)
    {
        // 1. 오른쪽 한 칸 이동
        Result_X += 1;
        Input_Count -= 1;
        if (Input_Count == 0) break;

        // 2. 양의 대각선 밑으로 이동
        for (int i = 0; i < 1+2*Count2; ++i) {
            Result_X -= 1;
            Result_Y += 1;

            Input_Count -= 1;
            if (Input_Count == 0) break;
        }
        if (Input_Count == 0) break;

        // 3. 행+1
        Result_Y += 1;
        Input_Count -= 1;
        if (Input_Count == 0) break;

        // 4. 양의 대각선 위로 이동
        for (int i = 0; i < 2 + 2 * Count2; ++i) {
            Result_X += 1;
            Result_Y -= 1;

            Input_Count -= 1;
            if (Input_Count == 0) break;
        }
        if (Input_Count == 0) break;

        Count2 += 1;
    }

    printf("%d/%d", Result_Y,Result_X);
    return 0;
}