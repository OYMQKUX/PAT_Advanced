#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define INT_MAX 2<<29
int N;
int M;
int coin[100000];
int cmp(const void *a, const void *b){
    return *(int *)a-*(int *)b;
}
int dichotomy(int i){
    int front=i+1, tail=N-1;
    int middle;
    while(front<=tail){
        middle=(front+tail)/2;
        if(coin[middle]==M-coin[i]) return middle;
        else if(coin[middle]>M-coin[i]) tail=middle-1;
        else front=middle+1;
    }
    return -1;
}
int main(int argc, char *argv[]){
    int i, ans=-1;
    int flag=0;
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++) scanf("%d",&coin[i]);
    qsort(coin,N,sizeof(int),cmp);
    for(i=0;i<N;i++){
        ans=dichotomy(i);
        if(ans!=-1) {flag=1; break;}
    }
    if(flag) printf("%d %d\n",coin[i],coin[ans]);
    else printf("No Solution\n");
    return 0;
}