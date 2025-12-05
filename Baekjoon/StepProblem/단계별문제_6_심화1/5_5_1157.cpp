#include <stdio.h>
#include <string.h>

int checkalpha(char C){
    if(C<='Z' && C>='A') return 1;
    else if(C<='z' && C>='a') return 2;
    else return 0;
}

int main() {
    char Input[1000005]; // 입력받을 문자열의 최대 길이 설정
    int Storage_characters[91] = {0}; // 알파벳 수만큼 크기 설정
    int max_value = 0; // 최빈값
    int max_characters = 0; // 최빈값을 갖는 알파벳의 아스키코드
    int isSame_count = 0;
    bool isSame = false; // 중복값 확인용

    scanf("%s", Input);
    int Input_num = strlen(Input);

    // 입력값의 소문자를 대문자로 만들어줌
    int upper_count = 0;
    while(Input[upper_count]){
        if(Input[upper_count]>='a' && Input[upper_count]<='z'){
            Input[upper_count]=Input[upper_count]-32;
        }
        upper_count++;
    }

    // 알파벳 호출 횟수 구하는 코드
    for (int i = 0; i < Input_num; ++i) {
        /* 아스키코드를 활용한 저장 방법
         - 문자열에 int형 변수를 할당하면, 해당 정수에 맞는 아스키코드를 갖는 문자로 변환됨
         */
        if (checkalpha(Input[i]) == 1) {
            Storage_characters[Input[i]] += 1; // (해당 알파벳의 아스키코드)번째의 호출 횟수를 1 증가
        }
    }

    // 최빈값 도출하는 반복문
    for (int i = 0; i <= 90; ++i) {
        if (Storage_characters[i] > max_value)
        {
            max_value = Storage_characters[i];
            max_characters = i;
        }
    }

    // 중복 횟수 누적
    for (int i = 1; i < 91; ++i) {
        if (Storage_characters[i] == max_value && Storage_characters[i] != 0)
        {
            isSame_count += 1;
        }
        if (isSame_count >= 2)
        {
            isSame = true;
            break;
        }
    }

    // 중복 여부 확인
    if (isSame)
    {
        printf("?");
    }
    else
    {
        printf("%c", char(max_characters));
    }

    return 0;
}

// 아니 이거 왜 안되는데
// 백준에서 isalpha 사용시, 대소문자 상관없이 1024가 리턴됨