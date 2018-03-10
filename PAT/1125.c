#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N;
int len[10000];
double total;
int ans;
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int main(int argc, char *argv[]){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &len[i]);
    qsort(len, N, sizeof(int), cmp);
    total = len[0];
    for(int i = 1; i < N; i++){
        total += len[i];
       total/= 2;
    }
    ans = total;
    printf("%d\n", ans);
    return 0;
}