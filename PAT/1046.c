#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define INT_MAX 2<<29
int total;
int ans;
int N;
int M;
int dis[100001];
int main(int argc, char *argv[]){
    int i, num1, num2;
    scanf("%d",&N);
    for(i=1;i<=N;i++) {scanf("%d",&dis[i]);total+=dis[i];dis[i]=total;}
    scanf("%d",&M);
    for(i=0;i<M;i++){
        scanf("%d%d",&num1,&num2);
        if(num1>num2) ans=dis[num1-1]-dis[num2-1];
        else ans=dis[num2-1]-dis[num1-1];
        if(ans<total-ans) printf("%d\n",ans);
        else printf("%d\n",total-ans);
    }
}