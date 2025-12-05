#include <cstdio>


/* 불기 연도를 서기 연도로 변환하는 문제 */
int main(){
    int bul_year,seo_year;
	while (1) {
		scanf("%d", &bul_year);
		if (bul_year >= 1000 && bul_year<= 3000) break;
		else printf("재입력\n");
	}
    seo_year = bul_year - 543;

    printf("%d", seo_year);

    return 0;
}