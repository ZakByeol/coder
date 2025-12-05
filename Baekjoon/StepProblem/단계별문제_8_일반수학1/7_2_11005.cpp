/*
#include <cstdio>
#include <cstring>

int main() {
    int Input_Value, Input_Binary, Value_mod,Value_division=0;
    char Answer[101];
    scanf("%d %d", &Input_Value, &Input_Binary);
    Value_division = Input_Value;
    int count = 0;

    while (Value_division/Input_Binary != 0)
    {
        Value_mod = Value_division % Input_Binary;
        Value_division = Value_division/Input_Binary;

        if (Value_mod >= 10)
        {
            Answer[count] = char(Value_mod + 55);
        }
        else if (Value_mod < 10)
        {
            Answer[count] = char(Value_mod + 48);
        }
        count++;
    }

    // 마지막 나머지 연산
    if(Value_division/Input_Binary == 0 && Value_division >= 10)
    {
        Answer[count] = char(Value_division + 55);
    }
    else if(Value_division/Input_Binary == 0 && Value_division < 10)
    {
        Answer[count] = char(Value_division + 48);
    }

    // 역순으로 문자열 출력
    int lenstring = strlen(Answer);
    for (int i = lenstring - 1; i >= 0; --i)
    {
        printf("%c", Answer[i]);
    }
    return 0;
}*/

// 궁금증..
#include <cstdio>
#include <cstring>

int main() {
    int Input_Value, Input_Binary, Value_mod;
    char Answer[10000]; // 배열 크기를 10000로 해야함
    scanf("%d %d", &Input_Value, &Input_Binary);
    int count = 0;

    // 반복문 사용함으로써 이전에 마지막 몫을 포함 시키지 못한 점을 수정
    for (int i = Input_Value; i > 0;) {
        Value_mod = i % Input_Binary;
        if (Value_mod < 10) {
            Answer[count++] = char(Value_mod + 48);
        }
        else {
            Answer[count++] = char(Value_mod + 55);
        }
        i /= Input_Binary;
    }

    // 역순으로 문자열 출력
    int lenstring = strlen(Answer);
    for (int i = lenstring - 1; i >= 0; --i)
    {
        printf("%c", Answer[i]);
    }
    return 0;
}
