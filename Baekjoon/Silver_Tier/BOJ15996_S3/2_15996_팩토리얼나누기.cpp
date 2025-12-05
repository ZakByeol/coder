#include <cstdio>

// 팩토리얼 구하는 함수
//long long int Factorial_Function(long long int INPUT)
//{
//    long long int RESULT_VALUE = 1;
//    for (long long int i = INPUT; i > 0 ; --i) {
//        RESULT_VALUE *= i;
//    }
//
//    return RESULT_VALUE;
//}
//
// 거듭제곱 구하는 함수
//long long int Exponentiation_Function(long long int INPUT_BASE, long long int INPUT_K)
//{
//    long long int BASE_VALUE = 1;
//    if (INPUT_K == 0) return 0;
//    for (int i = 0; i < INPUT_K; ++i) {
//        BASE_VALUE *= INPUT_BASE;
//    }
//    return BASE_VALUE;
//}

// 입력값이 자료형에서 표현할 수 있는 최대 범위를 넘기기에 수정이 필요함
// 팩토리얼 값에서 바로 거듭제곱의 값을 뺴면 됨
int NUM_MAX_INDEX(long long int INPUT_FACTORIAL, long long int INPUT_BASE)
{
    int COUNT_K;
    for (long long int i = INPUT_BASE; i < INPUT_FACTORIAL; i*=INPUT_BASE) {

    }
}

int main()
{
    long long int INPUT_FACTORIAL,INPUT_EXPONENTIATION;
    long long int RESULT_MAXVALUE;

    scanf("%lld %lld", &INPUT_FACTORIAL, &INPUT_EXPONENTIATION);

    long long int RESULT_FAC = Factorial_Function(INPUT_FACTORIAL);

//    검사용
    printf("입력값 : %lld , %lld\n팩토리얼 : %lld\n거듭제곱(3) 값 : %lld\n",INPUT_FACTORIAL,INPUT_EXPONENTIATION, RESULT_FAC, Exponentiation_Function(INPUT_EXPONENTIATION, 3));

    // N!값부터 1씩 감소하는 i 반복문이며, N! % A^k == 0 이면 할당하고 break하는 반복문
    for (long long int i = RESULT_FAC; i > 0; --i) {
        if ( RESULT_FAC % Exponentiation_Function(INPUT_EXPONENTIATION, i) == 0)
        {
            RESULT_MAXVALUE = i;
            break;
        }
    }

    printf("%lld", RESULT_MAXVALUE);
    return 0;
}
/*
// 15996. 팩토리얼 나누기
#include <cstdio>

int NUMBER_MAX_INDEX(long long INPUT_FACTORIAL, long long INPUT_BASE)
{
    // n!에 있는 소수 a의 개수 찾기
    long long COUNT = 0;
    for(long long i = INPUT_BASE ; i <= INPUT_FACTORIAL; i *= INPUT_BASE)
    {
        COUNT += INPUT_FACTORIAL / i;
    }

    return COUNT;
}


int main()
{
    long long INPUT_FACTORIAL, INPUT_EXPONENTIATION;
    scanf("%lld %lld", &INPUT_FACTORIAL, &INPUT_EXPONENTIATION);

    printf("%d", NUMBER_MAX_INDEX(INPUT_FACTORIAL, INPUT_EXPONENTIATION));

    return 0;
}*/
