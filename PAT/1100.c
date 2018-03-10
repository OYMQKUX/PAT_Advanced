#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int N;
char inp[10];
char first[13][5] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char second[13][5] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int mars_to_num(){
    int ans = 0;
    int flag = 0;
    char temp[5];
    if(strlen(inp) <= 4){
        for(int i = 0; i < 13; i++){
            if(strcmp(inp, first[i]) == 0){
              ans = i;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            for(int i = 0; i < 13; i++){
                if(strcmp(inp, second[i]) == 0){
                    ans = i * 13;
                    break;
                }
            }
        }
    }
    else{
      memcpy(temp, inp, 3);
        for(int i = 0; i < 13; i++){
            if(strcmp(temp, second[i]) == 0){
              ans = i * 13;
                break;
            }
        }
        memcpy(temp, inp + 4, 5);
        for(int i = 0; i < 13; i++){
            if(strcmp(temp, first[i]) == 0){
              ans += i;
                break;
            }
        }
    }
    return ans;
}
char *num_to_mars(){
  char *ans;
    int temp;
    if(strlen(inp) == 3) temp = (inp[0] - '0') *100 + (inp[1] - '0') *10 + (inp[2] - '0');
    else if(strlen(inp) == 2) temp = (inp[0] - '0') *10 + inp[1] - '0';
    else temp = inp[0] - '0';
    ans = (char *)malloc(10);
    if(temp / 13){
      strcpy(ans, second[temp / 13]);
        if(temp % 13){
        ans[3] = ' ';
        ans[4] = 0;
            strcpy(ans + 4, first[temp % 13]);
        }
    }
    else{
      strcpy(ans, first[temp]);
    }
    return ans;
}
int main(int argc, char *argv[]){
    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; i++){
      gets(inp);
        if(inp[0] >= '0' && inp[1] <= '9') printf("%s\n", num_to_mars());
        else printf("%d\n", mars_to_num());
    }
    return 0;
}