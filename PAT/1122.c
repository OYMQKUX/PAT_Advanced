#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N;
int M;
int K;
int edge[201][201];
int v[10000];
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int main(int argc, char *argv[]){
    int v1, v2;
    int n;
    int flag;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d%d", &v1, &v2);
        edge[v1][v2] = edge[v2][v1] = 1;
    }
    scanf("%d", &K);
    for(int i = 0; i < K; i++){
        flag = 1;
        scanf("%d", &n);
        for(int j = 0; j < n; j++){
            scanf("%d", &v[j]);
        }
        if(n != N + 1 || v[0] != v[n-1]) printf("NO\n");
        else{
            for(int j = 0; j < n - 1; j++){
                if(!edge[v[j]][v[j+1]]){
                    flag = 0;
                    break;
                }
            }
            if(!flag) printf("NO\n");
            else{
                qsort(v, n - 1, sizeof(int), cmp);
                for(int j = 0; j < n - 1; j++){
                    if(v[j] != j + 1){
                        flag = 0;
                        break;
                    }
                }
                if(flag) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}