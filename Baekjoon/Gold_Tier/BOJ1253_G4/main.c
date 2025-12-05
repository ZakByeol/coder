#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// 비교 함수 (qsort용)
int compare(const void *a, const void *b) {
    int32_t num1 = *(int32_t *)a;
    int32_t num2 = *(int32_t *)b;

    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int main() {
    int N;
    // N의 범위는 2000 이하
    int32_t A[2000]; 
    int32_t TemporaryValue = 0; // 임시적으로 값을 저장받는 변수
    int count = 0;


    // 입력 받기
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // 배열 정렬 (투 포인터 사용을 위해 필수)
    qsort(A, N, sizeof(int32_t), compare);

    // 각 수 A[i]가 '좋은 수'인지 확인
    for (int i = 0; i < N; i++) {
        int32_t find = A[i];

        int32_t StartRange = 0;
        int32_t EndRange = N-1;

        while (StartRange < EndRange)
        {
            int32_t SumValue = A[StartRange] + A[EndRange]; // 

            // Good Value 인 확률이 높은 경우들
            if (SumValue == find)
            {
                // 합과 판별값이 같은 경우지만, 그 두 수가 같은 인덱스에 위치 하지 않을때
                // = 판별값이 Good Value 일때
                if (StartRange != i && EndRange != i)
                {
                    count ++;
                    break;
                }

                // "" 같은 인덱스에 위치 할때, 범위(=투포인터) 수정
                else if (StartRange == i) {
                    StartRange++;
                }
                else if (EndRange == i) {
                    EndRange --;
                }
            }

            // Good Value가 되기에는 합이 작은 경우, 시작 범위를 앞당겨서 합을 간접적으로 늘림(정렬된 배열이기에 가능함)
            else if (SumValue < find) {
                StartRange++;
            }

            // Good Value가 되기에는 합이 큰 경우
            else
            {
                EndRange--;
            }

        }
    }

    // 결과 출력
    printf("%d\n", count);

    return 0;
}
