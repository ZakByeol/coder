#include <cstdio>

int main()
{
    int Array[9][9];
    int Max_xLine = 0,Max_yLine = 0,Max_Value = 0;

    // 9x9 행렬 입력 받기
    for (int i = 0; i < 9; ++i) {
        scanf("%d %d %d %d %d %d %d %d %d", &Array[i][0], &Array[i][1], &Array[i][2],
              &Array[i][3],&Array[i][4],&Array[i][5],&Array[i][6],&Array[i][7],&Array[i][8]);
    }

    // 9x9 행렬의 요소들 중에서 최댓값 구하기
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (Array[i][j] >= Max_Value)
            {
                Max_Value = Array[i][j];
                Max_xLine = i;
                Max_yLine = j;
            }
        }
    }

    // 결과 출력
    printf("%d\n", Max_Value);
    printf("%d %d", Max_xLine+1, Max_yLine+1); // 1 추가해야지

    return 0;
}