#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int checkArray(int* CompareA, int* CompareB, const int Size)
{
    int result = 1;
    for (int i = 0; i<Size; i++) {
        if (CompareA[i] != CompareB[i]) {
            result = 0;
        }
    }
    return result;
}


int InsertionSort(int* DataSet,int* ArrayB, const int _Size) 
{ 
    int32_t IsMatch = 0;
    int TopValue;
    for (int i = 1; i<_Size; i++) {

        // 맨 뒤의 요소가 최댓값일때 정렬이 되어있다는 뜻 이므로, 건너뜀
        if (DataSet[i-1] <= DataSet[i]) {
//            for (int k = 0; k <_Size; k++) {
//                printf("%d ", DataSet[k]);
//            }
//            printf("->");
            IsMatch = checkArray(DataSet, ArrayB, _Size);
            if (IsMatch) {
                return IsMatch;
            }
            continue;
        }
        TopValue = DataSet[i];

        for (int j = i; j>=0; j--) {
            if (DataSet[j-1] > TopValue) {
                DataSet[j] = DataSet[j-1];
//                for (int k = 0; k <_Size; k++) {
//                    printf("%d ", DataSet[k]);
//                }
//                printf("->");
                IsMatch = checkArray(DataSet, ArrayB, _Size);
                if (IsMatch) {
                    return IsMatch;
                }
            }
            else {
                DataSet[j] = TopValue;
//                for (int k = 0; k <_Size; k++) {
//                    printf("%d ", DataSet[k]);
//                }
//                printf("->");
                IsMatch = checkArray(DataSet, ArrayB, _Size);
                if (IsMatch) {
                    return IsMatch;
                }
                break;
            }
        }


    }


    return IsMatch;
} 

int main()
{
    int ArraySize = 0;
    int IsCorrect = 0;
    scanf("%d", &ArraySize);

    int* Array_A = (int*)calloc(sizeof(int), ArraySize);
    int* Array_B = (int*)calloc(sizeof(int), ArraySize);

    for (int i = 0; i<ArraySize; i++) {
        scanf("%d", Array_A+i);
    }

    for (int i = 0; i<ArraySize; i++) {
        scanf("%d", Array_B+i);
    }

    IsCorrect = InsertionSort(Array_A, Array_B, ArraySize);
    printf("%d", IsCorrect);

    free(Array_A);
    free(Array_B);
    return 0;
}