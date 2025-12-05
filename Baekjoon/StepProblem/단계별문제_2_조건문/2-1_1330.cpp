#include <stdio.h>

int main(){
    int A,B;

    /* 조건 충족 반복문 */
    while (1)
    {
        scanf("%d %d", &A,&B);
        if (A,B>=-10000 && A,B<=10000)
        {
            break;
        }
        else
        {
            printf("재입력 : \n");
        }
    }
    /* 출력문 */
    if (A>B)
    {
        printf(">");
    }
    else if (A<B)
    {
        printf("<");
    }
    else
    {
        printf("==");
    }
    
    
    
    return 0;
}