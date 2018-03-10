#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int N;
int head;
int temp;
int count;
struct val_1{
  int head;
  int value;
  int flag;
}val1[100000],val[100000];
int addr[100000];
int cmp(const void *a, const void *b){
  struct val_1 *c, *d;
  c=(struct val_1*)a;
  d=(struct val_1*)b;
  if(c->flag!=d->flag) return d->flag-c->flag;
  return c->value-d->value;
}
int main(int argc, char *argv[]){
  scanf("%d%d",&N,&head);
  if(head==-1) {printf("0 -1\n");return 0;}
  for(int i=0;i<N;i++){
    scanf("%d",&temp);
    val1[temp].head=temp;
    scanf("%d",&val1[temp].value);
    scanf("%d",&addr[temp]);
  }
  temp=head;
  while(temp!=-1){
    val1[temp].flag=1;
    val[count++]=val1[temp];
    temp=addr[val1[temp].head];
  }
  qsort(val,N,sizeof(val[0]),cmp);
  if(count) printf("%d %05d\n",count,val[0].head);
  else {printf("0\n");return 0;}
  for(int i=0;i<count-1;i++)
    printf("%05d %d %05d\n",val[i].head, val[i].value,val[i+1].head);
  printf("%05d %d %d\n",val[count-1].head, val[count-1].value,-1);
  return 0;
}