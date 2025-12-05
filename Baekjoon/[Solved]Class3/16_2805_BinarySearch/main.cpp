#include <iostream>
#pragma warning(disable: 4996)



int Output(const int* _vlen, const long long* _vCut)
{
	if (*_vlen >= *_vCut)
	{
		return *_vlen - *_vCut;
	}
	else
	{
		return 0;
	}
}

int main()
{
    int vAmount, vBring;
	int i;
    int* listTree;
    long long vMin = 0;
    long long vMid = 1;
	long long vMax = 0;
	long long vGain, max, ResultLen;

    scanf("%d %d", &vAmount, &vBring);
    listTree = (int*)calloc(vAmount, sizeof(int));

    for (i = 0, max = 0; i < vAmount; i++) // 나무 길이 입력 및 가장 최장 길이의 나무 저장
    {
        scanf(" %d", listTree + i);

        if (vMax < listTree[i])
        {
            vMax = listTree[i];
        }
    }

    ResultLen = 0;
    while (vMin <= vMax)
    {
        vMid = (vMin + vMax) / 2; // 중간 길이

		// vGain 초기화 및 잘린 나무들 저장
        for (i = 0, vGain = 0; i < vAmount; i++)
        {
            vGain += Output(listTree + i, &vMid);
        }

        
        if (vGain < vBring) // 목적량 미달성 -> 절단 높이 낮춤
        {
            vMax = vMid - 1;
        }
        else // 목적량 달성 -> 절단 높이 올림
        {
            //절단기의 최대높이 갱신
            if (ResultLen < vMid)
            {
                ResultLen = vMid;
            }
            vMin = vMid + 1;
        }
    }

    printf("%lld\n", ResultLen);

    free(listTree);
    return 0;
}