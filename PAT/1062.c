#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define max 100000
int N;
int L;
int H;
struct people{
  int num;
  int virtue;
  int talent;
  int flag;
  int total;
  int saga;
  int nobleman;
  int fool;
  int small;
}people[max];
int cmp(const void *a, const void *b){
  struct people *c, *d;
  c=(struct people*)a;
  d=(struct people*)b;
  if(c->flag!=d->flag) return c->flag-d->flag;
  if(c->saga!=d->saga) return d->saga-c->saga;
  if(c->nobleman!=d->nobleman) return d->nobleman-c->nobleman;
  if(c->fool!=d->fool) return d->fool-c->fool;
  if(c->small!=d->small) return d->small-c->small;
  if(c->total!=d->total) return d->total-c->total;
  if(c->virtue!=d->virtue) return d->virtue-c->virtue;
  return c->num-d->num;
}
int main(int argc, char *argv[]){
  scanf("%d%d%d",&N,&L,&H);
  for(int i=0;i<N;i++){
    scanf("%d%d%d",&people[i].num,&people[i].virtue,&people[i].talent);
    if(people[i].virtue>=L&&people[i].talent>=L) people[i].flag=1;
    else people[i].flag=0;
    people[i].total=people[i].virtue+people[i].talent;
    if(people[i].virtue>=H&&people[i].talent>=H) people[i].saga=1;
    else if(people[i].virtue>=H&&people[i].talent<H) people[i].nobleman=1;
    else if(people[i].virtue<H&&people[i].talent<H&&people[i].virtue>=people[i].talent) people[i].fool=1;
    else people[i].small=1;
  }
  qsort(people, N, sizeof(people[0]), cmp);
  int count=0;
  for(int i=0;i<N;i++) if(!people[i].flag) count++;
  printf("%d\n",N-count);
  for(int i=0;i<N;i++){
    if(people[i].flag){
      printf("%08d %d %d\n",people[i].num, people[i].virtue, people[i].talent);
    }
  }
  return 0;
}