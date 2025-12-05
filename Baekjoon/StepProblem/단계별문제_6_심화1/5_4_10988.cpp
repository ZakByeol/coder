#include <stdio.h>
#include <string.h>

 int pel_function(char Input[], int length) {

    for (int i = 0; i < length / 2; i++)
    {
        /* 반복하다가, 일치하지 않은 문자가 발견될시, 0을 리턴하고 종료 */
        if (Input[i] != Input[length - 1 - i])
            return 0;
    }
    /* 반복문이 끝나면 1을 리턴함 */
    return 1;
}

int main() {
    char Input_String[100];
    scanf("%s", Input_String);
    printf("%d", pel_function(Input_String, strlen(Input_String)));
    return 0;
}