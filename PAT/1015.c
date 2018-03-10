#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int change(int N, int radix){
    char digit[25];
    int count=0;
    int i, ans=0;
    memset(digit,0,sizeof(digit));
    while(N){
        digit[count++]=N%radix+'0';
        N/=radix;
    }
    for(i=0;i<=count-1;i++){
        ans*=radix;
        ans+=digit[i]-'0';
    }
    return ans;
}
int prime(int N){
    int i, flag=1;
    if(N<=1) return 0;
    if(N==2||N==3) return 1;
    for(i=2;i<=sqrt(N);i++){
        if(N%i==0) {flag=0;break;}
    }
    return flag;
}
int main(int argc, char *argv[]){
    int N, radix;
    int ans;
    scanf("%d",&N);
    while(N>0){
        scanf("%d",&radix);
        ans=change(N, radix);
        if(prime(ans)&&prime(N)) printf("Yes\n");
        else printf("No\n");
        scanf("%d",&N);
    }
    return 0;
}