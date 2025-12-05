#include <cstdio>

int main(){
    int X,N,a,b;
    int sum_price = 0;
    scanf("%d", &X);
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        sum_price = sum_price + a*b;
    }
    if (sum_price == X)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}