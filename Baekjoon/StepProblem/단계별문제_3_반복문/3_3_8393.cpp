#include <cstdio>

int main(){
    int n;
    int result = 0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        result = result + i;
    }
    printf("%d", result);
    return 0;
}