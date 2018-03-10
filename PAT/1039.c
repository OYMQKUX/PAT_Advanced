#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define max 26*26*26*10+1
int N, K;
int total[max];
int ans[max];
struct stu{
    int num;
    struct stu *next;
};
int name_to_num(char *name){
    return name[3]-'0'+(name[2]-'A')*10+(name[1]-'A')*260+(name[0]-'A')*26*260;
}
struct stu a[max];
int cmp(const void *a, const void *b){
    return *(int *)a-*(int *)b;
}
int main(int argc, char *argv[]){
    char name[5];
    int j, k;
    int i;
    int Nj;
    struct stu *temp;
    scanf("%d%d",&N,&K);
    for(k=0;k<K;k++){
        scanf("%d",&i);
        scanf("%d",&Nj);
        for(j=0;j<Nj;j++){
            getchar();
            scanf("%s",name);
            total[name_to_num(name)]++;
            temp=(struct stu*)malloc(sizeof(struct stu));
            temp->num=i;
            temp->next=a[name_to_num(name)].next;
            a[name_to_num(name)].next=temp;
        }
    }
    for(i=0;i<N;i++){
        k=0;
        getchar();
        scanf("%s",name);
        printf("%s %d",name,total[name_to_num(name)]);
        temp=a[name_to_num(name)].next;
        while(temp){
            ans[k++]=temp->num;
            temp=temp->next;
        }
        qsort(ans,k,sizeof(int),cmp);
        for(j=0;j<k;j++) printf(" %d",ans[j]);
        printf("\n");
    }
    return 0;
}