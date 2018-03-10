#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct stu{
    char name[11];
    char gender;
    char ID[11];
    int grade;
};
int cmp1(const void *a, const void *b){
    struct stu *c, *d;
    c=(struct stu*)a;
    d=(struct stu*)b;
    if(c->gender!=d->gender) return c->gender-d->gender;
    else return d->grade-c->grade;
}
int cmp2(const void *a, const void *b){
    struct stu *c, *d;
    c=(struct stu*)a;
    d=(struct stu*)b;
    if(c->gender!=d->gender) return d->gender-c->gender;
    else return c->grade-d->grade;
}
struct stu stu[1000];
int main(int argc, char *argv[]){
    int N;
    int grade1=-1, grade2=-1;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%s",stu[i].name);
        getchar();
        scanf("%c",&stu[i].gender);
        getchar();
        scanf("%s",stu[i].ID);
        scanf("%d",&stu[i].grade);
    }
    qsort(stu,N,sizeof(stu[0]),cmp1);
    if(stu[0].gender=='M') printf("Absent\n");
    else {
        printf("%s %s\n",stu[0].name,stu[0].ID);
        grade1=stu[0].grade;
    }
    qsort(stu,N,sizeof(stu[0]),cmp2);
    if(stu[0].gender=='F') printf("Absent\n");
    else{
        printf("%s %s\n",stu[0].name,stu[0].ID);
        grade2=stu[0].grade;
    }
    if(grade1>=0&&grade2>=0) printf("%d\n",grade1-grade2);
    else printf("NA\n");
    return 0;
}