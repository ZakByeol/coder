
#include <stdio.h>

long long arr[2][2] = { { 1, 1 }, { 1, 0 } };
long long result[2][2] = { { 1, 0 }, { 0, 1 } };


void PowMatrix(long long a[2][2], long long b[2][2]) {
	long long temp[2][2];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
			temp[i][j] = 0;
			for (int h = 0; h < 2; h++)
				temp[i][j] += a[i][h] * b[h][j];
			temp[i][j] %= 1000000007;
		}

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			a[i][j] = temp[i][j];
}


int main(int argc, char *argv[]) {
	long long n;
	scanf("%lld", &n);

	while (n > 0) {
		if (n % 2 == 1) // 홀수라면
			PowMatrix(result, arr);
		PowMatrix(arr, arr);
		n /= 2;
	}

    printf("%lld", result[0][1]);

	return 0;
}

/*
                                n
[Fn+1    Fn  ]          [1   1]
[Fn      Fn-1]   =      [1   0]



*/