#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int K;
int N;
int Q[1011][1011];
int main(int argc, char *argv[]){
    int queen, diff;
    int flag;
    scanf("%d", &K);
    for(int i = 0; i < K; i++){
        flag = 1;
        memset(Q, 0, sizeof(Q));
        scanf("%d", &N);
        for(int j = 1; j <= N; j++){
            scanf("%d", &queen);
            diff = 1;
            if(Q[queen][j] == -1) flag = 0;
            if(flag){
                for(int k = j + 1; k <= N; k++){
                    Q[queen][k] = -1;
                    if(queen - diff >= 1) Q[queen-diff][k] = -1;
                    if(queen + diff <= N) Q[queen+diff][k] = -1;
                    diff++;
                }
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}