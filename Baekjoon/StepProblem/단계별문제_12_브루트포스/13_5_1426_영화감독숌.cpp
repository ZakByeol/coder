// 개빡치네

/*
6 : 5666
7 : 6660 < 6666 따라서, 6660

8 : 6661
9 : 6662
10 : 6663
11 : 6664
12 : 6665
13 : 6666
14 : 6667
15 : 6668
16 : 6669
17 : 7666
18 : 8666
19 : 9666
20 : 10666*/

#include <cstdio>

int main(){
    int INPUT_NUM;
    scanf("%d", &INPUT_NUM);

    int Count_End = 0; // 종말의 숫자 개수
    int Current_Number = 666; // 현재 숫자, 666부터 시작
    while(1)
    {
        // Current_Number에서 666가  Count_End++
        int consecutive_6=0;
        int cur=Current_Number;
        while(cur>0){
            int digit = cur%10;
            if(digit==6)
                consecutive_6++;
            else
                consecutive_6=0; //다시 0으로 초기화

            if(consecutive_6==3){
                Count_End++;
                break;
            }
            cur = cur/10;
        }

        // INPUT_NUM 번째로 작은 종말 숫자 였다면 break, 아니면 계속
        if(Count_End == INPUT_NUM )
            break;
        Current_Number++;
    }
    printf("%d\n", Current_Number);
}