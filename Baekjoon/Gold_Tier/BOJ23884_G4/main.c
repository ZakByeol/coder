
// 선택정렬의 시간복잡도는 O(NumElement^2), 따라서, N=500,000 이면 1초는 훨신 넘어간다. (10^8 '=. 1초)
// 그래서 오름차순된 배열을 퀵정렬로 빠르게 만들어둔다. 해당 정렬된 배열을 매핑하여 빠르게 답을 도출 할 것이다.
// 배열의 요소 개수의 최댓값은 50*10^4개 이므로, 따라서 <1초 이기에, 

#include <stdio.h>
#include <stdlib.h> //malloc, qsort, bsearch

// qsort용 함수
int compare(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y); // 오름차순
}

int main(void)
{
    int NumElement, CountChange;
    scanf("%d %d", &NumElement, &CountChange);

    int *A = malloc(NumElement * sizeof(int));
    int *B = malloc(NumElement * sizeof(int));
    for (int i = 0; i < NumElement; i++)
    { // 비교용으로 B배열도 만들어준다.
        scanf("%d", &A[i]);
        B[i] = A[i];
    }

    // 인덱스 찾는 용으로 B배열을 오름차순 정렬해준다.
    qsort(B, NumElement, sizeof(int), compare);

    // Mapping - 
    int *pos = malloc(NumElement * sizeof(int));
    for (int i = 0; i < NumElement; i++)
    {
        // bsearch는 B 배열 안에서 A[i] 값을 찾아서, 그 주소를 반환한다.
        int *p = bsearch(&A[i], B, NumElement, sizeof(int), compare);

        // 현주소 - 첫주소 = 현 인덱스(원소 간 거리)
        int ValueIndex = (int)(p - B);

        // Index : 해당 값이 위치하는 B 배열(정렬된)의 인덱스, Value : 해당 값이 위치하는 A 배열의 인덱스
        pos[ValueIndex] = i;
    }

    int cnt = 0;
    for (int i = NumElement - 1; i >= 0; i--)
    {
        int need = B[i];      // i에 있어야 하는 값
        int current = pos[i]; // i에 있어야 하는 값의 현재 인덱스

        // 정렬이 되어 있지 않은 경우, current(pos[i]) == i 는 정렬이 되었다는 뜻이 됨
        if (current != i)
        {
            int x = A[i]; // 현재 값(i에 있던 값)
            int *px = bsearch(&x, B, NumElement, sizeof(int), compare);
            int x_ValueIndex = (int)(px - B); // 현재 값이 정렬 후 위치해야할 인덱스

            // 원소 스왑
            A[current] = x;
            A[i] = need;

            // 위치 갱신. A[i]는 정렬되었고, A[current]가 원래 있던 값으로 바뀐다.
            pos[i] = i;            // 전부 pos[i] = i가 되면 정렬된 것이다.
            pos[x_ValueIndex] = current; // B[x_ValueIndex]가 현재 A[current]에 있다.

            cnt++;
            if (cnt == CountChange)
            {
                for (int i = 0; i < NumElement; i++)
                { // 처음만 빼고 공백 출력
                    if (i != 0)
                        putchar(' ');
                    printf("%d", A[i]);
                }

                free(A);
                free(B);
                free(pos);

                return 0;
            }
        }
    }

    printf("-1");

    free(A);
    free(B);
    free(pos);

    return 0;
}