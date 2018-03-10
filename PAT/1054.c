#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define max 1<<24
int M;
int N;
int pixel[800][600];
int count[max];
int value[800*600];
int num;
int main(int argc, char *argv[]){
  int i, j;
  scanf("%d%d",&M,&N);
  for(i=0;i<M;i++)
    for(j=0;j<N;j++){
      scanf("%d",&pixel[i][j]);
      if(count[pixel[i][j]]==0) value[num++]=pixel[i][j];
      count[pixel[i][j]]++;
    }
  for(i=0;i<num;i++)
    if(count[value[i]]>M*N/2){printf("%d\n",value[i]);break;}
  return 0;
}