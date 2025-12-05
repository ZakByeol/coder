#include <cstdio>
#include <cstdlib>

// "각 사람이 돈을 인출하는데 필요한 시간" 의 합의 최솟값은
// 각 사람이 돈을 인출하는데 걸리는 시간을 나타내는 배열이
// 오름차순으로 정렬되어 있다는 의미이기도 하다.

// reason :: 차례가 지나갈 수록, 앞에서 지연된 시간이 중첩으로 더해지기 때문이다.

int main()
{
    int number_humans;

    // input
    scanf("%d", &number_humans);
    int delay_time[number_humans];
    for (int i = 0; i < number_humans; ++i) {
        scanf("%d", &delay_time[i]);
    }

    // sorted
    int temp;
    for (int i = 0; i < number_humans; ++i) {
        for (int j = i+1; j < number_humans; ++j) {
            if (delay_time[i] >= delay_time[j])
            {
                temp = delay_time[i];
                delay_time[i] = delay_time[j];
                delay_time[j] = temp;
            }
        }
    }

    // calculate result
    int takes_time;
    int sum_value = 0;
    for (int i = 0; i < number_humans; ++i) {
        takes_time = 0;
        for (int j = i; j >= 0; --j) {
            takes_time += delay_time[j];
        }
        sum_value += takes_time;
    }

    printf("%d", sum_value);

    return 0;
}