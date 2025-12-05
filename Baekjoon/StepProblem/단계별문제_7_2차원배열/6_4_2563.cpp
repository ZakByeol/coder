#include <cstdio>

int main()
{
    // 100x100 배열 생성해서, 중복 횟수 스택을 쌓는 식으로 하면 될 듯?
    int WhitePaper_100[100][100] = { 0,};
    int NumSquare,Pointx_Square,Pointy_Square,CountNum = 0;
    scanf("%d", &NumSquare);

    for (int i = 0; i < NumSquare; ++i) {
        scanf("%d %d", &Pointx_Square, &Pointy_Square);

        // 색종이의 넓이만큼 제외시키기
        for (int j = Pointy_Square; j < Pointy_Square+10; ++j) { // 행 반복문
            for (int k = Pointx_Square; k < Pointx_Square+10; ++k) {
                if (WhitePaper_100[j][k] == 0) WhitePaper_100[j][k] = 1;
                else if(WhitePaper_100[j][k] == 1) continue;
            }
        }
    }

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (WhitePaper_100[i][j] == 1)
            {
                CountNum += 1;
            }
            else continue;
        }
    }

    printf("%d", CountNum);

    return 0;
}