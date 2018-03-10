#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int N;
char inp[101][256];
char LCS[256];
int temp_count;
int count;
void reverse(char *inp){
    char temp;
    for(int i = 0; i < strlen(inp)/2; i++){
      temp = inp[i];
        inp[i] = inp[strlen(inp) - i - 1];
        inp[strlen(inp) - i - 1] = temp;
    }
}
int main(int argc, char *argv[]){
    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; i++){
      gets(inp[i]);
        reverse(inp[i]);
    }
    for(int i = 0; i < strlen(inp[0]) && i < strlen(inp[1]); i++){
        if(inp[0][i] == inp[1][i]){
          LCS[temp_count++] = inp[0][i];
        }
        else break;
    }
    count = temp_count;
    if(count){
      for(int i = 2; i < N; i++){
          temp_count = 0;
          for(int j = 0; j < count; j++){
              if(inp[i][j] == LCS[j]){
                temp_count++;
              }
              else break;
          }
          count = temp_count;
          if(!count) break;
      }
    }
    LCS[count] = 0;
    reverse(LCS);
    if(count) printf("%s\n", LCS);
    else printf("nai\n");
    return 0;
}