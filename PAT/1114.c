#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N;
int count;
int total;
struct Union{
    int father, mother;
    int k;
    int child[5];
    int num;
    int set;
    int area;
}Union[10000];
int visited[10000];
struct ans{
    int id;
    int num;
    double avg_set;
    double avg_area;
}ans[10000];
int all_id[21000];
int find(int x){
    if(Union[x].num < 0) return x;
    else return Union[x].num = find(Union[x].num);
}
void merge(int a, int b){
    int x, y;
    x = find(a);
    y = find(b);
    if(x != y){
        if(x > y){
            if(Union[x].num < 0) Union[y].num += Union[x].num;
            else Union[y].num--;
            Union[x].num = y;
            Union[y].set += Union[x].set;
            Union[y].area += Union[x].area;
        }
        else{
            if(Union[y].num < 0) Union[x].num += Union[y].num;
            else Union[x].num--;
            Union[y].num = x;
            Union[x].set += Union[y].set;
            Union[x].area += Union[y].area;
        }
    }
}
int cmp(const void *a, const void *b){
    struct ans *c, *d;
    c = (struct ans*)a;
    d = (struct ans*)b;
    if(fabs(c->avg_area - d->avg_area) < 1e-8) return c->id > d->id;
    else return c->avg_area < d->avg_area;
}
int main(int argc, char *argv[]){
    int id[1005];
    scanf("%d", &N);
    for(int i = 0; i < 10000; i++) Union[i].num = -1;
    for(int i = 0; i < N; i++){
        scanf("%d", &id[i]);
        if(id[i] != -1) all_id[total++] = id[i];
        scanf("%d%d%d", &Union[id[i]].father, &Union[id[i]].mother, &Union[id[i]].k);
        if(Union[id[i]].father != -1) all_id[total++] = Union[id[i]].father;
        if(Union[id[i]].mother != -1) all_id[total++] = Union[id[i]].mother;
        for(int j = 0; j < Union[id[i]].k; j++){
            scanf("%d", &Union[id[i]].child[j]);
            if(Union[id[i]].child[j] != -1) all_id[total++] = Union[id[i]].child[j];
        }
        scanf("%d%d", &Union[id[i]].set, &Union[id[i]].area);
    }
    for(int i = 0; i < N; i++){
        if(Union[id[i]].father != -1) merge(id[i], Union[id[i]].father);
        if(Union[id[i]].mother != -1) merge(id[i], Union[id[i]].mother);
        for(int j = 0; j < Union[id[i]].k; j++){
            merge(id[i], Union[id[i]].child[j]);
        }
    }
    for(int i = 0; i < total; i++){
        if(!visited[all_id[i]] && Union[all_id[i]].num < 0){
            visited[all_id[i]] = 1;
            ans[count].id = all_id[i];
            ans[count].num = Union[all_id[i]].num * -1;
            ans[count].avg_set = Union[all_id[i]].set * 1.0 / ans[count].num;
            ans[count].avg_area = Union[all_id[i]].area * 1.0 / ans[count].num;
            count++;
        }
    }
    qsort(ans, count, sizeof(ans[0]), cmp);
    printf("%d\n", count);
    for(int i = 0; i < count; i++)
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].num, ans[i].avg_set, ans[i].avg_area);
    return 0;
}