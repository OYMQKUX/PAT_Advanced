#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct station{
    double P_i;
    double D_i;
};
double C_max;
double D;
double D_avg;
int N;
struct station a[501];
int cmp(const void *a, const void *b){
    return ((struct station*)a)->D_i-(((struct station*)b)->D_i);
}
int main(int argc, char *argv[]){
    int i, j, index, index1;
    int flag, flag1;
    double max_dis;
    double min,min1;
    double price=0;
    double remain;
    scanf("%lf%lf%lf%d",&C_max, &D, &D_avg, &N);
    for(i=0;i<N;i++){
        scanf("%lf%lf",&a[i].P_i,&a[i].D_i);
    }
    a[i].P_i=-1;
    a[i].D_i=D;
    max_dis=D_avg*C_max;
    qsort(a,N,sizeof(a[0]),cmp);
    //for(int i=0;i<N;i++) printf("%.2f %d\n",a[i].P_i,a[i].D_i);
    remain=0;
    if(a[0].D_i){
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    for(i=0;i<N+1;){
        j=i+1;
        flag=0;
        flag1=0;
        index=j;
        index1=j;
        min=a[i].P_i;
        min1=a[i+1].P_i;
        if(i!=N){
            while(a[j].D_i-a[i].D_i<=max_dis&&j<N+1){
                if(a[j].P_i<min){
                    min=a[j].P_i;
                    index=j;
                    flag=1;
                    break;
                }
                else if(a[j].P_i<min1){
                    min1=a[j].P_i;
                    index1=j;
                    flag1=0;
                }
                j++;
                flag1=1;
            }
            if(flag){
                if(remain*D_avg<a[index].D_i-a[i].D_i){
                    price+=(a[index].D_i-a[i].D_i-remain*D_avg)/D_avg*a[i].P_i;
                    remain=(a[index].D_i-a[i].D_i)/D_avg;
                }
                remain-=(a[index].D_i-a[i].D_i)/D_avg;
                i=index;
            }
            else if(flag1){
                price+=(C_max-remain)*a[i].P_i;
                remain=C_max;
                remain-=(a[index1].D_i-a[i].D_i)/D_avg;
                i=index1;
            }
            else{
                printf("The maximum travel distance = %.2lf\n",a[i].D_i+max_dis);
                return 0;
            }
        }
        else {
            i++;
        }
    }
    //for(int i=0;i<N;i++) printf("%.2f %d\n",a[i].P_i,a[i].D_i);
    printf("%.2lf\n",price);
}