#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N;
int queue[100];
int inorder[100];
int inp[100];
int count;
int head, tail = 1;
int cmp(const void *a, const void *b){
  return *(int *)a - *(int *)b;
}
struct node{
  int value;
    int left;
    int right;
}node[100];
void Push(int i){
  queue[tail++] = i;
}
int Pop(){
     return queue[head++];
}
void Inorder(int i){
    if(node[i].left != -1){
      Inorder(node[i].left);
    }
    inorder[count++] = i;
    if(node[i].right != -1){
      Inorder(node[i].right);
    }
}
int main(){
    int temp = 0;
  scanf("%d", &N);
    for(int i = 0; i < N; i++){
      scanf("%d%d", &node[i].left, &node[i].right);
    }
    Inorder(0);
    for(int i = 0; i < N; i++){
      scanf("%d", &inp[i]);
    }
    qsort(inp, N, sizeof(int), cmp);
    for(int i = 0; i < N; i++){
      node[inorder[i]].value = inp[i];
    }
    count = 0;
    while(head < tail){
      if(head < tail) temp = Pop();
        count++;
        printf("%d",node[temp].value);
        if(count < N) printf(" ");
        else printf("\n");
        if(node[temp].left != -1) Push(node[temp].left);
        if(node[temp].right != -1) Push(node[temp].right);
    }
    return 0;
}