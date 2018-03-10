#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct stu{
    char id[16];
    int begin;
    int end;
};
int cmp1(const void *a, const void *b){
    struct stu *c, *d;
    c=(struct stu*)a;
    d=(struct stu*)b;
    return c->begin-d->begin;
}
int cmp2(const void *a, const void *b){
    struct stu *c, *d;
    c=(struct stu*)a;
    d=(struct stu*)b;
    return d->end-c->end;
}
int main(int argc, char *argv[]){
    int N;
    scanf("%d",&N);
    int i;
    int hour, min, sec;
    struct stu a[N];
    for(i=0;i<N;i++){
        scanf("%s",a[i].id);
        scanf("%d:%d:%d",&hour, &min, &sec);
        a[i].begin=hour*3600+min*60+sec;
        scanf("%d:%d:%d",&hour, &min, &sec);
        a[i].end=hour*3600+min*60+sec;
    }
    qsort(a, N, sizeof(a[0]), cmp1);
    printf("%s ", a[0].id);
    qsort(a, N, sizeof(a[0]), cmp2);
    printf("%s\n",a[0].id);
}