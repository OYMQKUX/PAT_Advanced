#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int road[2000*2000][2];
int pre[2000];
int Find(int x){
    return pre[x]==x?x:(pre[x]=Find(pre[x]));
}
void UNION(int x, int y){
    x=Find(x);
    y=Find(y);
    if(x==y) return;
    pre[y]=x;
}
int main(int argc, char *argv[]){
    int N, M, K;
    int i, j, a;
    int total;
    scanf("%d%d%d",&N,&M,&K);
    for(i=0;i<M;i++){
        scanf("%d%d",&road[i][0],&road[i][1]);
    }
    for(i=0;i<K;i++){
        scanf("%d",&a);
        for(j=0;j<=N;j++)
            pre[j]=j;
        for(j=0;j<M;j++)
            if(road[j][0]!=a&&road[j][1]!=a) UNION(road[j][0],road[j][1]);
        total=0;
        for(j=1;j<=N;j++) if(pre[j]==j&&j!=a) total++;
        printf("%d\n",total-1);
    }
    return 0;
}