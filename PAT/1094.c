#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int id;
  int level;
    struct node *next;
}node[100];
int N;
int M;
int level[100];
int max;
int Index;
void BFS(int Node, int level){
  struct node *temp;
    temp = node[Node].next;
    while(temp){
      node[temp->id].level = level + 1;
        temp = temp -> next;
    }
  temp = node[Node].next;
    while(temp){
      BFS(temp->id, level + 1);
        temp = temp -> next;
    }
}
int main(){
    int ID;
    int K;
    struct node *temp = NULL;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
      scanf("%d", &ID);
        scanf("%d", &K);
        for(int j = 0; j < K; j++){
          temp = (struct node*)malloc(sizeof(struct node));
            scanf("%d", &temp->id);
            temp -> next = node[ID].next;
            node[ID].next = temp;
        }
    }
    node[1].level = 1;
    BFS(1, 1);
    for(int i = 1; i <= N; i++){
      level[node[i].level]++;
        if(level[node[i].level] > max){
          max = level[node[i].level];
            Index = node[i].level;
        }
    }
    printf("%d %d\n", max, Index);
    return 0;
}