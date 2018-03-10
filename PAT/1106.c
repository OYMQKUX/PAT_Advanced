#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N;
double P;
double r;
int count;
int max_level;
struct sell{
    int count;
    int level;
    int *child;
}sell[100000];
void DFS(int root, int level){
    sell[root].level = level;
    for(int i = 0; i < sell[root].count; i++){
        DFS(sell[root].child[i], level + 1);
    }
}
int cmp(const void *a, const void *b){
    struct sell *c, *d;
    c = (struct sell*) a;
    d = (struct sell*) b;
    if(c->count != d->count) return c->count - d->count;
    return c->level - d->level;
}
double power(int level){
    double ans = P;
    for(int i = 0; i < level; i++){
        ans *= (1 + r / 100.0);
    }
    return ans;
}
int main(int argc, char *argv[]){
    scanf("%d%lf%lf", &N, &P, &r);
    for(int i = 0; i < N; i++){
        scanf("%d", &sell[i].count);
        sell[i].child = (int *)malloc(sizeof(int) * sell[i].count);
        for(int j = 0; j < sell[i].count; j++){
            scanf("%d", &sell[i].child[j]);
        }
    }
    DFS(0, 0);
    qsort(sell, N, sizeof(sell[0]), cmp);
    max_level = sell[0].level;
    for(int i = 1; i < N; i++){
        if(max_level == sell[i].level) count++;
        else break;
    }
    printf("%.4lf %d\n", power(max_level), count + 1);
    return 0;
}