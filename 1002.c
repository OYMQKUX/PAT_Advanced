#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int max(int a, int b){return a>b?a:b;};
int main(int argc, char *argv[]){
    int a_exp=0, b_exp=0, exp;
    double a_coe, b_coe, coe;
    int K,i;
    double a[1001];
    memset(a,0,sizeof(a));
    double b[1001];
    memset(b,0,sizeof(b));
    scanf("%d",&K);
    if(K){
        scanf("%d%lf",&a_exp,&a_coe);
        a[a_exp]=a_coe;
        for(i=0;i<K-1;i++){
            scanf("%d%lf",&exp,&coe);
            a[exp]=coe;
        }
    }
    scanf("%d",&K);
    if(K){
        scanf("%d%lf",&b_exp, &b_coe);
        b[b_exp]=b_coe;
        for(i=0;i<K-1;i++){
            scanf("%d%lf",&exp,&coe);
            b[exp]=coe;
        }
    }
    K=0;
    for(i=max(a_exp,b_exp);i>=0;i--){
        if(a[i]+b[i]) K++;
    }
    if(K)printf("%d ",K);
    else printf("%d\n",K);
    for(i=max(a_exp,b_exp);i>=0;i--){
        if(K>=2){
            if(a[i]+b[i]) {printf("%d %.1f ",i,a[i]+b[i]);K--;}}
        else break;
    }
    for(;i>=0;i--) if(a[i]+b[i]) printf("%d %.1f\n",i,a[i]+b[i]);
    return 0;
}