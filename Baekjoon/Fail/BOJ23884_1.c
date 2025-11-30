#include <stdio.h>

void swap(int* swap1, int* swap2)
{
    int tmp = *swap1;
    *swap1 = *swap2;
    *swap2 = tmp;
}

int main()
{
    int ArraySize = 0, CountChange = 0;
    int count = 0;
    scanf("%d %d", &ArraySize, &CountChange);

    int Array[ArraySize];
    int MaxValue = 0;
    int MaxValueLocation = 0;

    for (int i = 0; i < ArraySize; i++)
    {
        scanf(" %d", Array+ i);
    }
    

    // 뒤의 인덱스부터 선택탐색을 함
    // 처음에 최댓값을 첫번째 탐색값으로 초기화, 크기 구분을 하기 위해서
    for (int i = ArraySize-1; i >= 0; i--)
    {
        // K번의 교체가 이루어졌으면, 탈출
        if (count == CountChange)
        {
            break;
        }
        

        // 현재 탐색값이 인덱스보다 작거나 같다는 것은, 스왑할 값이 앞에 있는 요소들에 있다는 것과 같다.
        if (Array[i] <= i)
        {
            MaxValue = Array[i];
            for (int k = 1; k <= i; k++)
            {
                if (Array[i-k] > MaxValue) 
                {
                    MaxValue = Array[i-k];
                    MaxValueLocation = i-k;
                }
            } 
            swap(Array+i, Array + MaxValueLocation);
            count++;
        }
    }

    if (count < CountChange)
    {
        printf("-1");
        return 0;
    }
    for (int i = 0; i < ArraySize; i++)
    {
        printf("%d ", Array[i]);
    }
    
    
    
    return 0;
}