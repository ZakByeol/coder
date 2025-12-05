#include <cstdio>

int main()
{
    int InputValue,ResultValue=0,IncreaseValue=0;
    scanf("%d", &InputValue);

    for (int i = 0; i < 20000; ++i) {
        // 6을 얼마나 곱하는 것을 나타내는 IncreaseValue 변수 ( 중첩 )
        if (i >= 1)
        {
            IncreaseValue += i-1;
        }

        if (InputValue == 1)
        {
            ResultValue = 1;
            break;
        }
        else if (i>0 && InputValue >= 2+6*IncreaseValue && InputValue <= 7+ 6*IncreaseValue + 6*(i-1) )
        { // 범위 내에서 확인될시, ResultValue에 지나간 방의 개수를 할당하고 break
            ResultValue = i+1;
            break;
        }

        /*
         * i, IncreaseValue 확인용
         * printf("%d : %d %d\n", i, IncreaseValue, OverlappingValue);
         */
    }
    printf("%d", ResultValue);
    return 0;
}