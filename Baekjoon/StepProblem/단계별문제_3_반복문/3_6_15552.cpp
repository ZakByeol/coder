#include <stdio.h>

int Plus(const int A,const int B){
    return A+B;
}

int main(){
    int Test_case;
    int A,B;
    while (true){ // 테스트 케이스의 최대 값 조건
        scanf("%d", &Test_case);
        if (Test_case>1000000){
            printf("재입력 : \n");
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < Test_case; ++i) {
        scanf("%d %d",&A,&B);
        printf("%d\n", Plus(A,B));
        // 개행문자 안써서 인식이 안됐음;;
    }
}