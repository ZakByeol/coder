#include <cstdio>

int main(){

    char id[51];

    fseek(stdin,0,SEEK_END);
    /* 백준에서는 fseek함수 사용하면 안되는 듯? */
    scanf("%s", id);

    printf("%s", id);
    printf("??" "!");
    /* trigraph ignored 삼중음자 */
    return 0;
}