#include <stdio.h>
#include <stdlib.h>
int inp[100000];
int hash[100000];
int Union[100000];
int count;
int flag[100000];
int main(int argc, const char * argv[]) {
  int N;
  int temp;
  int group = 0;
  int first = 0;
  scanf("%d", &N);
  count = N;
  for(int i=0; i<N;i++) Union[i]=i;
  for(int i=0; i<N;i++){
    scanf("%d",&inp[i]);
    hash[inp[i]] = i;
    if(inp[i] == i) count--;
  }
  //printf("%d\n",count);
  temp = hash[0];
  flag[temp] = 1;
  while(temp){
    temp = hash[temp];
    flag[temp] = 1;
  }
  if(inp[0] == 0) first = 0;
  else first = 1;
  for(int i=0;i<N;i++){
    if(!flag[i] && inp[i] != i){
      temp = i;
      flag[i] = 1;
      while(hash[temp] != i){
        temp = hash[temp];
        flag[temp] = 1;
      }
      group++;
    }
  }
  if(count) printf("%d\n", count-first+group);
  else printf("%d\n", count);
  return 0;
}