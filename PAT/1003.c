#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INT_MAX 1<<28
int M, N, C1, C2;
int rescue[501];
int road[501][501];
int dis[501];
int visited[501];
int road_count[501];
int rescue_count[501];
void INITIALIZE(){
    int i,j;
    for(i=0; i<501;i++)
        for(j=0;j<501;j++){
            road[i][j]=INT_MAX;
        }
    for(i=0;i<501;i++) dis[i]=INT_MAX;
    memset(visited,0,sizeof(int)*501);
    memset(road_count,0,sizeof(int)*501);
    memset(rescue_count,0,sizeof(int)*501);
}
void dijstra(){
    int i,j,temp=C1;
    int min;
    dis[C1]=0;
    road_count[C1]=1;
    rescue_count[C1]=rescue[C1];
    for(;;){
        temp=-1;
        min=INT_MAX;
        for(j=0;j<N;j++) if(visited[j]==0&&dis[j]<min) {min=dis[j];temp=j;}
        if(temp==-1) break;
        visited[temp]=1;
        for(i=0;i<N;i++){
            if(visited[i]==0){
                if(dis[i]>dis[temp]+road[temp][i]){
                    dis[i]=dis[temp]+road[temp][i];
                    road_count[i]=road_count[temp];
                    rescue_count[i]=rescue_count[temp]+rescue[i];
                }
                else if(dis[i]==dis[temp]+road[temp][i]){
                    road_count[i]+=road_count[temp];
                    rescue_count[i]=rescue_count[temp]+rescue[i]>rescue_count[i]?rescue_count[temp]+rescue[i]:rescue_count[i];
                }
            }
        }
    }
}
int main(int argc, char *argv[]){
    int i;
    int fro, to;
    INITIALIZE();
    scanf("%d%d%d%d",&N, &M, &C1, &C2);
    for(i=0;i<N;i++) scanf("%d",&rescue[i]);
    for(i=0;i<M;i++){
        scanf("%d%d",&fro, &to);
        scanf("%d",&road[fro][to]);
        road[to][fro]=road[fro][to];
    }
    /*for(i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%d       \t",road[i][j]);
        printf("\n");
    }*/
    dijstra();
    printf("%d %d\n",road_count[C2],rescue_count[C2]);
    return 0;
}