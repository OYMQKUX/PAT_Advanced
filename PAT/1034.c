#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define max 26*26*26
struct record{
    int num;
    int flag;
};
struct record record[1000];
int Union[max];
int Time[max];
int Time_total[max];
int head[max];
int check[max];
int cmp(const void *a, const void *b){
    struct record *c, *d;
    c=(struct record*)a;
    d=(struct record*)b;
    if(c->flag!=d->flag) return (d->flag)-(c->flag);
    else return c->num-d->num;
}
int name_to_num(char *name){
    return name[2]-'A'+(name[1]-'A')*26+(name[0]-'A')*26*26;
}
char *num_to_name(int a){
    char *name;
    name=(char *)malloc(sizeof(char)*4);
    name[3]=0;
    name[0]=a/26/26+'A';
    name[1]=a%(26*26)/26+'A';
    name[2]=a%26+'A';
    return name;
}
int find(int a){
    if(Union[a]<0||a==Union[a]) return a;
    else return Union[a]=find(Union[a]);
}
void merge(int a, int b){
    int x, y;
    x=find(a);
    y=find(b);
    if(x!=y){
        if(Union[x]==x) Union[x]=-1+(Union[y]<0?Union[y]:0);
        else if(Union[x]<0) Union[x]+=(-1+(Union[y]<0?Union[y]:0));
        Union[y]=x;
    }
}
int main(int argc, char *argv[]){
    int N;
    int K;
    int count=0, count_temp=0;
    int temp;
    int total;
    char a[4],b[4];
    for(int i=0;i<max;i++) Union[i]=i;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++){
        scanf("%s",a);
        getchar();
        scanf("%s",b);
        scanf("%d",&temp);
        Time[name_to_num(a)]+=temp;
        Time[name_to_num(b)]+=temp;
        Time_total[name_to_num(a)]+=temp;
        merge(name_to_num(a),name_to_num(b));
    }
    for(int i=0;i<max;i++) if(Union[i]<=-2) record[count++].num=i;
    count_temp=count;
    for(int i=0;i<count;i++){
        temp=0;
        total=0;
        for(int j=0;j<max;j++){
            if(check[i]==-Union[record[i].num]+1) break;
            if(find(j)==record[i].num){
                check[i]++;
                if(Time[j]>temp){
                    temp=Time[j];
                    head[i]=j;
                }
                total+=Time_total[j];
            }
        }
        record[i].num=head[i];
        if(total>K) record[i].flag=1;
        else {record[i].flag=0;count_temp--;}
    }
    /*for(int i=0;i<count;i++){
        for(int j=0;j<check[i];j++){
            printf("%s ",num_to_name(name[i][j]));
        }
        printf("%d ",Union[record[i].num]);
        printf("\n");
    }
    for(int i=0;i<max;i++) if(Union[i]!=i) printf("%s %d\n",num_to_name(i),Union[i]);*/
    printf("%d\n",count_temp);
    qsort(record,count,sizeof(record[0]),cmp);
    for(int i=0;i<count;i++){
        if(!record[i].flag) break;
        printf("%s %d\n",num_to_name(record[i].num),-Union[find(record[i].num)]+1);
    }
    return 0;
}