#include <stdio.h>

int main(){
    int A,B;
    int result;
    
    /* 조건 충족까지 반복 */
	while (1) {
        fseek(stdin,0,SEEK_END);
		scanf("%d %d", &A, &B);
		if ((A>=1 && A<= 10000)&&(B>=1 && B<=10000)) break;
		else printf("재입력\n");
	}
    /* 사칙연산 반복문 */
    for (int i = 0; i <5; i++)
    {
        switch (i)
        {
        case 0:
            result = A+B;
            printf("%d\n", result);
            continue;
        case 1:
            result = A-B;
            printf("%d\n", result);
            continue;
        case 2:
            result = A*B;
            printf("%d\n", result);
            continue;
        case 3:
            result = (int)(A/B);
            printf("%d\n", result);
            continue;
        case 4:
            result = A%B;
            printf("%d", result);
            break;
        
        }
    }
    return 0;
}

int correct_main(){
    int A, B;
    scanf("%d %d", &A, &B);
    printf("%d\n", A+B);
    printf("%d\n", A-B);
    printf("%d\n", A*B);
    printf("%d\n", A/B);
    printf("%d", A%B);
 
    
return 0;
}