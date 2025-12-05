#include <cstdio>

int pow_function(int base, int quotient);
void divide_start_value(int N,int row,int col);

int start_point = 0; // 분할된 각각의 블록에서 첫번째에 속하는 수

int main()
{
    int input_N,input_r,input_c; // 순서대로, N차원,r행,c열 입력값
    scanf("%d %d %d", &input_N, &input_r, &input_c);
    divide_start_value(input_N,input_r,input_c);
    printf("%d", start_point);

    return 0;
}

void divide_start_value(int N,int row,int col)
{
    int max_number = pow_function(2, N);
    int half_number = max_number/2;
    if (N != 0)
    {
        // 가르키는 요소가 몇 사분면에 위치하는지 알아야 함
        if (row < half_number && col >= half_number) // 제 1사분면
        {
            start_point += pow_function(2, 2*N-2);
            divide_start_value(N-1, row, col-half_number);
        }
        else if (row < half_number && col < half_number) // 제 2사분면
        {
            divide_start_value(N-1, row,col);
        }
        else if (row >= half_number && col < half_number) // 제 3사분면
        {
            start_point += 2 * pow_function(2, 2*N-2);
            divide_start_value(N-1, row-half_number, col);
        }
        else
        {
            start_point += 3 * pow_function(2, 2*N-2);
            divide_start_value(N-1, row-half_number, col-half_number);
        }
    }
}

// base의 quotient 승을 구하는 함수
int pow_function(int base, int quotient)
{
    int result = 1;
    for (int i = 0; i < quotient; i++) {
        result = result * base;
    }

    return result;
}
