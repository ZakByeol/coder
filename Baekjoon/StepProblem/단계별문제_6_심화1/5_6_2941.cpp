#include <cstdio>
#include <cstring>

int GetAlpaCount(char Input[]){
    int count = strlen(Input) - 1;
    int result_count = 0;
    for (int i = 0; i <= count; ++i) {
        if (Input[i] != '0')
        {
            result_count += 1;
            continue;
        }
    }
    return result_count;
}
int main(){
/*
 * 반복문으로 입력값 전체를 스캔함, 이후에 크로아티아 알파벳을
    각각 돌려보고 해당 변경 알파벳을 제외한 문자열을 할당하는 방식*/

    char Input_Char[100];
    int Croatia_count = 0;

    scanf("%s", Input_Char);
    int Input_count = int(strlen(Input_Char)) - 1;
    for (int i = 0; i <= Input_count; ++i) {
        if (Input_Char[i] == 'c' && Input_Char[i+1] == '=')
        {
            Croatia_count += 1;
            Input_Char[i] = '0';
            Input_Char[i+1] = '0';
        }
        if (Input_Char[i] == 'c' && Input_Char[i+1] == '-')
        {
            Croatia_count += 1;
            Input_Char[i] = '0';
            Input_Char[i+1] = '0';
        }
        if (Input_Char[i] == 'd' && Input_Char[i+1] == 'z' && Input_Char[i+2] == '=')
        {
            Croatia_count += 1;
            Input_Char[i] = '0';
            Input_Char[i+1] = '0';
            Input_Char[i+2] = '0';
        }
        if (Input_Char[i] == 'd' && Input_Char[i+1] == '-')
        {
            Croatia_count += 1;
            Input_Char[i] = '0';
            Input_Char[i+1] = '0';
        }
        if (Input_Char[i] == 'l' && Input_Char[i+1] == 'j')
        {
            Croatia_count += 1;
            Input_Char[i] = '0';
            Input_Char[i+1] = '0';
        }
        if (Input_Char[i] == 'n' && Input_Char[i+1] == 'j')
        {
            Croatia_count += 1;
            Input_Char[i] = '0';
            Input_Char[i+1] = '0';
        }
        if (Input_Char[i] == 's' && Input_Char[i+1] == '=')
        {
            Croatia_count += 1;
            Input_Char[i] = '0';
            Input_Char[i+1] = '0';
        }
        if (Input_Char[i] == 'z' && Input_Char[i+1] == '=')
        {
            Croatia_count += 1;
            Input_Char[i] = '0';
            Input_Char[i+1] = '0';
        }
    }

    printf("%d", GetAlpaCount(Input_Char)+Croatia_count);
    return 0;
}