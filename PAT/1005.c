#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(int argc, char *argv[]){
    char inp[101];
    char ans[101];
    int i, sum=0, rev_sum=0;
    scanf("%s",inp);
    for(i=0;i<strlen(inp);i++) sum+=inp[i]-'0';
    i=0;
    while(sum){
        ans[i++]=sum%10+'0';
        sum/=10;
    }
    ans[i]=0;
    i--;
    while(i>=1){
        switch(ans[i]){
                case '1': printf("one "); break;
                case '2': printf("two "); break;
                case '3': printf("three "); break;
                case '4': printf("four "); break;
                case '5': printf("five "); break;
                case '6': printf("six "); break;
                case '7': printf("seven "); break;
                case '8': printf("eight "); break;
                case '9': printf("nine "); break;
                default: printf("zero "); break;
        }
        i--;
    }
    switch(ans[i]){
        case '1': printf("one\n"); break;
        case '2': printf("two\n"); break;
        case '3': printf("three\n"); break;
        case '4': printf("four\n"); break;
        case '5': printf("five\n"); break;
        case '6': printf("six\n"); break;
        case '7': printf("seven\n"); break;
        case '8': printf("eight\n"); break;
        case '9': printf("nine\n"); break;
        default: printf("zero\n"); break;
    }
    return 0;
}