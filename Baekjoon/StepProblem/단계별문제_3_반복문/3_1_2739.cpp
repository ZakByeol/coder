#include <cstdio>

int main(){
    int input_value;
    scanf("%d", &input_value);
    for (int i = 1; i <= 9; i++)
    {
        printf("%d * %d = %d\n", input_value, i,input_value*i);
    }
    
}