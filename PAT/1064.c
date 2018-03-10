#include <stdio.h>
//#include <string.h>
#include <stdlib.h>
int N;
int inp[1000];
int cmp(const void *a, const void *b){
  return *(int *)a-*(int *)b;
}
int power(int base, int index){
  int product=1;
  if(index==0) return 1;
  for(int i=0;i<index;i++){
    product*=base;
  }
  return product;
}
struct tree{
  int value;
  struct tree *left;
  struct tree *right;
}*header;
int lg2(int base, int value){
  int count=0;
  int temp=1;
  while(temp<value){
    temp*=base;
    count++;
  }
  return count;
}
void find_center(int head, int tail, struct tree *tree){
  struct tree *temp=(struct tree*)malloc(sizeof(struct tree));
  temp->left=temp->right=NULL;
  int len=tail-head+1;
  int level=lg2(2,len+1);
  int remain=len-power(2,level-1)+1;
  int left_bot, right_bot;
  if(len<=0) return;
  if(len==1){
    temp->value=inp[head];
    if(tree==NULL) {tree=temp;}
    else{
      if(inp[head]>tree->value) tree->right=temp;
      else tree->left=temp;
    }
    return;
  }
  if(remain>power(2,level-2)){
    left_bot=power(2,level-2);
    right_bot=remain-left_bot;
  }
  else{
    left_bot=remain;
    right_bot=0;
  }
  temp->value=inp[head+len-right_bot-power(2,level-2)];
  //printf("%d\n",temp->value);
  if(tree==NULL){
    tree=temp;
    header=tree;
    find_center(head, head+len-right_bot-power(2,level-2)-1, tree);
    find_center(head+len-right_bot-power(2,level-2)+1, tail, tree);
  }
  else {
    if(temp->value>tree->value) tree->right=temp;
    else if(temp->value<tree->value) tree->left=temp;
    tree=temp;
    find_center(head, head+len-right_bot-power(2,level-2)-1, tree);
    find_center(head+len-right_bot-power(2,level-2)+1, tail, tree);
  }
}
int main(int argc, char *argv[]){
  struct tree *head;
  struct tree ans[1000];
  scanf("%d",&N);
  for(int i=0; i<N;i++){
    scanf("%d",&inp[i]);
  }
  qsort(inp, N, sizeof(inp[0]), cmp);
  find_center(0, N-1, head);
  //printf("%d\n",header->value);
  if(N>1){
  ans[1]=*header;
  for(int i=2;i<=N;i++){
    if(i%2==0) ans[i]=*ans[i/2].left;
    else ans[i]=*ans[i/2].right;
  }
  for(int i=1;i<N;i++) printf("%d ",ans[i].value);
    printf("%d\n",ans[N].value);}
  else printf("%d\n",inp[0]);
  return 0;
}