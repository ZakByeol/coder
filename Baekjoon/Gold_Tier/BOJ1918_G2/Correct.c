#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 전역 변수 대신 메인 함수 내에서 스택 관련 변수 관리 권장

// 연산자 우선순위 반환 함수
// 괄호는 스택 내부에서 가장 낮은 우선순위로 간주하여, 자기보다 낮은 연산자가 올 때까지 팝을 막습니다.
int GetPriority(char OPERATOR)
{
    switch (OPERATOR)
    {
    case '*':
    case '/':
        return 2; // 곱셈/나눗셈: 2
    case '+':
    case '-':
        return 1; // 덧셈/뺄셈: 1
    case '(':
        return 0; // 스택 내부에서 '('는 가장 낮은 우선순위 (0)
    default:
        return -1; // 잘못된 연산자
    }
}

// 스택의 푸시 연산을 수행합니다.
void Push(char* stack, int* top, char data)
{
    stack[(*top)++] = data;
}

// 스택의 팝 연산을 수행하고 그 결과를 반환합니다.
char Pop(int* top, char* stack)
{
    if (*top == 0) return '\0'; // 스택이 비어있으면 널 문자 반환
    return stack[--(*top)];
}

int main()
{
    // 입력 중위 표기식 (최대 100자)
    char InfixNotation[101]; 
    // 출력 후위 표기식 (최대 입력 길이와 같음)
    char PostfixNotation[101];
    int PostfixIndex = 0;

    // 연산자 스택
    char OperatorStack[101];
    // top: 스택의 다음 푸시 위치 (요소의 개수)
    int StackTop = 0; 

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
        else if (Token == '(')
        {
            // 2. 왼쪽 괄호일 때: 스택에 푸시
            Push(OperatorStack, &StackTop, Token);
        }
        else if (Token == ')')
        {
            // 3. 오른쪽 괄호일 때: 
            // 스택에서 '('가 나올 때까지 Pop하여 출력
            while (StackTop > 0 && OperatorStack[StackTop - 1] != '(')
            {
                PostfixNotation[PostfixIndex++] = Pop(&StackTop, OperatorStack);
            }
            // '('를 스택에서 제거 (팝)하고 출력하지 않음
            if (StackTop > 0 && OperatorStack[StackTop - 1] == '(')
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

    // 결과 문자열의 끝에 널 문자 추가
    PostfixNotation[PostfixIndex] = '\0';
    
    // 결과 출력
    printf("%s\n", PostfixNotation);

    // 동적 할당을 사용하지 않아 free 불필요
    return 0;
}