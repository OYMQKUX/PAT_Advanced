#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define infinity 2147483647
#define max 501
struct path{
    int size;//表示相同最短路径条数（如size=1表示只有一条最短路径）
    int vertex[max];//用来存放最短路径中上一个定点（包含相同最短路径）
}path [max];//建立一个结构数组用来存放每个点的最短路径信息
int dis[max];//
int visited[max];//表示某个点是否被访问过
int tmp_vertax[max],top=0;//最短路径
int min_path_vertex[max],v=0;//符合题意的最短路径
int C_max,N,S_p,M;//四个参数
int C[max];//每个站自行车数量
int T[max][max];//相邻站所需时间
int Send=infinity,collect=infinity;//送出数量、取回数量
void Dijkstra();//找出所有最短路径
void Dfs(int S_p);//找出相同最短路径中符合题意的路径
void Print_path();//输出答案
void Scan_parameter();//第一行及第二行输入
void Scan_T();//后M行输入
void Initial_visited_T();//初始化visited和T数组
void Initial_path_dist();//初始化path和dist数组
int main(int argc, const char * argv[]) {
    Scan_parameter();
    Initial_visited_T();
    Scan_T();
    Initial_path_dist();
    visited[0]=1;
    Dijkstra();
    Dfs(S_p);
    Print_path();
}
void Scan_parameter(){
    int i;
    scanf("%d%d%d%d",&C_max,&N,&S_p,&M);
    for(i=1;i<=N;i++) scanf("%d",&C[i]);
}
void Scan_T(){
    int i,j,k,l;
    for(l=1;l<=M;l++){
        scanf("%d%d%d",&i,&j,&k);
        T[i][j]=T[j][i]=k;
    }
}
void Initial_visited_T(){
    int i,j;
    memset(visited,0,sizeof(visited));//将visited数组全部置零
    for(i=0;i<=N;i++)
        for(j=0;j<=N;j++)
            if(i==j) T[i][j]=0;
            else T[i][j]=infinity;//初始化T数组
}
void Initial_path_dist(){
    int i;
    for(i=0;i<=N;i++) memset(path[i].vertex,-1,sizeof(path[i].vertex));//所有path结构中vertex数组全部赋值-1
    for(i=0;i<=N;i++){
        dis[i]=T[0][i];
        if(i&&dis[i]!=infinity) path[i].vertex[path[i].size++]=0;//对所有与PMBC邻接的站赋值
    }
}
void Dijkstra(){
    int i,j,k=0;
    int min_dis=infinity;
    for(i=1;i<=N;i++){
        min_dis=infinity;
        for(j=0;j<=N;j++)
            if(visited[j]==0&&dis[j]<min_dis){min_dis=dis[j];k=j;}//找出所有未访问点中距离最小的点
        visited[k]=1;//该点已经访问过
        for(j=0;j<=N;j++){
            if(visited[j]==0&&T[k][j]!=infinity){
                if(dis[j]>dis[k]+T[k][j]){
                    dis[j]=dis[k]+T[k][j];
                    path[j].vertex[0]=k;
                    path[j].size=1;
                }//假如未访问的点的距离不是最短，则将其置为最短并将其上一个点的值和路径数目改变
                else if(dis[j]==dis[k]+T[k][j])
                    path[j].vertex[path[j].size++]=k;//若发现相同且最短距离，则将最短路径数目增加1
            }
        }
    }
}
void Dfs(int S_p){
    int i;
    tmp_vertax[top++]=S_p;//最短路径点储存
    if(S_p==0)//若找到了起点0
    {
        int s=0,c=0;//送出数量、取回数量
        for(i=top-2;i>=0;i--)//总收回取出数量计算
        {
            c+=-C_max/2+C[tmp_vertax[i]];//当前站应该收回的数量
            if(c<0){
                s+=-c;//收回数量为负值表示应该送出
                c=0;
            }
        }
        if(s<Send||(s==Send&&c<collect))//找到取回PMBC数量最少
        {
            collect=c;
            Send=s;
            v=0;
            for(i=top-1;i>=0;i--) min_path_vertex[v++]=tmp_vertax[i];
        }
        return;
    }
    for(i=0;i<path[S_p].size;i++) {Dfs(path[S_p].vertex[i]);top--;}//对每条相同距离路径进行计算
}
void Print_path(){
    int i;
    printf("%d ",Send);//输出送出值
    for(i=0;i<v-1;i++) printf("%d->",min_path_vertex[i]);//输出除最后一个点之外的路径
    printf("%d %d",S_p,collect);//输出最后一个点和取回值
}