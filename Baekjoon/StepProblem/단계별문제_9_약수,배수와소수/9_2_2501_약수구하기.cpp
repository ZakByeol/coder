#include <cstdio>

int main()
{
    int BaseValue,NumValue,Count=0;
    int ResultValue = 0;
    scanf("%d %d", &BaseValue, &NumValue);

    // 약수 구하는 반복문
    for (int i = 1; i <= BaseValue; ++i) {

        // 마지막에, NumValue가 BaseValue의 약수의 개수보다 클때, 결과값을 0으로 할당하고 break;
        if (i == BaseValue && Count < NumValue-1)
        {
            ResultValue = 0;
            break;
        }

        // NumValue가 1이면, 어떤 경우든 결과는 1로 도출됨
        if (NumValue == 1)
        {
            ResultValue = 1;
            break;
        }

        // Count가 NumValue와 같아지면, 밑의 코드를 실행하지 않고 break
        // 이전의 ResultValue를 가지고 나감
        if (Count == NumValue) break;

        if (BaseValue%i == 0)
        {
            Count += 1;
            ResultValue = i;
            continue;
        }
    }

    // 결과 출력
    printf("%d", ResultValue);
    return 0;
}