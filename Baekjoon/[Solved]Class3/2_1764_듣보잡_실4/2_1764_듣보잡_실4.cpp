#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* first, const void* second);

typedef struct
{
    char people_name[21];
}People;

int main()
{
    // 구조체 포인터 선언 및 초기화
    People* list = NULL;
    People* sorted_list = NULL;

    // 입력
    int unheard_num,unseen_num;
    scanf("%d %d", &unheard_num, &unseen_num);

    int sum_num = unheard_num + unseen_num;

    // 동적 할당
    list = (People*) malloc(sum_num * sizeof(People) );
    sorted_list = (People*) malloc(sum_num * sizeof(People) );

    // 듣도 못한 사람,보지도 못한 사람 입력
    for (int i = 0; i < sum_num; i++) {
        scanf(" %s", list[i].people_name);
    }

    // 중복 여부 확인
    int same_index = 0;
    for (int i = 0; i < unheard_num; ++i) {
        for (int j = unheard_num; j < sum_num; ++j) {
            if (strcmp(list[i].people_name, list[j].people_name) == 0)
            {
                strcpy(sorted_list[same_index++].people_name, list[i].people_name);
            }
        }
    }

    qsort(sorted_list, same_index, sizeof(sorted_list[0]), compare);
    printf("%d\n", same_index);
    for (int i = 0; i < same_index; ++i) {
        printf("%s\n", sorted_list[i].people_name);
    }

    // 동적 해제
    free(list);
    free(sorted_list);

    return 0;
}


// 탐색 값과 리스트 값의 사전적 우선도 비교
int compare(const void* first, const void* second)
{
    People* a = (People*)first;
    People* b = (People*)second;

    if (strcmp(a->people_name, b->people_name) > 0)
        return 1;
    else
        return -1;
}

