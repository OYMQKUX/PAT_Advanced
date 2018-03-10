#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct digit{
    char dig;
    int next;
    int flag;
};
struct digit a[100000];
int main(int argc, char *argv[]){
    int first1, first2;
    int addr;
    int i;
    int flag=0;
    scanf("%d%d",&first1, &first2);
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&addr);
        getchar();
        scanf("%c%d",&a[addr].dig,&a[addr].next);
    }
    for(i=first1;i!=-1;){
        a[i].flag=1;
        i=a[i].next;
    }
    for(i=first2;i!=-1;){
        if(a[i].flag) {flag=1;break;}
        i=a[i].next;
    }
    if(flag) printf("%05d\n",i);
    else printf("-1\n");
    return 0;
}