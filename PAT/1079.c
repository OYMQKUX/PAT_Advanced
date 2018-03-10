#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int N;
double P;
double r;
double ans;
int retailer[100000];
int count;
struct node{
    int num;
    int pro;
    double price;
    struct node *next;
}node[100000];
void BFS(int x){
  struct node *temp;
    temp = node[x].next;
    while(temp){
      node[temp->num].price = node[x].price * (1.0 + r / 100.0);
        temp = temp->next;
    }
    temp = node[x].next;
    while(temp){
      BFS(temp->num);
        temp = temp->next;
    }
}
int main(int argc, char *argv[]){
    int K_i;
    int id;
    struct node *temp1, *temp2;
    scanf("%d%lf%lf", &N, &P, &r);
    for(int i = 0; i < N; i++){
        temp1 = &node[i];
      scanf("%d", &K_i);
        for(int j = 0; j < K_i; j++){
            temp2 = (struct node*)malloc(sizeof(struct node));
            temp2->next = NULL;
          scanf("%d", &id);
            temp2->num = id;
            temp1->pro = -1;
            temp1->next = temp2;
            temp1 = temp1->next;
        }
        if(!K_i){
            scanf("%d", &temp1->pro);
          retailer[count++] = i;
        }
    }
    node[0].price = P;
    BFS(0);
    for(int i = 0; i < count; i++){
      ans += node[retailer[i]].price * node[retailer[i]].pro;
    }
    printf("%.1lf\n", ans);
    return 0;
}