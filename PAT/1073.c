#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char inp[20010];
char num1[10010];
char num2[10010];
char ans[20010];
int sign;
unsigned long len1;
unsigned long len2;
double num_1;
int num_2;
int main(int argc, char *argv[]){
    scanf("%s",inp);
    if(inp[0] == '+') sign = 1;
    else sign = -1;
    for(unsigned long i = 1; i < strlen(inp); i++){
        if(inp[i] == 'E'){
            len1 = i-1;
            break;
        }
    }
    len2 = strlen(inp) - len1 - 3;
    memcpy(num1, inp + 1, sizeof(char) * len1);
    memcpy(num2, inp + len1 + 3, sizeof(char) * len2);
    num_1 = atof(num1);
    num_2 = atoi(num2);
    if(num_2 == 0) printf("%s\n", num1);
    else{
      if(inp[len1+2] == '-'){
            if(sign == -1) printf("-");
        printf("0.");
            for(int i = 1; i < num_2; i++){
              printf("0");
            }
            for(int i = 0; i < len1; i++){
              if(num1[i] != '.') printf("%c", num1[i]);
            }
            printf("\n");
      }
      else{
            if(sign == -1) printf("-");
        printf("%c", num1[0]);
            if(num_2 >= len1 - 2){
              printf("%s", num1+2);
                for(int i = 1; i <= num_2 - len1 + 2; i++){
                  printf("0");
                }
                printf("\n");
            }
            else{
                for(int i = 1; i <= num_2; i++){
                  printf("%c", num1[i+1]);
                }
                printf(".");
                printf("%s", num1 + num_2 + 2);
                printf("\n");
            }
      }
    }
    return 0;
}