#include <cstdio>
#include  <cstdlib>
#pragma warning(disable: 4996)


int main()
{
	int* sum_arr = nullptr;
	int* num_arr = nullptr;
	int case_num, case_sum;

	scanf("%d %d", &case_num, &case_sum);

	sum_arr = (int*)calloc(case_num + 1, sizeof(int));
	num_arr = (int*)calloc(case_num + 1, sizeof(int));


	// 윈도우 슬라이딩 기법
	for (int i = 1; i <= case_num; i++) // ex) 1~4 => 1~3 + 4
	{
		scanf("%d ", num_arr + i);
		sum_arr[i] = sum_arr[i - 1] + num_arr[i]; 
	}

	for (int i = 0; i < case_sum; ++i)
	{
		int range_i, range_j;
		scanf("%d %d", &range_i, &range_j);
		printf("%d\n", sum_arr[range_j] - sum_arr[range_i-1]);
	}

	free(sum_arr);
	free(num_arr);
	return 0;
}