#include <cstdio>

int main()
{
    char Input_String[5][15] = {0,};
    // 문자열 입력
    for (int i = 0; i < 5; ++i) {
        scanf("%s", Input_String[i]);
    }

    // 널값이면 건너뛰고, 아니면 문자를 출력
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (Input_String[j][i] == '\0') continue;
            printf("%c", Input_String[j][i]);
        }
    }
    return 0;
}