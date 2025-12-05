#include <cstdio>

int main()
{
    unsigned int NUM_CARD, MAX_SUMVALUE,RESULT_VALUE = 0; // 변수 초기하 필수!
    scanf("%d %d", &NUM_CARD, &MAX_SUMVALUE);

    // CARD_NUMBER 라는 정수 배열을 선언
    int CARD_INDEX[NUM_CARD];

    // CARD_NUMBER에 해당하는 인덱스에 카드 숫자 할당
    for (int i = 0; i < NUM_CARD; ++i) {
        scanf("%d", &CARD_INDEX[i]);
    }

    // 카드의 합을 구하기
    for (int i = 0; i < NUM_CARD; ++i) { // 첫번째 카드를 뽑음

        for (int j = 0; j < NUM_CARD; ++j) { // 두번째 카드를 뽑음, 이전 카드와 중복은 금지
            // 중복이 되는 경우, continue
            if (j==i) continue;

            for (int k = 0; k < NUM_CARD; ++k) { // 세번째 카드를 뽑음, 이전 카드와 중복은 금지
                // 중복이 되는 경우, continue
                if (k == j || k==i) continue;

                if ( (CARD_INDEX[i] + CARD_INDEX[j] + CARD_INDEX[k] <= MAX_SUMVALUE) && (CARD_INDEX[i] + CARD_INDEX[j] + CARD_INDEX[k] >= RESULT_VALUE ))
                {
                    RESULT_VALUE = CARD_INDEX[i] + CARD_INDEX[j] + CARD_INDEX[k];
                }
            }
        }
    }

    printf("%d", RESULT_VALUE);

    return 0;
}
