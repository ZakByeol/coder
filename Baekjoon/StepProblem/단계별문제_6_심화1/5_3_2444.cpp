// 첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.
/* (5) 입력
 * 1. 4/1   띄워쓰기는 중간에 수렴할 때, 1씩 감소 추세
 * 2. 3/3   별의 갯수는 중간에 수렴할 때, 2씩 증가 추세
 * 3. 2/5
 * 4. 1/7
 * 5. 0/9
 * 6. 1/7
 * ;;
 */

/* 결과
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/
#include <stdio.h>
#include <math.h>

int main()
{
    int input_value;
    scanf("%d", &input_value);
    // 줄바꿈 반복문 i는 줄 번호
    for (int i = 0; i < 2*input_value-1; ++i)
    {
        // 중간 지점 확인 조건문
        if(i>((int)ceil(2*input_value-1)/2))
        {
            // 띄워 쓰기 # count = 줄 번호 - 중간 번호(중간은 해당 안돼서 반올림 필요X)
            int count = i - (2*input_value-1)/2;
            for (int j = 0; j < count; ++j) {
                printf(" ");
            }
            // 별 작성 # 중간 후 부터는 중간의 별 개수에서 2씩 감소하는 추세임
            for (int k = 0; k < 2*input_value-1-2*count; ++k) {
                printf("*");
            }
            printf("\n");

        }
        // 중간 줄 # 반올림 함수 사용
        if (i == ((int)ceil(2*input_value-1)/2))
        {
            for (int j = 0; j < 2*input_value-1; ++j) {
                printf("*");
            }
            printf("\n");
        }
        // 초기 부분
        else if(i<(2*input_value-1)/2)
        {
            // 띄워 쓰기
            for (int k = 0; k < input_value - i - 1; ++k) {
                printf(" ");
            }
            // 별 작성
            for (int k = 0; k < 2 * i + 1; ++k) {
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}