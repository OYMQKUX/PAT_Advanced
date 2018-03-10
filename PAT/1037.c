#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int a[2][100000];//0 for positive, 1 for negative
int b[2][100000];
int NC, ND;
int tail_C_P, tail_C_N;
int tail_D_P, tail_D_N;
long long total;
int cmp(const void *a, const void *b){
    return abs(*(int *)a)-abs(*(int *)b);
}
int main(int argc, char *argv[]){
    int temp;
    scanf("%d",&NC);
    for(int i=0;i<NC;i++){
        scanf("%d",&temp);
        if(temp>0) a[0][tail_C_P++]=temp;
        else a[1][tail_C_N++]=temp;
    }
    qsort(a[0],tail_C_P,sizeof(int),cmp);
    qsort(a[1],tail_C_N,sizeof(int),cmp);
    scanf("%d",&ND);
    for(int i=0;i<ND;i++){
        scanf("%d",&temp);
        if(temp>0) b[0][tail_D_P++]=temp;
        else b[1][tail_D_N++]=temp;
    }
    qsort(b[0],tail_D_P,sizeof(int),cmp);
    qsort(b[1],tail_D_N,sizeof(int),cmp);
    while(tail_C_P>=0&&tail_D_P>=0){
        total+=a[0][tail_C_P]*b[0][tail_D_P];
        tail_C_P--;
        tail_D_P--;
    }
    while(tail_D_N>=0&&tail_D_N>=0){
        total+=a[1][tail_C_N]*b[1][tail_D_N];
        tail_C_N--;
        tail_D_N--;
    }
    printf("%lld\n",total);
    return 0;
}