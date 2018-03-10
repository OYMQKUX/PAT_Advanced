#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int N;
int M;
int K;
struct app{
    int id;
  int GE;
    int GI;
    int total;
    int rank;
    int choice[5];
}app[40000];
struct sch{
  int quota;
    int count;
    int stu[40000];
}sch[100];
int cmp(const void *a, const void *b){
  struct app *c, *d;
    c = (struct app*)a;
    d = (struct app*)b;
    if(c->total != d->total) return d->total - c->total;
    if(c->GE != d->GE) return d->GE - c->GE;
    return c->choice[0] - d->choice[0];
}
int cmp1(const void *a, const void *b){
  return *(int *)a - *(int *)b;
}
int main(int argc, char *argv[]){
    scanf("%d%d%d", &N, &M, &K);
    for(int i = 0; i < M; i++){
      scanf("%d", &sch[i].quota);
    }
    for(int i = 0; i < N; i++){
      scanf("%d%d", &app[i].GE, &app[i].GI);
        app[i].total = app[i].GE + app[i].GI;
        app[i].id = i;
        for(int j = 0; j < K; j++){
          scanf("%d", &app[i].choice[j]);
        }
    }
    qsort(app, N, sizeof(app[0]), cmp);
    app[0].rank = 1;
    for(int i = 1; i < N; i++){
        if((app[i].total < app[i-1].total) || (app[i].total == app[i-1].total && app[i].GE < app[i-1].GE))
            app[i].rank = app[i-1].rank + 1;
        else if(app[i].total == app[i-1].total && app[i].GE == app[i-1].GE)
            app[i].rank = app[i-1].rank;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            if(sch[app[i].choice[j]].count < sch[app[i].choice[j]].quota){
              sch[app[i].choice[j]].stu[sch[app[i].choice[j]].count++] = app[i].id;
                break;
            }
            else{
                if(app[app[i].id].rank == app[sch[app[i].choice[j]].stu[sch[app[i].choice[j]].count - 1]].rank){
                    //printf("i = %d %d %d %d\n", i, app[i].rank, sch[app[i].choice[j]].stu[sch[app[i].choice[j]].count - 1], app[sch[app[i].choice[j]].stu[sch[app[i].choice[j]].count - 1]].rank);
                  sch[app[i].choice[j]].stu[sch[app[i].choice[j]].count++] = app[i].id;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < M; i++){
      qsort(sch[i].stu, sch[i].count, sizeof(int), cmp1);
    }
    for(int i = 0; i < M; i++){
        if(sch[i].count == 0){
          printf("\n");
            continue;
        }
        for(int j = 0; j < sch[i].count - 1; j++){
          printf("%d ", sch[i].stu[j]);
        }
        printf("%d\n", sch[i].stu[sch[i].count-1]);
    }
    return 0;
}