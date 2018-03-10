#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define max 100000
int stack[max];
int tree[max];
char inp[3][11]={"Pop","PeekMedian","Push"};
int N;
int last;
int lowbit(int x) {return x&-x;}
void add(int k, int num){
  while(k<=max){
    tree[k]+=num;
    k+=lowbit(k);
  }
}
int Read(int k){
  int sum=0;
  while(k){
    sum+=tree[k];
    k-=lowbit(k);
  }
  return sum;
}
int main(int argc, char *argv[]){
  int i;
  char temp[11];
  int value;
  int head, tail;
  int count;
  int middle;
  scanf("%d",&N);
  getchar();
  for(i=0;i<N;i++){
    scanf("%s",temp);
    if(!strcmp(temp,inp[0])){
      if(last>0) {
        add(stack[last-1],-1);
        printf("%d\n",stack[last-1]);
        last--;
      }
      else printf("Invalid\n");
    }
    else if(!strcmp(temp,inp[1])){
      if(last==0) {printf("Invalid\n");continue;}
      else{
        head=0;tail=max;middle=(head+tail)/2;
        if(last%2) count=(last+1)/2;
        else count=last/2;
        while(1){
          if(head>=tail) break;
          else if(Read(middle)<count){head=middle+1;middle=(head+tail)/2;}
          else {tail=middle;middle=(head+tail)/2;}
        }
        printf("%d\n",middle);
      }
    }
    else if(!strcmp(temp,inp[2])){
      scanf("%d",&value);
      getchar();
      add(value,1);
      stack[last++]=value;
    }
  }
  return 0;
}