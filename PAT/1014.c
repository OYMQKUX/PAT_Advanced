#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int N, M, K, Q;
int window[20][1000];
int T[1000];
int len[20];
int querey[1000];
int past_time[20];
int pos[20];
int main(int argc, char *argv[]){
    int i, j, k=0, l;
    scanf("%d%d%d%d",&N,&M,&K,&Q);
    int win=0, time=0;
    int hour=0, min=0;
    int count=0;
    int flag=0;
    memset(T,0,sizeof(T));
    memset(len,0,sizeof(len));
    memset(pos,0,sizeof(pos));
    memset(past_time,0,sizeof(past_time));
    for(int i=0;i<K;i++) scanf("%d",&T[i]);
    for(int i=0;i<Q;i++) scanf("%d",&querey[i]);
    if(K<=M*N){
        for(i=0;i<K;i++){
            window[i%N][len[i%N]++]=i;
        }
        for(i=0;i<Q;i++){
            time=0;
            win=(querey[i]-1)%N;
            for(j=0;j<(querey[i]-1)/N;j++)
                time+=T[window[win][j]];
            hour=time/60;
            min=time-hour*60;
            if(hour+8>=17) printf("Sorry\n");
            else {
                time+=T[querey[i]-1];
                hour=time/60;
                min=time-hour*60;
                printf("%02d:%02d\n", hour+8, min);
            }
        }
    }
    else{
        for(i=0;i<M*N;i++){
            window[i%N][len[i%N]++]=i;
        }
        i=0;
        while(count<K-M*N){
            for(j=0;j<N;j++){
                if(pos[j]<len[j]){
                if(T[window[j][pos[j]]]+past_time[j]==i){
                    past_time[j]+=T[window[j][pos[j]]];
                    pos[j]++;
                    window[j][len[j]++]=N*M+(count++);
                }
                }
            }
            i++;
        }
        /*for(i=0;i<N;i++){
            for(j=0;j<len[i];j++){
                printf("%d ",window[i][j]+1);
            }
            printf("\n");
        }*/
        for(i=0;i<Q;i++){
            time=0;
            count=0;
            flag=0;
            if(querey[i]<=M*N){
                win=(querey[i]-1)%N;
                for(j=0;j<(querey[i]-1)/N;j++) time+=T[window[win][j]];
                hour=time/60;
                min=time-hour*60;
                if(hour+8>=17) printf("Sorry\n");
                else{
                    time+=T[querey[i]-1];
                    hour=time/60;
                    min=time-hour*60;
                    printf("%02d:%02d\n",hour+8,min);
                }
            }
            else{
                for(j=M;j<1000;j++){
                    for(k=0;k<N;k++){
                        if(window[k][j]+1==querey[i]) {flag=1;break;}
                    }
                    if(window[k][j]+1==querey[i]) break;
                }
                for(l=0;l<j;l++){
                    time+=T[window[k][l]];
                }
                //printf("%d\n",time);
                hour=time/60;
                min=time-hour*60;
                if(hour+8>=17) printf("Sorry\n");
                else {
                    time+=T[querey[i]-1];
                    hour=time/60;
                    min=time-hour*60;
                    printf("%02d:%02d\n",hour+8,min);
                }
            }
        }
    }
    return 0;
}