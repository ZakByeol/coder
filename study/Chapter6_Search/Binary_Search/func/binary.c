#include "binary.h"

ElementType BinarySearch(int32_t List[], int Size, int32_t const target)
{
    int Left = 0, Right = Size - 1,Mid;
    while (Left<=Right) {
        Mid = (Left+Right)/2;
        if (target == List[Mid])
        {
            return (List[Mid]);
        }
        else if (target > List[Mid]) {
            Left = Mid + 1;
        }
        else
        {
            Right = Mid - 1;
        }
    }

    return -1;
}