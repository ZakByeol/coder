#include <stdio.h>

int main() {

	int A = 0;
	int B = 0;
	double output = 0;

    /* 조건 충족까지 반복 */
	while (1) {
		scanf("%d %d", &A, &B);
		if (A > 0 || B < 10) break;
		else printf("재입력\n");
	}
	output = (double)A/B;
/*
(double) a/b와 (double)(a/b)의 결과가 다른 이유
1. a를 먼저 형 변환 후 그 값을 나누는 연산 실행.
2. a/b를 연산 후 해당 값을 형 변환 하는 과정.
*/
	printf("%.9lf", output);

	return 0;
}