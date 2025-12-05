#include <stdio.h>

int Plus(const int A,const int B){
    return A+B;
} // 덧셈 함수

int main(){
    int Test_case;
    int A,B;
    scanf("%d",&Test_case);
    for (int i = 0; i < Test_case; ++i) {
        while (true) // A와B의 조건식
        {
            scanf("%d %d",&A,&B);
            if(0<A && A<10 && 0<B && B<10 )
            {
                break;
            }
            else
            {
                printf("재입력 : \n");
            }
        }
        printf("Case #%d: %d\n", i+1, Plus(A,B));
    }
}