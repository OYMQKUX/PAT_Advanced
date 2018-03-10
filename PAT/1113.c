#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N;
int inp[100000];
long long S1, S2;
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int main(int argc, char *argv[]){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &inp[i]);
    }
    qsort(inp, N, sizeof(int), cmp);
    for(int i = 0; i < N / 2; i++){
        S1 += inp[i];
    }
    for(int i = N / 2; i < N; i++){
        S2 += inp[i];
    }
    if(N % 2){
        printf("1 ");
    }
    else{
        printf("0 ");
    }
    printf("%lld\n", S2 - S1);
    return 0;
}