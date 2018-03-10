#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int N_P;
int N_G;
int order[1000];
int wei[1000];
struct pro{
  int place;
  int weight;
}pro[1000];
int winner[1000];
int max(int pos, int num){
  int i;
  int index=pos;
  int max=-1;
  for(i=pos;i<pos+num;i++){
    if(pro[winner[i]].weight>max){
      max=pro[winner[i]].weight;
      index=winner[i];
    }
  }
  return index;
}
int main(int argc, char *argv[]){
  int i, j;
  int temp;
  int group;
  int win;
  int count;
  int num;
  scanf("%d%d",&N_P,&N_G);
  for(i=0;i<N_P;i++) scanf("%d",&wei[i]);
  for(i=0;i<N_P;i++){
    scanf("%d",&order[i]);
    pro[order[i]].weight=wei[order[i]];
  }
  for(i=0;i<1000;i++) winner[i]=order[i];
  group=N_P%N_G?(N_P/N_G+1):N_P/N_G;
  win=N_P;
  while(win>1){
    count=0;
    for(i=0;i<group;i++){
      num=win-i*N_G>=N_G?N_G:win-i*N_G;
      temp=max(i*N_G,num);
      for(j=i*N_G;j<i*N_G+num;j++){
        
        if(winner[j]!=temp) pro[winner[j]].place=group+1;
      }
      winner[count++]=temp;
      //for(int k=0;k<N_P;k++) printf("%d %d %d\n",i, k,pro[k].place);
      //printf("\n");
    }
    win=group;
    group=win%N_G?(win/N_G+1):win/N_G;
  }
  pro[winner[0]].place=1;
  for(i=0;i<N_P-1;i++) printf("%d ",pro[i].place);
  printf("%d\n",pro[i].place);
  return 0;
}