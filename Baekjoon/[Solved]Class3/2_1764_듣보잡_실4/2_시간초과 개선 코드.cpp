#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 21
#define MAX_PEOPLE 500000

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int sum_num = N+M;

    // 이중포인터 사용하여, 구조체 대신 이름 입력
    char **names = (char **)malloc(sum_num * sizeof(char *));
    for (int i = 0; i < sum_num; i++) {
        names[i] = (char *)malloc(MAX_NAME * sizeof(char));
        scanf("%s", names[i]);
    }
    // 입력값 정렬
    qsort(names, sum_num, sizeof(char *), compare);

    char **result = (char **)malloc(MAX_PEOPLE * sizeof(char *));

    // 정렬을 먼저 거쳤기에, 앞뒤의 문자열을 비교함
    int count = 0;
    for (int i = 1; i < sum_num; i++) {
        if (strcmp(names[i - 1], names[i]) == 0) {
            result[count++] = names[i];
            i++;
        }
    }

    // 출력
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s\n", result[i]);
    }

    // 동적 해제
    for (int i = 0; i < sum_num; i++) {
        free(names[i]);
    }
    free(names);
    free(result);

    return 0;
}

