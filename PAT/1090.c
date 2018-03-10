#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N;
double price;
double r;
int max;
int total;
double ans;
int Union[100000];
int count[100000];
int find(int pos){
    if(Union[pos] == -1) return 1;
    if(count[pos] != 1) return count[pos];
  count[pos] += find(Union[pos]);
    return count[pos];
}
int main(){
    scanf("%d%lf%lf", &N, &price, &r);
    for(int i = 0; i < N; i++){
      scanf("%d", &Union[i]);
        count[i] = 1;
    }
    for(int i = 0; i < N; i++){
      find(i);
        if(count[i] > max) max = count[i];
    }
    for(int i = 0; i < N; i++){
      if(count[i] == max) total++;
    }
    for(int i = 0; i < max - 1; i++){
      price *= (1 + r / 100.0);
    }
    printf("%.2lf %d\n", price, total);
    return 0;
}