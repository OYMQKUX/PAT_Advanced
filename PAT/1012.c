#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char rank[5]="ACME";
struct str{
    char id[7];
    int C;
    int M;
    int E;
    double A;
    int rank_C;
    int rank_M;
    int rank_E;
    int rank_A;
};
int cmp1(const void *a, const void *b){
    struct str *c;
    struct str *d;
    c=(struct str *)a;
    d=(struct str *)b;
    return d->C-c->C;
}
int cmp2(const void *a, const void *b){
    struct str *c;
    struct str *d;
    c=(struct str *)a;
    d=(struct str *)b;
    return d->M-c->M;
}
int cmp3(const void *a, const void *b){
    struct str *c;
    struct str *d;
    c=(struct str *)a;
    d=(struct str *)b;
    return d->E-c->E;
}
int cmp4(const void *a, const void *b){
    struct str *c;
    struct str *d;
    c=(struct str *)a;
    d=(struct str *)b;
    return d->A>c->A;
}
//A, C, M, E
int max(int a, int b, int c, int d){
    int maxium=a;
    if(b<maxium) maxium=b;
    if(c<maxium) maxium=c;
    if(d<maxium) maxium=d;
    return maxium;
}
int max_rank(int a, int b, int c, int d){
    int maxium=a;
    int temp=0;
    if(b<maxium) {maxium=b;temp=1;}
    if(c<maxium) {maxium=c;temp=2;}
    if(d<maxium) {maxium=d;temp=3;}
    return temp;
}
int main(int argc, char *argv[]){
    int N, M;
    int flag=0;
    scanf("%d%d",&N,&M);
    getchar();
    int i, j;
    char temp[7];
    memset(temp,0,sizeof(char)*7);
    struct str stu[N];
    for(i=0;i<N;i++){
        scanf("%s",stu[i].id);
        scanf("%d%d%d",&stu[i].C,&stu[i].M,&stu[i].E);
        stu[i].A=(stu[i].C+stu[i].M+stu[i].E)*1.0/3.0;
        getchar();
    }
    qsort(stu, N, sizeof(stu[0]), cmp1);
    for(i=0;i<N;i++){
        if(stu[i].C==stu[i-1].C&&i) stu[i].rank_C=stu[i-1].rank_C;
        else stu[i].rank_C=i;
    }
    qsort(stu, N, sizeof(stu[0]), cmp2);
    for(i=0;i<N;i++){
        if(stu[i].M==stu[i-1].M&&i) stu[i].rank_M=stu[i-1].rank_M;
        else stu[i].rank_M=i;
    }
    qsort(stu, N, sizeof(stu[0]), cmp3);
    for(i=0;i<N;i++){
        if(stu[i].E==stu[i-1].E&&i) stu[i].rank_E=stu[i-1].rank_E;
        else stu[i].rank_E=i;
    }
    qsort(stu, N, sizeof(stu[0]), cmp4);
    for(i=0;i<N;i++){
        if(stu[i].A==stu[i-1].A&&i) stu[i].rank_A=stu[i-1].rank_A;
        else stu[i].rank_A=i;
    }
    /*printf("\n");
    for(i=0;i<N;i++){
        printf("%s %d %d %d %lf\n",stu[i].id,stu[i].C,stu[i].M,stu[i].E,stu[i].A);
        printf("%d %d %d %d\n",stu[i].rank_C,stu[i].rank_M,stu[i].rank_E,stu[i].rank_A);
    }
    printf("%s %d\n",stu[3].id,max_rank(stu[3].rank_A,stu[3].rank_C,stu[3].rank_M,stu[3].E));*/
    for(i=0;i<M;i++){
        scanf("%s",temp);
        flag=0;
        for(j=0;j<N;j++){
            if(strcmp(temp,stu[j].id)==0)
                {
                    printf("%d %c\n",max(stu[j].rank_A,stu[j].rank_C,stu[j].rank_M,stu[j].rank_E)+1, rank[max_rank(stu[j].rank_A,stu[j].rank_C,stu[j].rank_M,stu[j].rank_E)]);
                    flag=1;
                    break;
                }
        }
        if(!flag) printf("N/A\n");
    }
    return 0;
}