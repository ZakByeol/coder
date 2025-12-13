#include<stdio.h>
 
void find(int num, int last);
int N, M;
int arr[8];
 
int main() {
	scanf("%d %d", &N, &M);
	find(0, 0);
	return 0;
}
 
void find(int num, int last) {
	int i;
	if (num == M) { // 수열이 최대 길이에 도달하면 모든 수열의 수를 출력하고 완결 하고 끝냄
		for (i = 0; i < M; i++)
			printf("%d ", arr[i] + 1);
		printf("\n");
	}
	else {
        // 처음에는 해당 경우가 실행됨
        // find함수는 재귀 특성을 지녀서 한번 실행하면 i 수열이 생김
		for (i = last; i < N; i++) {
			arr[num] = i;
			find(num + 1, i + 1);
		}
	}
}