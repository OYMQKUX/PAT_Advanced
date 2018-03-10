#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N;
int Union[1001];
int count;
int find(int x){
    if(Union[x] < 0) return x;
    else return Union[x] = find(Union[x]);
}
void merge(int a, int b){
    if(find(a) != find(b)){
        Union[find(a)] += Union[find(b)];
        Union[find(b)] = find(a);
    }
}
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int hobby[1001][1001];
int main(int argc, char *argv[]){
    int K;
    int h;
    scanf("%d", &N);
    memset(Union, -1, sizeof(Union));
    for(int i = 1; i <= N; i++){
        scanf("%d:", &K);
        for(int j = 0; j < K; j++){
            scanf("%d", &h);
            hobby[h][0]++;
            hobby[h][hobby[h][0]] = i;
            hobby[0][h]++;
        }
    }
    for(int i = 1; i <= 1000; i++){
        if(hobby[0][i] > 1){
            for(int j = 2; j <= hobby[i][0]; j++){
                merge(hobby[i][1], hobby[i][j]);
            }
        }
    }
    qsort(Union + 1, N, sizeof(int), cmp);
    for(int i = 1; i <= N; i++){
        if(Union[i] < 0) count++;
        else break;
    }
    printf("%d\n", count);
    for(int i = 1;i <= count - 1; i++)
        printf("%d ", Union[i] * -1);
    printf("%d\n", Union[count] * -1);
    return 0;
}