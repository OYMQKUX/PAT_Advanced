#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct node *NODE;
struct node{
    int ID;
    int num;
    int *child;
};
int main(int argc, char *argv[]){
    int N, M;
    int i,j;
    int id, level;
    scanf("%d%d",&N, &M);
    int count[1000];
    int queue[1000];
    int head=0, tail=0, temp=0;
    memset(count,0,sizeof(count));
    struct node a[1000];
    for(i=0;i<N;i++) a[i].ID=i;
    for(i=0;i<M;i++){
        scanf("%d",&id);
        scanf("%d",&a[id].num);
        a[id].child=malloc(sizeof(int)*a[id].num);
        for(j=0;j<a[id].num;j++){
            scanf("%d",&a[id].child[j]);
        }
    }
    i=0;j=0;
    level=1;
    queue[0]=1;
    while(head<=tail){
        if(!a[queue[head]].num) count[level]++;
        else{
            for(i=0;i<a[queue[head]].num;i++){
                queue[++tail]=a[queue[head]].child[i];
            }
        }
        if(head==temp) {level++;temp=tail;}
        head++;
    }
    for(i=1;i<level-1;i++) printf("%d ",count[i]);
    printf("%d\n",count[i]);
    return 0;
}