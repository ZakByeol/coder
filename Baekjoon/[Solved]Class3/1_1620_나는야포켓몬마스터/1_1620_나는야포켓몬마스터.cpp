#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isName(char Input_value);
int compare(const void* first, const void* second);

typedef struct
{
    int monster_num;
    char monster_name[21];
}Monster;

int main()
{
    int num_poketmon, num_search, i;

    // 구조체 포인터 선언 및 초기화
    Monster* list = NULL;
    Monster* sorted_list = NULL;

    char op[21];

    scanf("%d %d", &num_poketmon, &num_search);

    // 포인터 동적할당
    list = (Monster*)malloc(num_poketmon * sizeof(Monster));
    sorted_list = (Monster*)malloc(num_poketmon * sizeof(Monster));

    // 포켓몬 도감 입력
    for (i = 0; i < num_poketmon; i++)
    {
        scanf(" %s", list[i].monster_name);
        list[i].monster_num = sorted_list[i].monster_num = i + 1; // i 증가 후,
        sorted_list[i] = list[i];
    }

    // qsort(①정렬할 값의 주소, ②요소의 개수, ③요소의 크기, ④기준 함수);
    // 사전적 우선도를 기준으로 정렬함
    qsort(sorted_list, num_poketmon, sizeof(sorted_list[0]), compare);

    // 탐색 반복문
    for (i = 0; i < num_search; i++)
    {
        scanf(" %s", op);

        if(isName(op[0])) // 문자인 경우
        {
            // 이진탐색
            int min_num, max_num, mid_num;
            min_num = 0, max_num = num_poketmon - 1;

            while (min_num <= max_num)
            {
                mid_num = (min_num + max_num) / 2;

                // 도감의 포켓몬이랑 사전적 우선도가 같으면, 도감 번호 출력
                if (strcmp(sorted_list[mid_num].monster_name, op) == 0)
                {
                    printf("%d\n", sorted_list[mid_num].monster_num);
                    break;
                }
                // 도감의 포켓몬보다 사전적 우선도가 크면, 다음 이진탐색 값으로 할당
                else if (strcmp(sorted_list[mid_num].monster_name, op) > 0)
                {
                    max_num = mid_num - 1;
                }
                // 도감의 포켓몬보다 사전적 우선도가 작으면, 다음 이진탐색 값으로 할당
                else
                {
                    min_num = mid_num + 1;
                }
            }
        }
        else // 숫자인 경우
        {
            int idx = atoi(op); // string을 int로 전환시킴 : "11" -> 11
            printf("%s\n", list[idx - 1].monster_name);
        }
            // 이진탐색
    }

    // 동적 할당 해제
    free(sorted_list);
    free(list);

    return 0;
}

// 탐색 값과 리스트 값의 사전적 우선도 비교
int compare(const void* first, const void* second)
{
    Monster* a = (Monster*)first;
    Monster* b = (Monster*)second;

    if (strcmp(a->monster_name, b->monster_name) > 0)
        return 1;
    else
        return -1;
}

// 입력된 탐색값이 알파벳인지, 숫자인지 확인하는 함수
bool isName(char Input_value)
{
    if (Input_value >= 'A' && Input_value <= 'Z')
        return true;
    else if (Input_value >= 'a' && Input_value <= 'z')
        return true;
    else if (Input_value >= '0' && Input_value <= '9')
        return false;
}