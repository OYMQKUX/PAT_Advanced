#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char inp[1001];
int isSym(char *str, int len){
    for(int i=0;i<=len/2-1;i++)
        if(str[i]!=str[len-i-1]) return 0;
    return 1;
}
int main(int argc, char *argv[]){
    int max=1;
    gets(inp);
    for(int i=0;i<strlen(inp)-1;i++)
        for(int j=i+1;j<strlen(inp);j++)
            if(isSym(inp+i,j-i+1)&&j-i+1>max) max=j-i+1;
    printf("%d\n",max);
    return 0;
}