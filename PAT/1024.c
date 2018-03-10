#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char ans[100];
char *Process(char *N){
    char temp[100];
    int carry=0;
    memset(temp,0,sizeof(temp));
    memset(ans,0,sizeof(ans));
    long i;
    for(i=strlen(N)-1;i>=0;i--){
        temp[i]=(N[i]+N[strlen(N)-1-i]+carry-'0'-'0')%10+'0';
        carry=(N[i]+N[strlen(N)-1-i]+carry-'0'-'0')/10;
    }
    if(carry) {strcpy(ans+1,temp);ans[0]='1';}
    else strcpy(ans,temp);
    return ans;
}
int Palindromic(char *N){
    int i;
    for(i=0;i<strlen(N)/2;i++){
        if(N[i]!=N[strlen(N)-i-1]) break;
    }
    if(i!=strlen(N)/2) return 0;
    else return 1;
}
int main(int argc, char *argv[]){
    char N[100];
    int K;
    int count=0;
    memset(N,0,sizeof(N));
    scanf("%s",N);
    getchar();
    scanf("%d",&K);
    while(1){
        if(!Palindromic(N)&&count<K) {strcpy(N,Process(N));count++;}
        else {printf("%s\n%d\n",N,count);break;}
    }
}