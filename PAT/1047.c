#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define INT_MAX 2<<29
struct stu{
    int name;
    struct stu *next;
};
struct course{
    int total;
    struct stu *next;
};
struct course a[2501];
int N;
int K;
int C;
int ans[40001];
int name_to_num(char *name){
    return name[3]-'0'+(name[2]-'A')*10+(name[1]-'A')*260+(name[0]-'A')*260*26;
}
char *num_to_name(int name){
    char *ans;
    ans=(char *)malloc(sizeof(char)*5);
    ans[0]=name/260/26+'A';
    ans[1]=(name%(260*26))/260+'A';
    ans[2]=(name%260)/10+'A';
    ans[3]=name%10+'0';
    ans[4]=0;
    return ans;
}
int cmp(const void *a, const void *b){
    return *(int *)a-*(int *)b;
}
int main(int argc, char *argv[]){
    int i, j;
    int num;
    char name[5];
    struct stu *temp;
    scanf("%d%d",&N,&K);
    for(i=0;i<N;i++){
        getchar();
        scanf("%s",name);
        scanf("%d",&C);
        for(j=0;j<C;j++){
            scanf("%d",&num);
            a[num].total++;
            temp=(struct stu*)malloc(sizeof(struct stu));
            temp->name=name_to_num(name);
            temp->next=a[num].next;
            a[num].next=temp;
        }
    }
    for(i=1;i<=K;i++){
        printf("%d %d\n",i,a[i].total);
        num=0;
        temp=a[i].next;
        while(temp){
            ans[num++]=temp->name;
            temp=temp->next;
        }
        qsort(ans,num,sizeof(int),cmp);
        for(j=0;j<num;j++){
            printf("%s\n",num_to_name(ans[j]));
        }
    }
}