#include <stdio.h>
#include <stdlib.h>
#include <algorithm>  // C++ sort 사용을 위해 추가

typedef struct _tagGreedy {
    int StartTime;
    int EndTime;
} Greedy;

// C++ sort함수를 위한 비교 함수 (C++ 문법) -> 인트로 정렬 Intro Sort
int compare(const void* a, const void* b) {
    Greedy* m1 = (Greedy*)a;
    Greedy* m2 = (Greedy*)b;

    // 종료시간이 같으면 시작시간 오름차순
    if (m1->EndTime == m2->EndTime) {
        return m1->StartTime - m2->StartTime;
    }
    // 종료시간 오름차순
    return m1->EndTime - m2->EndTime;
}

int main() {
    int InputAmount;
    int RecentFinish = 0;
    int ResultCount = 0;

    scanf("%d", &InputAmount);
    Greedy* Meetings = (Greedy*)calloc(InputAmount, sizeof(Greedy));

    for (int i = 0; i < InputAmount; i++) {
        scanf("%d %d", &Meetings[i].StartTime, &Meetings[i].EndTime);
    }

    // ⓐ - IntroSort for using C language
    qsort(Meetings, InputAmount, sizeof(Greedy), compare);

    /*
    std::sort(Meetings, Meetings + InputAmount, [](const Greedy& a, const Greedy& b)
    { // using C++'s sort()
        if(a.EndTime == b.EndTime) return a.StartTime < b.StartTime;
        return a.EndTime < b.EndTime;
    });
    */

    // ⓑ - Linear Search/Greedy Algorithm
    for (int i = 0; i < InputAmount; i++) {
        if (Meetings[i].StartTime >= RecentFinish) {
            ResultCount++;
            RecentFinish = Meetings[i].EndTime;
        }
    }

    // ⓒ - print and unallocate
    printf("%d", ResultCount);
    free(Meetings);
    return 0;
}
