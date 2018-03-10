#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N;
int couple[100000];
int M;
int guests[10000];
int come[100000];
int ans[10000];
int count;
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int main(int argc, char *argv[]){
    int cp1, cp2;
    scanf("%d", &N);
    memset(couple, -1, sizeof(couple));
    for(int i = 0; i < N; i++){
        scanf("%d%d", &cp1, &cp2);
        couple[cp1] = cp2;
        couple[cp2] = cp1;
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d", &guests[i]);
        come[guests[i]] = 1;
    }
    for(int i = 0; i < M; i++){
        if(couple[guests[i]] == -1){
            ans[count++] = guests[i];
        }
        else{
            if(!come[couple[guests[i]]]){
                ans[count++] = guests[i];
            }
        }
    }
    qsort(ans, count, sizeof(int), cmp);
    printf("%d\n", count);
    for(int i = 0; i < count; i++){
        if(i < count - 1) printf("%05d ", ans[i]);
        else printf("%05d\n", ans[i]);
    }
    return 0;
}