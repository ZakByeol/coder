#include <cstdio>
#pragma warning(disable: 4996)

int main()
{
	int dpArray[1001] = { 0,1,2 };
	int InputInt;
	scanf("%d", &InputInt);
	for (int i = 3; i <= InputInt; ++i) // dynamic programming
		dpArray[i] = (dpArray[i - 1] + dpArray[i - 2]) % 10007; // prevent Overflow by using mod
	printf("%d", dpArray[InputInt] );

	return 0;
}