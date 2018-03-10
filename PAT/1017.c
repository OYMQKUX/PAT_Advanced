#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
struct custom{
    int hour, min, sec;
    int time;
    int arrive;
};
int cmp(const void *a, const void *b){
    struct custom *c, *d;
    c=(struct custom*)a;
    d=(struct custom*)b;
    return c->arrive-d->arrive;
}
int main(int argc, char *argv[]){
    int N, K, n=0, pos=0;
    int hour, min, sec, time;
    int wait=0;
    int flag=0;
    double ave=0.0;
    scanf("%d%d",&N,&K);
    int i, j;
    int win[K];
    memset(win,0,sizeof(int)*K);
    struct custom a[N];
    for(i=0;i<N;i++){
        scanf("%d:%d:%d%d",&hour,&min,&sec,&time);
        if((hour*3600+min*60+sec<=17*3600)){
            a[n].hour=hour;
            a[n].min=min;
            a[n].sec=sec;
            a[n].time=time;
            a[n].arrive=hour*3600+min*60+sec;
            n++;
        }
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=0;i<K;i++) win[i]=8*3600;
    //for(i=0;i<K;i++) printf("%d\n",win[i]);
    //for(i=0;i<n;i++) printf("%d %d %d %d %d\n",a[i].hour, a[i].min, a[i]. sec,a[i].time, a[i].arrive);
    for(i=0;i<n;i++){
        time=INT_MAX;
        pos=0;
        flag=0;
        for(j=0;j<K;j++){
            if(a[i].arrive>=win[j]){
                win[j]=a[i].arrive+a[i].time*60;
                flag=1;
                break;
            }
            else{
                if(time>win[j]){
                    time=win[j];
                    pos=j;
                }
            }
        }
        if(!flag){
            wait+=time-a[i].arrive;
            win[pos]+=a[i].time*60;
        }
    }
    if(n){
        ave=wait*1.0/n;
        printf("%.1f\n",ave/60.0);
    }
    else printf("0.0\n");
   return 0;
}