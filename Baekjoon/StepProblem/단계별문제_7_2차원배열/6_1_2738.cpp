/*#include <cstdio>

int main()
{
    int N,M;
    int INSERT_1,INSERT_2,INSERT_3;

    scanf("%d %d", &N,&M);
    int Array[N][M];

    // 행렬 A를 받음
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d", &INSERT_1,&INSERT_2,&INSERT_3);
        Array[i][0] += INSERT_1;
        Array[i][1] += INSERT_2;
        Array[i][2] += INSERT_3;
    }

    // 행렬 B를 받음
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d", &INSERT_1,&INSERT_2,&INSERT_3);
        Array[i][0] += INSERT_1;
        Array[i][1] += INSERT_2;
        Array[i][2] += INSERT_3;
    }

    for (int i = 0; i < N; ++i) {
        if (i == N-1)
        {
            printf("%d %d %d", Array[i][0] , Array[i][1] , Array[i][2]);
            break;
        }
        printf("%d %d %d\n", Array[i][0] , Array[i][1] , Array[i][2]);
    }
    return 0;
} // 이거 왜 안됨? - 열이 3개일때만 유효한 코드임*/

#include <cstdio>

int main()
{
    int N,M;

    scanf("%d %d", &N,&M);
    int A_Array[N][M];
    int B_Array[N][M];

    // 행렬 A를 받음
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &A_Array[i][j]);
        }
    }

    // 행렬 B를 받음
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &B_Array[i][j]);
        }
    }

    // 행렬의 합을 출력
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%d ", A_Array[i][j] + B_Array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
