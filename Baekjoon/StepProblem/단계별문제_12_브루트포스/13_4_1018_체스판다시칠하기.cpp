#include <cstdio>

int main(void)
{
    char arr[50][51];
    int a, b, COUNT_0 = 3000; //COUNT_0는 초기에 아주 큰 값으로 초기화
    scanf("%d%d", &a, &b);
    for (int i = 0; i < a; i++)
        scanf("%s", arr[i]);

    int COUNT_1 = 0, COUNT_2 = 0;   //첫째 칸을 W로 할 때, B로 할 때 따로 계산하기 위함
    for (int x = 0; x < a - 7; x++) {   //x좌표와
        for (int y = 0; y < b - 7; y++) {   //y좌표가 도착점에 갈 때까지 반복

            //첫째 칸을 W로 만드는 경우
            for (int i = x; i < x + 8; i++) {
                for (int j = y; j < y + 8; j++) {
                    //합이 짝수일 때
                    if (((i - x + j - y) % 2) == 0) {
                        //해당하는 좌표가 W가 아니면
                        if (arr[i][j] != 'W')
                            COUNT_1++;    //다시 칠하기
                    }
                        //합이 홀수일 때
                    else {
                        //해당하는 좌표가 B가 아니면
                        if (arr[i][j] != 'B')
                            COUNT_1++;    //다시 칠하기
                    }
                }
            }
            //첫째 칸을 B로 만드는 경우
            for (int i = x; i < x + 8; i++) {
                for (int j = y; j < y + 8; j++) {
                    if (((i - x + j - y) % 2) == 0) {
                        if (arr[i][j] != 'B')
                            COUNT_2++;
                    }

                    else {
                        if (arr[i][j] != 'W')
                            COUNT_2++;
                    }
                }
            }
            //더 적게 칠한 횟수를 선택하고
            int Less_Num = COUNT_1 < COUNT_2 ? COUNT_1 : COUNT_2;
            if (Less_Num < COUNT_0) COUNT_0 = Less_Num;   //결과에 저장
            COUNT_1 = 0;
            COUNT_2 = 0;
        }
    }
    printf("%d", COUNT_0);

    return 0;
}