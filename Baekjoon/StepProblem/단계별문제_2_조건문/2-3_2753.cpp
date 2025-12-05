#include <stdio.h>

int main(){
    int year_value;
    while (1)
    {
        scanf("%d", &year_value);
        if (year_value>=1 && year_value<=4000)
        {
            break;
        }
        else
        {
            printf("재입력 : \n");
        }
    }

    int result1 = year_value%4 ;
    int result2 = year_value%100;
    int result3 = year_value%400;

/*  == / != (같다 / 같지않다)
        익숙한 연산자인데 === / !== 이건 뭐지?
    === / !== 은 엄격한 비교이다.
        '엄격하게'의 의미는 변수 타입까지 고려한다는 것이다. 
*/
    if (result3 == 0)
    {
        printf("1");
    }
    else if (result1 == 0 && result2 != 0)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
    return 0;
}