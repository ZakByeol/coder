#include <stdio.h>

int main(){
    int A;

    /* 조건 충족 반복문 */
    while (1)
    {
        scanf("%d", &A);
        if (A>=0 && A<=100)
        {
            break;
        }
        else
        {
            printf("재입력 : \n");
        }
    }
    /* 등급 출력문 */
    if (A>=90 && A<= 100)
    {
        printf("A");
    }
    else if(A<=89 && A>=80)
    {
        printf("B");
    }
    else if (A>=70 && A<= 79)
    {
        printf("C");
    }
    else if (A<=69 && A>=60)
    {
        printf("D");
    }
    else
    {
        printf("F");
    }
    return 0;
}