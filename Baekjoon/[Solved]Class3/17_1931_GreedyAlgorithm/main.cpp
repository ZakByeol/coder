/*
#include <stdio.h> 
#include <stdlib.h>
#pragma warning(disable: 4996)

typedef struct _tagGreedy
{
    int StartTime;
    int EndTime;
}Greedy;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(Greedy* const _pArray, int start, int end) {
    if (start >= end) return;
    int key = start, i = start + 1, j = end, temp;
    while (i <= j) {
        while (i <= end && _pArray[i].EndTime <= _pArray[key].EndTime) i++;
        while (j > start && _pArray[j].EndTime >= _pArray[key].EndTime) j--;

        if (i > j)
        {
            swap(&_pArray[key].EndTime, &_pArray[j].EndTime);
            swap(&_pArray[key].StartTime, &_pArray[j].StartTime);
        }
        else
        {
            swap(&_pArray[i].EndTime, &_pArray[j].EndTime);
            swap(&_pArray[i].StartTime, &_pArray[j].StartTime);
        }
    }

    quickSort(_pArray, start, j - 1);
    quickSort(_pArray, j + 1, end);
}

int main() 
{
    int InputAmount;
    int RecentFinish = 0;
    int ResultCount = 0;

    scanf("%d", &InputAmount);
    Greedy* Meetings = (Greedy*)calloc(InputAmount, sizeof(Greedy)); // dynamic allocate

    for (int i = 0; i < InputAmount; i++) // input start/end time
    {
        scanf("%d %d", &Meetings[i].StartTime, &Meetings[i].EndTime);
    }
    quickSort(Meetings, 0, InputAmount-1); // quick sort - ¨Í

    for (int i = 0; i < InputAmount; i++) // looking EndTime by using Linear Search/Greedy Algorithm - ¨Î
    {
        if (Meetings[i].StartTime >= RecentFinish)
        {
            ResultCount++;
            RecentFinish = Meetings[i].EndTime;
        }
    }

    printf("\n\n");
    for (int i = 0; i < InputAmount; i++)
    {
        printf("%d : %d %d\n", i, Meetings[i].StartTime, Meetings[i].EndTime);
    }

    printf("%d", ResultCount); // print - ¨Ï

    free(Meetings);
	return 0;
}
*/