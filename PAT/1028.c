#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
struct file{
    int id;
    char name[9];
    int grade;
};
struct file file[100000];
int cmp1(const void *a, const void *b){
    struct file *c, *d;
    c=(struct file*)a;
    d=(struct file*)b;
    return c->id-d->id;
}
int cmp2(const void *a, const void *b){
    struct file *c, *d;
    c=(struct file*)a;
    d=(struct file*)b;
    if(strcmp(c->name,d->name)) return strcmp(c->name,d->name);
    else return c->id-d->id;
}
int cmp3(const void *a, const void *b){
    struct file *c, *d;
    c=(struct file*)a;
    d=(struct file*)b;
    if(c->grade!=d->grade) return c->grade-d->grade;
    else return c->id-d->id;
}
int main(int argc, char *argv[]){
    int N, C;
    scanf("%d%d",&N,&C);
    for(int i=0;i<N;i++){
        scanf("%d",&file[i].id);
        getchar();
        scanf("%s",file[i].name);
        scanf("%d",&file[i].grade);
    }
    if(C==1) qsort(file, N, sizeof(file[0]), cmp1);
    else if(C==2) qsort(file, N, sizeof(file[0]), cmp2);
    else if(C==3) qsort(file, N, sizeof(file[0]), cmp3);
    for(int i=0;i<N;i++){
        printf("%06d %s %d\n",file[i].id, file[i].name, file[i].grade);
    }
    return 0;
}