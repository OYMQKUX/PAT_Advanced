#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct poly{
    int N;
    double aN;
};
int main(int argc, char *argv[]){
    double ans[2001];
    memset(ans, 0, sizeof(ans));
    int i,j,K1,K2,count=0;
    scanf("%d",&K1);
    struct poly a[K1];
    for(i=0;i<K1;i++){
        scanf("%d%lf",&a[i].N,&a[i].aN);
    }
    scanf("%d",&K2);
    struct poly b[K2];
    for(i=0;i<K2;i++){
        scanf("%d%lf",&b[i].N,&b[i].aN);
    }
    for(i=0;i<K1;i++)
        for(j=0;j<K2;j++){
            ans[a[i].N+b[j].N]+=a[i].aN*b[j].aN;
        }
    for(i=2000;i>=0;i--) if(fabs(ans[i])>0) count++;
    printf("%d",count);
        for(i=2000;i>=0;i--) if(fabs(ans[i])>0) {printf(" %d %.1f",i,ans[i]);count--;}
    printf("\n");
}