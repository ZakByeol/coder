#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// 중위표기식을 후위표기식으로 변환하는 프로그램
// 42m 경과

// OPERATOR ENUM
typedef enum
{
    LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
    PLUS = '+', MINUS = '-',
    MULTIPLY = '*', DIVIDE = '/',
}OPERATOR;


int32_t CountOperator = 0;
int32_t CountProfix = 0;

// Task to copy data from Stack by FILO
void StackFILO(char* OPERATOR_STACK, char* Profix_Expression, int32_t count)
{
    for (int32_t i = 0; i < count; i++)
    {
        Profix_Expression[CountProfix] = OPERATOR_STACK[CountOperator-1];
        OPERATOR_STACK[CountOperator] = '\0';
        Profix_Expression[CountProfix+1] = '\0';
        CountProfix++;
        CountOperator--;
    }
}

// Task to get OPERATOR's Priority
int32_t GetPriority(char OPERATOR)
{
    int32_t Priority = -1;
    switch (OPERATOR)
    {
    case MULTIPLY:
    case DIVIDE:
        Priority = 2;
        break;
    case PLUS:
    case MINUS:
        Priority = 1;
        break;
    
    default:
        break;
    }

    return Priority;
}

// Task to get result whether first parameter is priorprioritized by second parameter
int32_t IsPrior(char OPERATOR1, char OPERATOR2)
{
    if (OPERATOR1 == '\0')
    {
        return 0;
    }
    
    int32_t priority1 = GetPriority(OPERATOR1);
    int32_t priority2 = GetPriority(OPERATOR2);
    if (priority1 == -1 || priority2 == -1)
    {
        printf("ERROR CODE : CAN'T GET PRIORITY\n");
        return 0;
    }

    return priority1 > priority2;
}


int main()
{
    char Token = '0';
    char PrefixNotation[100];

    // OPERATOR_STACK - First in Last Out Structure
    char Operator_Stack[50];

    // Input string and malloc/initial string space 
    scanf("%s", PrefixNotation);
    int32_t MAX_INDEX = strlen(PrefixNotation)-1;
    char* ProfixNotation = (char*)calloc(sizeof(char), MAX_INDEX);
    

    // Mechanism
    int32_t i = 0;
    for (i = 0; i <= MAX_INDEX; i++)
    {
        Token = PrefixNotation[i];
        // printf("%c", Token);
        if (Token == LEFT_PARENTHESIS) { // 중괄호 ( 일때,
            continue;
        }
        else if (Token == RIGHT_PARENTHESIS) { // 중괄호 ) 일때, 스택 내의 요소를 전부 FILO 방식으로 꺼냄
            StackFILO(Operator_Stack, ProfixNotation, CountOperator);
        }
        else if(Token == DIVIDE || Token == MULTIPLY || Token == PLUS || Token == MINUS) // 연산자일때, 우선순위를 가려 처리함
        {
            int32_t TAILS_INDEX = strlen(Operator_Stack) + 1;
            if (IsPrior(Operator_Stack[CountOperator-1], Token))
            {
                StackFILO(Operator_Stack, ProfixNotation, CountOperator);
            }
            Operator_Stack[CountOperator] = Token;
            Operator_Stack[CountOperator+1] = '\0';
            CountOperator++;

        }
        else // 피연산자일때, 그대로 출력함
        {
            ProfixNotation[CountProfix] = Token;
            ProfixNotation[CountProfix+1] = '\0';
            CountProfix++;
        }
    }

    // 널값일때(문자열을 전부 탐색했을 때), 스택 내의 요소를 전부 FILO 방식으로 꺼냄 
    StackFILO(Operator_Stack, ProfixNotation, CountOperator);
    printf("\n%s", ProfixNotation);

    
    free(ProfixNotation);

    return 0;
}