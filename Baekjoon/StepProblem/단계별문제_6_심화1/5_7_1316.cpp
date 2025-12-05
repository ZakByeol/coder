#include <stdio.h>
#include <string.h>


 // 해당 문제는 직전의 문자와 다를 때, 해당 직진 문자는 앞으로 나오면 안됨



int main(){
    int Input_num,Input_len;
    int alphabet[26] = {0,}; // ASCII 사용한 알파벳 문자열 데이터
    int group_num = 0; // 출력될 그룹 단어의 수를 나타내는 변수

    char Input_word[101];
    scanf("%d", &Input_num);
    group_num = Input_num;

    for(int i=0; i<Input_num; i++){
        scanf("%s", Input_word);
        Input_len = strlen(Input_word); // 문자열 길이 # 반복 횟수에 사용

        //index 0 부터 a, b
        for(int j=0; j<26; j++){
            alphabet[j] = 0;
        }

        for(int k = 0; k < Input_len; k++)
        {
            if(alphabet[Input_word[k]-'a'] == 0){
                alphabet[Input_word[k]-'a'] += 1;
            }
            else{ //이미 0이 아니면, 바로 앞 문자 확인
                if (Input_word[k] == Input_word[k-1])
                {
                    continue;
                }
                else if(Input_word[k] != Input_word[k-1]) { // 이미 호출 되었으나 앞 문자와 다르면, 그룹 단어 X
                    group_num -= 1;
                    break;
                }
            }

            if(k== Input_len -1){ // 여기까지 문제가 없었다면, 그룹 단어 이다.
                break;
            }
        }
    }
    printf("%d", group_num);
    return 0;
}
/*

#include <stdio.h>
#include <string.h>

*/
/*
해당 문제는 직전의 문자와 다를 때, 해당 직진 문자는 앞으로 나오면 안됨
*//*



int main(){
    int Input_num,Input_len;
    int alphabet[26]; // ASCII 사용한 알파벳 문자열 데이터
    int group_num = 0; // 출력될 그룹 단어의 수를 나타내는 변수

    char Input_word[101];
    scanf("%d", &Input_num);


    for(int i=0; i<Input_num; i++){
        scanf("%s", Input_word);
        Input_len = strlen(Input_word); // 문자열 길이 # 반복 횟수에 사용


        //index 0 부터 a, b
        for(int j=0; j<26; j++){
            alphabet[j] = 0;
        }

        // 그룹 단어 도출
        for(int k = 0; k < Input_len; k++)
        {
            if(alphabet[Input_word[k]-'a'] == 0){
                alphabet[Input_word[k]-'a'] += 1;
            }
            else if (alphabet[Input_word[k]-'a'] != 0)
            { //이미 0이 아니면, 바로 앞 문자 확인
                if(Input_word[k-1] != Input_word[k]) // 이미 호출 되었으나 앞 문자와 다르면, 그룹 단어 X

                    break;
            }

            if(k== Input_len -1){ // 여기까지 문제가 없었다면, 그룹 단어 이다.
                group_num+=1;
            }
        }
    }
    printf("%d", group_num);
    return 0;
}*/
