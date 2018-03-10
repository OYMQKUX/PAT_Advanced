#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
int N;
int K;
int P;
int max_count;
int count;
int tail;
int temp[21];
int ans[400];
int fact[400];
int max_fact_sum = -1;
void DFS(int pos, int k, int total_sum, int fact_sum){
    if(total_sum == N && k == K){
        if(fact_sum > max_fact_sum){
            max_count = tail;
            max_fact_sum = fact_sum;
            memcpy(ans, fact, sizeof(ans));
        }
        return;
    }
    if(total_sum > N || k > K) return;
    if(pos >= 1){
        fact[tail++] = pos;
        DFS(pos, k + 1, total_sum + temp[pos], fact_sum + pos);
        tail--;
        DFS(pos - 1, k, total_sum, fact_sum);
    }
}
int main(int argc, char *argv[]){
    scanf("%d%d%d", &N, &K, &P);
  for(int i = 0; i < 21; i++){
        temp[count++] = pow(i, P);
        if(pow(i, P) > N) break;
    }
    DFS(count - 1, 0, 0, 0);
    if(max_fact_sum == -1){
        printf("Impossible\n");
    }
    else{
        printf("%d = %d^%d", N, ans[0], P);
        for(int i = 1; i < max_count; i++){
            printf(" + %d^%d", ans[i], P);
        }
        printf("\n");
    }
    return 0;
}