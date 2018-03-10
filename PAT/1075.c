#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct pat{
    int id;
    int order;
    int pro[6];
    int perfect;
    int sum;
    int submit_with_score;
}pat[10010];
int problem[6];
int N;
int K;
int M;
int cmp(const void *a, const void *b){
  struct pat *c, *d;
    c = (struct pat*) a;
    d = (struct pat*) b;
    if(c->sum != d->sum) return d->sum - c->sum;
    if(c->perfect != d->perfect) return d->perfect - c->perfect;
    if(c->submit_with_score != d->submit_with_score) return d->submit_with_score - c->submit_with_score;
    return c->id - d->id;
}
int main(int argc, char *argv[]){
    int temp;
    int num;
    int score;
    scanf("%d%d%d", &N, &K, &M);
    for(int i = 1; i <= K; i++)
        scanf("%d", &problem[i]);
    for(int i = 0; i <= N; i++){
        memset(pat[i].pro, -1, sizeof(int) * 6);
      pat[i].id = i;
    }
    for(int i = 0; i < M; i++){
      scanf("%d%d%d", &temp, &num, &score);
        if(pat[temp].pro[num] == -1) pat[temp].pro[num] = 0;
        if(score > pat[temp].pro[num]){
            pat[temp].sum -= pat[temp].pro[num];
            pat[temp].sum += score;
            pat[temp].pro[num] = score;
          if(problem[num] == score) pat[temp].perfect++;
        }
        if(score != -1) pat[temp].submit_with_score = 1;
    }
    qsort(pat+1, N, sizeof(struct pat), cmp);
    pat[1].order = 1;
    if(pat[1].sum > 0 || pat[1].submit_with_score){
      printf("%d %05d %d", pat[1].order, pat[1].id, pat[1].sum);
        for(int i = 1; i <= K; i++){
          if(pat[1].pro[i] == -1) printf(" -");
            else printf(" %d", pat[1].pro[i]);
        }
        printf("\n");
    }
    for(int i = 2; i <= N; i++){
        if(pat[i].submit_with_score){
            if(pat[i].sum == pat[i-1].sum){
              pat[i].order = pat[i-1].order;
            }
            else{
              pat[i].order = i;
            }
            printf("%d %05d %d", pat[i].order, pat[i].id, pat[i].sum);
            for(int j = 1; j <= K; j++){
                if(pat[i].pro[j] == -1) printf(" -");
                else printf(" %d", pat[i].pro[j]);
            }
            printf("\n");
        }
        else break;
    }
    return 0;
}