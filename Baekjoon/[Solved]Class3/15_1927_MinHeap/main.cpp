#include <iostream>
#pragma warning(disable: 4996)

int minhArray[100001];

void SwapElement(int* _pArray1, int* _pArray2) // Change Element by using pointer
{
	int tmp = *_pArray1;
	*_pArray1 = *_pArray2;
	*_pArray2 = tmp;
}

int main()
{
	int vCalculate; // case amount
	int vInput;
	int vAmount = 0; // inference array element amount
	int vNowIndex; // locate now index

	scanf("%d", &vCalculate);

	for (int i = 0; i<vCalculate; i++)
	{
		scanf("%d", &vInput);
		if (vInput > 0) // MinHeap Add element
		{
			vAmount++;
			vNowIndex = vAmount-1;
			minhArray[vNowIndex] = vInput;
			while (true)
			{
				if (vNowIndex == 0) // exception process
				{
					break;
				}

				if (minhArray[vNowIndex] < minhArray[ (vNowIndex-1) / 2]) // compare and change
				{
					SwapElement(minhArray + vNowIndex, minhArray + ( (vNowIndex-1) / 2) );
					vNowIndex = (vNowIndex-1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		else // MinHeap Delete Element
		{
			if (vAmount == 0) // initial case
			{
				printf("%d\n", minhArray[0]);
				continue;
			}

			// printf and remove process
			printf("%d\n", minhArray[0]);
			minhArray[0] = minhArray[vAmount-1]; 
			minhArray[vAmount-1] = 0;
			vAmount--;
			vNowIndex = 0;

			while (true)
			{
				int leftChild = 2 * vNowIndex + 1;
				int rightChild = 2 * vNowIndex + 2;
				int SwapIndex = vNowIndex;
				bool doSwap = false;

				// check smaller index
				if (leftChild < vAmount && minhArray[leftChild] < minhArray[SwapIndex])
				{
					SwapIndex = leftChild;
					doSwap = true;
				}
				if (rightChild < vAmount && minhArray[rightChild] < minhArray[SwapIndex ]) // 왼쪽보다 오른쪽이 더 작아짐!
				{
					SwapIndex = rightChild;
					doSwap = true;
				}

				if (doSwap) // Swap according to doSwap value
				{
					SwapElement(minhArray + vNowIndex, minhArray + SwapIndex);
					vNowIndex = SwapIndex;
				}
				else
				{
					break;
				}
			}
		}
	}
	return 0;
}