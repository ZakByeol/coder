//#include <stdio.h>
//#pragma warning(disable: 4996)
//
//int minhArray[100001] = { 0, }; // Minimum Heap Array 1~100000
//int vNowIdx = 1;
//
//void ChangeElement(int* _pArray1, int* _pArray2) // Change Element by using pointer
//{
//	int tmp = *_pArray1;
//	*_pArray1 = *_pArray2;
//	*_pArray2 = tmp;
//}
//
//void minhAdd(int _vAdd) // MinHeap Add element
//{
//	int temp_idx = vNowIdx;
//	int temp;
//	minhArray[vNowIdx++] = _vAdd;
//	while (temp_idx > 1) {
//		if (minhArray[temp_idx / 2] > minhArray[temp_idx]) {
//			temp = minhArray[temp_idx / 2];
//			minhArray[temp_idx / 2] = minhArray[temp_idx];
//			minhArray[temp_idx] = temp;
//			temp_idx /= 2;
//		}
//		else {
//			break;
//		}
//	}
//}
//
//void heapfify(int i) {
//	// i : idx
//	int left = 2 * i;
//	int right = 2 * i + 1;
//	int smallest = i;
//	int temp;
//
//	// find smallest
//	if (left < vNowIdx && minhArray[left] < minhArray[smallest])
//		smallest = left;
//	if (right < vNowIdx && minhArray[right] < minhArray[smallest])
//		smallest = right;
//
//	if (smallest != i) {
//		// swap
//		temp = minhArray[i];
//		minhArray[i] = minhArray[smallest];
//		minhArray[smallest] = temp;
//		heapfify(smallest);
//	}
//
//}
//
//int main(void) {
//	int N;
//	int temp;
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++) {
//		scanf("%d", &temp);
//		if (temp == 0) {
//			if (vNowIdx == 1)
//			{
//				printf("0\n");
//			}
//			else 
//			{
//				printf("%d\n", minhArray[1]);
//				minhArray[1] = minhArray[vNowIdx - 1]; // remove
//				heapfify(1);
//				vNowIdx -= 1;
//			}
//		}
//		else
//			minhAdd(temp);
//	}
//
//
//
//
//	return 0;
//}
