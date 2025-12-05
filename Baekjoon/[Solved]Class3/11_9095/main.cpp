#include <cstdio>

int main() {
	int num_case;
	int num_input = 0;
	int dpArray[12] = { 1, 1, 2,4 };

	scanf_s("%d", &num_case);
	for (int i = 0; i < num_case; i++)
	{
		scanf_s("%d", &num_input);
		for (int i = 4; i <= num_input; i++) // Dynamic Programming
			dpArray[i] = dpArray[i - 1] + dpArray[i - 2] + dpArray[i - 3];
		printf("%d\n", dpArray[num_input]);
	}

	return 0;
}