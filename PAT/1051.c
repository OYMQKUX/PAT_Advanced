#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INT_MAX 1<<29
int M;
int N;
int K;
int head;
int tail;
int temp;
int flag;
int inp;
int min1;
int min2;
int min;
int stack[2000];
void push(int num){
  stack[tail+1]=num;
  tail++;
}
void pop(){
  tail--;
}
void Clear(){
  head=tail=0;
  memset(stack,-1,sizeof(stack));
}
int main(int argc, char *argv[]){
  scanf("%d%d%d",&M,&N,&K);
  for(int i=0;i<K;i++){
    temp=1;
    flag=1;
    min2=-1;
    for(int j=0;j<N;j++){
      scanf("%d",&inp);
      if(!j) min=min1;
      else min=min2;
      if(inp>=temp){
        for(int k=min+1;k<=inp;k++){
          push(k);
          if(tail>M){
            flag=0;
          }
        }
        pop();
        temp=inp;
      }
      else{
        if(stack[tail]!=inp){
          flag=0;
        }
        else pop();
      }
      if(inp>min2) min2=inp;
    }
    if(tail) flag=0;
    if(flag) printf("YES\n");
    else printf("NO\n");
    Clear();
  }
    return 0;
}