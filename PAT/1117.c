#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N;
int max;
int num[100001];
int cmp(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}
int main(int argc, char *argv[]){
    int i;
    scanf("%d", &N);
    for(i = 1; i <= N; i++){
        scanf("%d", &num[i]);
    }
    qsort(num + 1, N, sizeof(int), cmp);
    for(i = 1; i <= N; i++){
        if(num[i] <= i) break;
    }
    printf("%d\n", i - 1);
    return 0;
}