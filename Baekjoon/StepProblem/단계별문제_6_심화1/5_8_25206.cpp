#include <cstdio>

int main()
{
    char Lec_Name[50];
    float Lec_Credit,SumCredit = 0, CreditGrade_Num = 0;
    char Lec_Grade[2];
    float Changed_Grade;


    for (int i = 0; i < 20; ++i) {
        scanf("%s %f %s", Lec_Name, &Lec_Credit, Lec_Grade);
        if (Lec_Grade[0] == 'P') continue; // 평점이 P이면, 넘어가기
        SumCredit += Lec_Credit;
        if (Lec_Grade[0] == 'F') continue; // 평점이 F이면, 넘어가기 >> F의 평점이 0 이기 때문임


        // 앞 글자의 따라서 1.0 간격으로 할당함
        if (Lec_Grade[0] == 'A') Changed_Grade = 4.0f;
        else if (Lec_Grade[0] == 'B') Changed_Grade = 3.0f;
        else if (Lec_Grade[0] == 'C') Changed_Grade = 2.0f;
        else Changed_Grade = 1.0f;

        // 뒷 글자가 + 이면, 0.5f 만큼 증가
        if (Lec_Grade[1] == '+') Changed_Grade += 0.5f;

        // 마지막 계산
        CreditGrade_Num += Lec_Credit * Changed_Grade;
    }

    printf("%.6f", CreditGrade_Num/SumCredit);


    return 0;
}