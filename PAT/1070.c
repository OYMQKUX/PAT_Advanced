#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N, D;
struct mooncake{
  double amount;
  double price;
  double ave;
}a[2000];
int cmp(const void *a, const void *b){
  return (((struct mooncake *)b)->ave) > (((struct mooncake *)a)->ave);
}
int main(int argc, const char * argv[]) {
  scanf("%d%d", &N, &D);
  for(int i=0; i<N; i++) scanf("%lf", &a[i].amount);
  for(int i=0; i<N; i++){
    scanf("%lf", &a[i].price);
    a[i].ave = a[i].price / a[i].amount;
  }
  qsort(a, N, sizeof(struct mooncake), cmp);
  int count = 0;
  double sum = 0;
  while(a[count].amount < D && count < N){
    sum += a[count].price;
    D -= a[count++].amount;
  }
  if(D) sum += a[count].ave * D;
  printf("%.2lf\n", sum);
  return 0;
}