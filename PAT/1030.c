#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define INT_MAX 1<<30
int visited[500];
int dis[500];
int cost[500][500];
int road[500][500];
int min_cost[500];
int last[500];
int N;
int M;
int S;
int D;
int ans[500];
void Dijstra(){
    int index=-1;
    int i;
    int min;
    dis[S]=0;
    min_cost[S]=0;
    while(1){
        index=-1;
        min=INT_MAX;
        for(i=0;i<N;i++){
            if(dis[i]<min&&!visited[i]){
                index=i;
                min=dis[i];
                break;
            }
        }
        visited[index]=1;
        if(index==-1) break;
        for(i=0;i<N;i++){
            if(!visited[i]){
                if(road[i][index]+dis[index]<dis[i]){
                    dis[i]=road[i][index]+dis[index];
                    min_cost[i]=cost[i][index]+min_cost[index];
                    last[i]=index;
                }
                else if(road[i][index]+dis[index]==dis[i]){
                    if(min_cost[i]>cost[i][index]+min_cost[index]){
                        min_cost[i]=cost[i][index]+min_cost[index];
                        last[i]=index;
                    }
                }
            }
        }
    }
}
int main(int argc, char *argv[]){
    int i, j;
    int a, b;
    scanf("%d%d%d%d",&N,&M,&S,&D);
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            road[i][j]=INT_MAX;
            cost[i][j]=INT_MAX;
        }
        dis[i]=INT_MAX;
        last[i]=i;
    }
    for(i=0;i<M;i++){
        scanf("%d%d",&a,&b);
        scanf("%d%d",&road[a][b],&cost[a][b]);
        road[b][a]=road[a][b];
        cost[b][a]=cost[a][b];
    }
    Dijstra();
    i=D;
    j=0;
    ans[j++]=i;
    while(i!=S){
        i=last[i];
        ans[j++]=i;
    }
    for(j--;j>=0;j--) printf("%d ",ans[j]);
    printf("%d %d\n",dis[D],min_cost[D]);
    return 0;
}