#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MaxVertex 10001
int visited[MaxVertex];
int Union[MaxVertex];
int deep[MaxVertex];
int ans[MaxVertex];
int count;
int deepest;
typedef int VertexType;
typedef int EdgeType;
typedef struct node{
    int adjvex;
    EdgeType weight;
    struct node *next;
}EdgeNode;
typedef struct VertexNode{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode;
typedef VertexNode AdjList[MaxVertex];
typedef struct{
    AdjList adjList;
    int numNodes;
    int numEdges;
}GraphAdjList;
int cmp(const void *a, const void *b){
    return *(int *)a-*(int *)b;
}
int find(int a){
    return Union[a]==a?a:find(Union[a]);
}
void merge(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b) Union[a]=b;
}
GraphAdjList CreateGraph(GraphAdjList GL){
    int i, a, b;
    EdgeNode *temp1, *temp2;
    scanf("%d",&GL.numNodes);
    GL.numEdges=GL.numNodes-1;
    for(i=0;i<=GL.numNodes;i++) Union[i]=i;
    for(i=0;i<=GL.numNodes;i++){
        GL.adjList[i].data=i;
        GL.adjList[i].firstedge=NULL;
    }
    for(i=0;i<GL.numEdges;i++){
        scanf("%d%d",&a, &b);
        merge(a,b);
        temp1=(EdgeNode*)malloc(sizeof(EdgeNode));
        temp2=(EdgeNode*)malloc(sizeof(EdgeNode));
        temp1->adjvex=b;
        temp1->weight=1;
        temp2->adjvex=a;
        temp2->weight=1;
        temp1->next=GL.adjList[a].firstedge;
        temp2->next=GL.adjList[b].firstedge;
        GL.adjList[a].firstedge=temp1;
        GL.adjList[b].firstedge=temp2;
    }
    return GL;
}
void Initialize(GraphAdjList GL){
    memset(visited,0,sizeof(visited));
    memset(deep,0,sizeof(deep));
    memset(ans,0,sizeof(ans));
}
void DFS(GraphAdjList GL,VertexNode root, int dis){
    EdgeNode *point=root.firstedge;
    if(dis>deepest){
        deepest=dis;
        memset(deep,0,sizeof(deep));
        count=0;
        deep[count++]=root.data;
    }
    else if(dis==deepest) deep[count++]=root.data;
    visited[root.data]=1;
    while(1){
        if(point==NULL) break;
        if(visited[point->adjvex]==0) DFS(GL,GL.adjList[point->adjvex],dis+1);
        point=point->next;
    }
    visited[root.data]=0;
}
int main(int argc, char *argv[]){
    GraphAdjList GL;
    GL=CreateGraph(GL);
    Initialize(GL);
    for(int i=1;i<=GL.numNodes;i++) if(Union[i]==i) count++;
    if(count>1) printf("Error: %d components\n",count);
    else{
        int i;
        count=0;
        DFS(GL,GL.adjList[1],0);
        for(i=0;i<count;i++) ans[i]=deep[i];
        int temp=i;
        count=0;
        DFS(GL,GL.adjList[deep[temp-1]],0);
        for(i=0;i<count;i++) ans[temp++]=deep[i];
        qsort(ans,temp,sizeof(int),cmp);
        count=1;
        for(i=1;i<temp;i++) if(ans[i]!=ans[i-1]) ans[count++]=ans[i];
        for(i=0;i<count;i++) printf("%d\n",ans[i]);
    }
    return 0;
}