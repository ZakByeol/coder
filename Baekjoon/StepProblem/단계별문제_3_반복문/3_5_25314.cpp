#include <cstdio>

int main(){

    int N;

    fseek(stdin, 0,SEEK_END); // 백준에서 이거 지워야함
    scanf("%d", &N);

    int result_n = int(N/4);

    for (int i = 0; i < result_n; i++)
    {
        printf("long ");
        if (i==result_n-1)
        {
            printf("int");
            break;
        }
        
    }
    return 0;
}
