#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 함수 포인터
// 함수명은 함수의 주소를 가르킨다고 볼 수 있다!
// 함수 포인터를 이용하여 호출하는 경우에는, 함수의 선언/구현을 미리 하지 않아도 된다는 장점이 존재함
// 또, 매개변수로 사용할 수 있다는 장점으로, 중복된 코드 작성을 피할 수 있음!

// 퀵정렬 qsort 함수에 사용될 비교 함수
int ComparePoint( const void* _elem1, const void* _elem2)
{
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if( *elem1 < *elem2)
        return 1;
    else if(*elem1 > *elem2)
        return -1;
    else
        return 0;
}

int main()
{
    int DataSet[] = {6,4,2,3,1,5};
    int Length = sizeof(DataSet)/sizeof(DataSet[0]);
    
    qsort((void*)DataSet, Length, sizeof(int), ComparePoint);

    for (int i = 0; i < Length; i++)
    {
        printf("%d ", DataSet[i]);
    }
    printf("\n");
    
    return 0;
}