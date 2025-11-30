#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
    PLUS = '+', MINUS = '-',
    MULTIPLY = '*', DIVIDE = '/',
}OPERATOR;

// 전역 변수 대신 메인 함수 내에서 스택 관련 변수 관리 권장

// 연산자 우선순위 반환 함수
// 괄호는 스택 내부에서 가장 낮은 우선순위로 간주하여, 자기보다 낮은 연산자가 올 때까지 팝을 막는다.
int GetPriority(char OPERATOR)
{
    switch (OPERATOR)
    {
    case MULTIPLY:
    case DIVIDE:
        return 2; // 곱셈/나눗셈: 2
    case PLUS:
    case MINUS:
        return 1; // 덧셈/뺄셈: 1
    case LEFT_PARENTHESIS:
        return 0; // 스택 내부에서 '('는 가장 낮은 우선순위 (0)
    default:
        return -1; // 잘못된 연산자
    }
}

// 스택의 푸시 연산
void Push(char* stack, int* top, char data)
{
    stack[(*top)++] = data;
}

// 스택의 팝 연산을 수행하고 그 결과를 반환한다.
char Pop(int* top, char* stack)
{
    if (*top == 0) return '\0'; // 스택이 비어있으면 널 문자 반환
    return stack[--(*top)];
}

int main()
{
    char InfixNotation[101]; 
    char PostfixNotation[101];
    int PostfixIndex = 0;

    char OperatorStack[101];
    int StackTop = 0; // 스택의 요소의 갯수

    // 입력 받기
    scanf("%s", InfixNotation);
    int MAX_INDEX = strlen(InfixNotation);

    // 알고리즘 실행
    for (int i = 0; i < MAX_INDEX; i++)
    {
        char Token = InfixNotation[i];

        if (Token >= 'A' && Token <= 'Z')
        {
            // 1. 피연산자 (문자)일 때: 그대로 출력 문자열에 추가
            PostfixNotation[PostfixIndex++] = Token;
        }
        else if (Token == LEFT_PARENTHESIS)
        {
            // 2. 왼쪽 괄호일 때: 스택에 푸시
            Push(OperatorStack, &StackTop, Token);
        }
        else if (Token == RIGHT_PARENTHESIS)
        {
            // 3. 오른쪽 괄호일 때: 
            // 스택에서 '('가 나올 때까지 Pop하여 출력
            while (StackTop > 0 && OperatorStack[StackTop - 1] != LEFT_PARENTHESIS)
            {
                PostfixNotation[PostfixIndex++] = Pop(&StackTop, OperatorStack);
            }
            // '('를 스택에서 제거 (팝)하고 출력하지 않음
            if (StackTop > 0 && OperatorStack[StackTop - 1] == LEFT_PARENTHESIS)
            {
                Pop(&StackTop, OperatorStack);
            }
        }
        else // 4. 연산자 (+, -, *, /)일 때
        {
            // 스택이 비어있지 않고, 스택의 탑 연산자가 현재 토큰보다 우선순위가 
            // '높거나 같으면' Pop하여 출력합니다.
            // 참고: '('는 스택 내부에서 가장 낮은 우선순위(0)를 가집니다.
            while (StackTop > 0 && GetPriority(OperatorStack[StackTop - 1]) >= GetPriority(Token))
            {
                PostfixNotation[PostfixIndex++] = Pop(&StackTop, OperatorStack);
            }
            // 현재 연산자를 스택에 Push합니다.
            Push(OperatorStack, &StackTop, Token);
        }
    }

    // 5. 문자열 탐색이 끝났을 때: 스택에 남아있는 모든 연산자를 Pop하여 출력
    while (StackTop > 0)
    {
        PostfixNotation[PostfixIndex++] = Pop(&StackTop, OperatorStack);
    }
    PostfixNotation[PostfixIndex] = '\0';
    
    // 결과 출력
    printf("%s\n", PostfixNotation);

    return 0;
}