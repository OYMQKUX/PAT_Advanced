#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N;
int K;
int Q;
int max;
int trees;
int Union[10001];
int find(int x){
    if(Union[x] < 0) return x;
    return Union[x] = find(Union[x]);
}
void merge(int a, int b){
    int x = find(a), y = find(b);
    if(x != y){
        Union[y] += Union[x];
        Union[x] = y;
    }
}
int main(int argc, char *argv[]){
    int bird1, bird2;
    scanf("%d", &N);
    memset(Union, -1, sizeof(Union));
    for(int i = 0; i < N; i++){
        scanf("%d", &K);
        if(K){
            scanf("%d", &bird1);
            if(bird1 > max) max = bird1;
        }
        for(int j = 1; j < K; j++){
            scanf("%d", &bird2);
            if(bird2 > max) max = bird2;
            merge(bird1, bird2);
        }
    }
    for(int i = 1; i <= max; i++){
        if(Union[i] < 0) trees++;
    }
    printf("%d %d\n", trees, max);
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++){
        scanf("%d%d", &bird1, &bird2);
        if(find(bird1) == find(bird2)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}