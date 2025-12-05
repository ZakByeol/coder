// Z에 현혹되지 않기!
// 좌표평균의 사분면(Quadrant)을 이용해서 풀이
// 11.05(화)

#include <cstdio>
int pow_function(int base, int quotient);
int first_value(int* SIZE, int position_x, int position_y);

int START_X = 0, START_Y = 0; // result : 탐색 값이 속한 2x2 배열의 2 사분면 값의 위치
int START_POINT = 0; // result : 탐색 값이 속한 2x2 배열의 2 사분면 값

int main()
{
    int Array_SIZE,Locate_x,Locate_y;
    int Base_value; // SIZE가 2가 될때, 첫번째 값
    int* pSIZE = &Array_SIZE;
    scanf("%d %d %d", &Array_SIZE, &Locate_y, &Locate_x);
//    Array_SIZE = 15,Locate_x=1443,Locate_y=444; //실험용

    Base_value = first_value(pSIZE, Locate_x, Locate_y);

    // START_POINT의 위치에 따라 Base_value의 값을 증가시킴
    // 0 1
    // 2 3
    if (Locate_x > START_X && Locate_y == START_Y) Base_value += 1;
    else if (Locate_x == START_X && Locate_y > START_Y) Base_value += 2;
    else if (Locate_x > START_X && Locate_y > START_Y) Base_value += 3;

    printf("%d", Base_value);

    return 0;
}

// START_POINT 즉, 탐색하는 값이 속한 2x2배열의 2사분면의 값을 반환함
int first_value(int* SIZE_N, int position_x, int position_y)
{
    // SIZE가 가르키는 값이 1일때, 반복문 종료
    int MAX_line_number = pow_function(2,*SIZE_N);
    while (MAX_line_number != 2)
    {

        float Limits_SIZE = ((float)MAX_line_number-1)/2; // 배열의 길이의 중간점
        int Half_line = MAX_line_number/2; // *SIZE_N의 절반 : 시작점의 위치 증가 사용
        int OneBlock_num = Half_line*Half_line;

        if (position_x > Limits_SIZE && position_y < Limits_SIZE) {
            // 해당 요소가 제 1 사분면에 있을때
            START_POINT += OneBlock_num;
            START_X += Half_line;

            position_x -= Half_line; // 위치를 Half_line 만큼 감소, 진행에 따라서 Limits_SIZE의 값이 작아지기 때문
        } else if (position_x < Limits_SIZE && position_y < Limits_SIZE) {
            // 해당 요소가 제 2 사분면에 있을때
            START_POINT += 0;
        } else if (position_x < Limits_SIZE && position_y > Limits_SIZE) {
            // 해당 요소가 제 3 사분면에 있을때
            START_POINT += 2*OneBlock_num;
            START_Y += Half_line;

            position_y -= Half_line;
        } else {
            // 해당 요소가 제 4 사분면에 있을때
            START_POINT += 3 * OneBlock_num;
            START_X += Half_line;
            START_Y += Half_line;

            position_x -= Half_line;
            position_y -= Half_line;
        }

        // *SIZE 를 반으로 줄이고, 다음 반복으로 이동
        MAX_line_number /= 2;
        Half_line /= 2;
    }

    return START_POINT;
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

