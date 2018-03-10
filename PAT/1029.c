#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
int c[2000000];
int cmp(const void *a, const void *b){
    return *(int *)a-*(int *)b;
}
int main(int argc, char *argv[]){
    int a, b,i;
    scanf("%d",&a);
    for(i=0;i<a;i++) scanf("%d",&c[i]);
    scanf("%d",&b);
    for(;i<a+b;i++) scanf("%d",&c[i]);
    qsort(c,a+b,sizeof(int),cmp);
    printf("%d\n",c[(a+b)%2?(a+b)/2:(a+b)/2-1]);
    return 0;
}