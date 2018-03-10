#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char inp1[81];
char inp2[81];
char hash[128];
char output[81];
int count;
int main(){
    scanf("%s%s", inp1, inp2);
    for(int i = 0, j = 0; i < strlen(inp1); i++){
        if(inp1[i] != inp2[j]){
            if(!hash[inp1[i]]){
              if(inp1[i] >= 'a' && inp1[i] <= 'z'){
                  hash[inp1[i] + 'A' - 'a'] = 1;
                  output[count++] = inp1[i] + 'A' - 'a';
              }
              else if(inp1[i] >= 'A' && inp1[i] <= 'Z'){
                hash[inp1[i] + 'a' - 'A'] = 1;
                  output[count++] = inp1[i];
              }
              else{
                output[count++] = inp1[i];
              }
              hash[inp1[i]] = 1;
            }
        }
        else j++;
    }
    for(int i = 0; i < count; i++)
        printf("%c", output[i]);
    printf("\n");
    return 0;
}