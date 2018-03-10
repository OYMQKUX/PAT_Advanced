#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N;
int visited[100];
int ans[100];
int count;
int cal(int x){
    int res = 0;
    while(x){
        res += x % 10;
        x /= 10;
    }
    return res;
}
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int main(int argc, char *argv[]){
    int temp;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        if(!visited[cal(temp)]){
            ans[count++] = cal(temp);
            visited[cal(temp)] = 1;
        }
    }
    qsort(ans, count, sizeof(int), cmp);
    printf("%d\n", count);
    for(int i = 0; i < count; i++){
        if(i < count - 1) printf("%d ", ans[i]);
        else printf("%d\n", ans[i]);
    }
    return 0;
}