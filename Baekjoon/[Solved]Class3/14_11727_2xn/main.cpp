#include <cstdio>
#pragma warning(disable: 4996)

int main()
{
	int dpArray[1001] = { 1,1,3 };
	int InputInt;
	scanf("%d", &InputInt);
	for (int i = 3; i <= InputInt; ++i) // Dynamic Programming
		dpArray[i] = (dpArray[i-1]+2*dpArray[i-2])%10007;
	printf("%d", dpArray[InputInt]);

	return 0;
}