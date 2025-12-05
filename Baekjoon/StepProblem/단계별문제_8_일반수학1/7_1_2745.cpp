#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    //10진수로 10억일 때, 10이하의 진법이 입력되면 int 범위를 초과할 수 있다.
    char input[10000];
    int Input_Binary;
    long long result = 0, base_value = 0;

    scanf("%s %d", input, &Input_Binary);      //문자와 진법을 입력 받음

    int string_len = strlen(input);        //문자열 갯수 구하기

    for (int i = 0; i < string_len; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            base_value = input[i] - '0';     //보기에는 숫자 이지만 문자 이므로 아스키 코드 연산을 이용해 숫자값을 구해야 됨
        }
        else if (input[i] >= 'A' && input[i] <= 'Z') {
            base_value = input[i] - 'A' + 10;
        }

        result += base_value * pow(Input_Binary, string_len - 1 - i);      //진법 변환 식
    }
    printf("%lld", result);
    return 0;
}
