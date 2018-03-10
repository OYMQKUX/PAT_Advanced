#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int g1, g2;
int count;
int N;
struct stu{
  char name[11];
    char id[11];
    int grade;
    int flag;
}stu[100000];
int cmp(const void *a, const void *b){
  struct stu *c, *d;
    c = (struct stu*) a;
    d = (struct stu*) b;
    if(c->flag != d->flag) return d->flag - c->flag;
    return d->grade - c->grade;
}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        getchar();
      scanf("%s", stu[i].name);
        scanf("%s", stu[i].id);
        scanf("%d", &stu[i].grade);
    }
    scanf("%d%d", &g1, &g2);
    if(g1 > g2){
      g1 = g1 + g2;
        g2 = g1 - g2;
        g1 = g1 - g2;
    }
    for(int i = 0; i < N; i++){
        if(stu[i].grade <= g2 && stu[i].grade >= g1){
          stu[i].flag = 1;
            count++;
        }
        else stu[i].flag = 0;
    }
    if(count == 0) printf("NONE\n");
    else{
      qsort(stu, N, sizeof(stu[0]), cmp);
        for(int i = 0; i < count; i++){
          printf("%s %s\n", stu[i].name, stu[i].id);
        }
    }
    return 0;
}