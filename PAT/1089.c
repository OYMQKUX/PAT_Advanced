#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N;
int ini[100], sort[100];
int cmp(const void *a, const void *b){
  return *(int *)a - *(int *)b;
}
int check(){
    for(int i = 0; i < N; i++){
      if(ini[i] != sort[i]) return 0;
    }
    return 1;
}
int check_if_insertion(){
  int flag = 1;
    int i;
    for(i = 1; i < N; i++){
        if(sort[i] < sort[i-1]) {flag = i;break;}
    }
    for(; i < N; i++){
      if(sort[i] != ini[i]) flag = 0;
    }
    return flag;
}
void Print_insertion(int flag){
    int i;
    puts("Insertion Sort");
    for(i = flag - 1; i >= 0; i--){
        if(sort[i] < sort[flag]) break;
    }
    for(int j = 0; j <= i; j++){
        printf("%d ", sort[j]);
    }
    if(i != N-2) printf("%d ", sort[flag]);
    for(int j = i + 1; j < N - 1; j++){
        if(j!=flag)printf("%d ", sort[j]);
    }
    printf("%d\n", sort[N-1]);
}
void Print_Merge(){
    int i, j;
    puts("Merge Sort");
    for(i = 2; i < N; i*=2){
        for(j = 0; j < N; j += i){
          if(N - j >= i) qsort(ini + j, i, sizeof(int), cmp);
            else qsort(ini, N - j, sizeof(int), cmp);
        }
        if(check()) break;
    }
    i *= 2;
    if(i > N) i = N;
    for(j = 0; j < N; j += i){
      if(N - j >= i) qsort(ini + j, i , sizeof(int), cmp);
        else qsort(ini + j, N - j, sizeof(int), cmp);
    }
    for(i = 0; i < N - 1; i++){
      printf("%d ", ini[i]);
    }
    printf("%d\n", ini[N-1]);
}
int main(){
    int i;
    int flag;
    scanf("%d", &N);
    for(i = 0; i < N; i++){
      scanf("%d", &ini[i]);
    }
    for(i = 0; i < N; i++){
      scanf("%d", &sort[i]);
    }
    flag = check_if_insertion();
    if(flag){
      Print_insertion(flag);
    }
    else{
      Print_Merge();
    }
    return 0;
}