#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define INT_MAX 1<<30
int N;
int M;
int S;
int count;
int ans[100];
struct answer{
  int num;
  char str[100];
};
struct node{
  int num;
  int weight;
  int father;
  int child[100];
  int total;
};
struct node node[100];
struct answer answer[100];
void DFS(int Node){
  int i;
  if(node[Node].num==0){
    if(node[Node].total==S) ans[count++]=Node;
    return;
  }
  for(i=0;i<node[Node].num;i++){
    node[node[Node].child[i]].total=node[node[Node].child[i]].weight+node[Node].total;
    DFS(node[Node].child[i]);
  }
}
int cmp(const void *a, const void *b){
  struct answer *c, *d;
  c=(struct answer*)a;
  d=(struct answer*)b;
  return strcmp(d->str,c->str);
}
int main(int argc, char *argv[]){
  int temp;
  int i, j;
  scanf("%d%d%d",&N,&M,&S);
  for(i=0;i<N;i++) scanf("%d",&node[i].weight);
  for(i=0;i<M;i++){
    scanf("%d",&temp);
    scanf("%d",&node[temp].num);
    for(j=0;j<node[temp].num;j++){
      scanf("%d",&node[temp].child[j]);
      node[node[temp].child[j]].father=temp;
    }
  }
  node[0].total=node[0].weight;
  node[0].father=-1;
  DFS(0);
  for(i=0;i<count;i++){
    temp=ans[i];
    while(temp!=-1){
      answer[i].str[answer[i].num++]=node[temp].weight;
      temp=node[temp].father;
    }
    answer[i].str[answer[i].num]=0;
  }
  for(i=0;i<count;i++){
    for(j=0;j<strlen(answer[i].str)/2;j++){
      temp=answer[i].str[j];
      answer[i].str[j]=answer[i].str[strlen(answer[i].str)-1-j];
      answer[i].str[strlen(answer[i].str)-1-j]=temp;
    }
  }
  qsort(answer, count, sizeof(answer[0]), cmp);
  for(i=0;i<count;i++){
    printf("%d",answer[i].str[0]);
    for(j=1;j<answer[i].num;j++)
      printf(" %d",answer[i].str[j]);
    printf("\n");
  }
  return 0;
}