#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define INT_MAX 1<<30
int main(int argc, char *argv[]){
    char inp[81];
    long n1, n2, n3;
    int i, j;
    long len;
    scanf("%s",inp);
    len=strlen(inp)+2;
    if(len%3==0){
        n1=n2=n3=len/3;
    }
    else if(len%3==1){
        n2=len/3+1;
        n1=n3=(len-n2)/2;
    }
    else{
        n2=len/3+2;
        n1=n3=(len-n2)/2;
    }
    for(i=0;i<n1-1;i++){
        printf("%c",inp[i]);
        for(j=0;j<n2-2;j++)
            printf(" ");
        printf("%c\n",inp[strlen(inp)-1-i]);
    }
    //printf("n1=%ld n2=%ld n3=%ld\n",n1,n2,n3);
    for(;i<n1+n2-1;i++) printf("%c",inp[i]);
    printf("\n");
    return 0;
}