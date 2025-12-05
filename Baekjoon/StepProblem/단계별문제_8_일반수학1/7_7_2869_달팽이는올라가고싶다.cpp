/*#include <cstdio>
#include <ctime>

int main()
{
     시간 측정을 위한 변수
    clock_t start, finish;
    double duration;

    start = clock();

    int Height_Value,DayUp_Value,NightDown_Value;
    int NowHeight_Value=0;
    int Result_Days=0;

    scanf("%d %d %d", &DayUp_Value, &NightDown_Value, &Height_Value);
    while (NowHeight_Value != Height_Value)
    {
        Result_Days += 1;

        NowHeight_Value += DayUp_Value;
        if (NowHeight_Value >= Height_Value) break;

        NowHeight_Value -= NightDown_Value;
        if (NowHeight_Value >= Height_Value) break;
    }
    printf("%d\n", Result_Days);

     시간 측정을 위한 구문
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f 초입니다..\n", duration);

    return 0;
}*/

// 시간 제한 0.25초를 충족하기 위해서는 반복문을 사용하면 안된다.

#include <cstdio>
//#include <ctime>

int main()
{
//    /* 시간 측정을 위한 변수 */
//    clock_t start, finish;
//    double duration;
//
//    start = clock();

    int Height_Value,DayUp_Value,NightDown_Value;
    int result =0;

    scanf("%d %d %d", &DayUp_Value, &NightDown_Value, &Height_Value);
    result = (Height_Value-NightDown_Value-1)/(DayUp_Value-NightDown_Value)+1;
    printf("%d\n", result);

//    /* 시간 측정을 위한 구문 */
//    finish = clock();
//    duration = (double)(finish - start) / CLOCKS_PER_SEC;
//    printf("%f 초입니다..\n", duration);

    return 0;
}