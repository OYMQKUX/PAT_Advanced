#include <stdio.h>
struct node{
    int value;
  int next;
    int previous;
}node[100010];
int head;
int N;
int K;
int main(int argc, char *argv[]){
    int temp;
    int temp1 = head, temp2 = head;
    scanf("%d%d%d", &head, &N, &K);
    for(int i = 0; i < N; i++){
      scanf("%d", &temp);
        scanf("%d%d", &node[temp].value, &node[temp].next);
        if(node[temp].next != -1)
            node[node[temp].next].previous = temp;
    }
    N = 0;
    temp = head;
    while(temp != -1){
      temp = node[temp].next;
        N++;
    }
    if(N >= K){
      temp1 = head;
      temp = head;
      for(int i = 1; i < K; i++){
        temp = node[temp].next;
        }
      head = temp;
      temp2 = node[temp].next;
      for(int i = 1; i < K; i++){
        node[temp].next = node[temp].previous;
            temp = node[temp].next;
      }
        N -= K;
    }
    while(N >= K){
        temp = temp2;
        for(int i = 1; i < K; i++){
          temp = node[temp].next;
        }
        node[temp1].next = temp;
        temp2 = node[temp].next;
        for(int i = 1; i < K; i++){
          node[temp].next = node[temp].previous;
            temp = node[temp].next;
        }
        temp1 = temp;
        N -= K;
    }
    node[temp1].next = temp2;
    temp = head;
    while(temp != -1){
        if(node[temp].next != -1){
            printf("%05d %d %05d\n", temp, node[temp].value, node[temp].next);
        }
        else{
            printf("%05d %d %d\n", temp, node[temp].value, node[temp].next);
        }
        temp = node[temp].next;
    }
    return 0;
}