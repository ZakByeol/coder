#include <cstdio>
#include <cstring>

// bit masking
// bool 자료형 대신 int 자료형을 사용하여 메모리 절약
// 1<<value : 비트를 오른쪽 부터 value+1번째 칸으로 옮김 ( 입력값의 존재 증명 )
int set_s = 0; // 요소의 중복은 불가능하다.
void bit_masking(const char type[], int value);

int main()
{
    char type_calculate[7];
    int input_value,numbers_input;

    scanf("%d", &numbers_input);
    for (int i = 0; i < numbers_input; ++i) {
        scanf("%s", type_calculate);
        scanf("%d", &input_value);
        bit_masking(type_calculate, input_value);
    }

    return 0;
}

void bit_masking(const char type[], int value)
{
    if(strcmp(type,"add") == 0)
    {
        // 비트 연산자 & 와 시프트 연산자 << 사용
        // value의 유무 확인
        if ((set_s & (1<<value)) == 0)
            set_s += (1<<value);
    }
    else if(strcmp(type,"remove") == 0)
    {
        // 비트연산자의 반환 형태
        if((set_s & (1<<value)) > 0)
            set_s -= (1<<value);

    }
    else if(strcmp(type,"check") == 0)
    {
        if((set_s & (1<<value)) > 0)
            printf("1\n");
        else
            printf("0\n");
    }
    else if(strcmp(type,"toggle") == 0)
    {
        if((set_s & (1<<value)) == 0)
            set_s += (1<<value);
        else
            set_s -= (1<<value);
    }
    else if(strcmp(type,"all") == 0)
        set_s = (1<<21) - 1; // (1<<21) - 1 = 11111111111111111111(2) = 2,097,151(10) 이다.
    else
        // type : empty
        set_s = 0;
}