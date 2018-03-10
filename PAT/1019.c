#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define INT_MAX 1<<30
int main(int argc, char *argv[]){
    int N, b;
    scanf("%d%d",&N, &b);
    int digit[30]={0};
    int pos=0, flag=1;
    while(N){
        digit[pos++]=N%b;
        N/=b;
    }
    for(int i=0;i<pos/2;i++){
        if(digit[i]!=digit[pos-i-1]) {flag=0;break;}
    }
    if(flag) printf("Yes\n");
    else printf("No\n");
    for(int i=pos-1;i>=1;i--) printf("%d ",digit[i]);
    printf("%d\n",digit[0]);
    return 0;
}