#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int N;
int K;
int M;
int min;
int max;
int Case=1;
struct forbes{
  char name[9];
  int age;
  int worth;
}inp[100000], inp_copy[100000];
int cmp1(const void *a, const void *b){
  struct forbes *c, *d;
  c=(struct forbes*)a;
  d=(struct forbes*)b;
  if(c->worth!=d->worth) return d->worth-c->worth;
  if(c->age!=d->age) return c->age-d->age;
  return strcmp(c->name,d->name);
}
int main(int argc, char *argv[]){
  int i, j;
  int count;
  scanf("%d%d",&N,&K);
  for(i=0;i<N;i++){
    getchar();
    scanf("%s",inp[i].name);
    scanf("%d%d",&inp[i].age,&inp[i].worth);
    inp_copy[i]=inp[i];
  }
  qsort(inp,N,sizeof(inp[0]),cmp1);
  for(i=0;i<K;i++){
    count=0;
    scanf("%d%d%d",&M,&min,&max);
    printf("Case #%d:\n",Case);
    Case++;
    for(j=0;j<N;j++){
      if(count==M) break;
      if(inp[j].age>=min&&inp[j].age<=max){
        printf("%s %d %d\n",inp[j].name, inp[j].age, inp[j].worth);
        count++;
      }
    }
    if(count==0) printf("None\n");
  }
  return 0;
}