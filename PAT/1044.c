#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define INT_MAX 2<<29
int N;
long long M;
int D[100000];
int min=INT_MAX;
int flag=0;
int sum;
int main(int argc, char *argv[]){
    int i, j;
    scanf("%d%lld",&N,&M);
    for(i=0;i<N;i++) scanf("%d",&D[i]);
    for(i=0;i<N;i++){
        if(!i) sum=0;
        else {sum-=D[i-1];sum-=D[j];}
        for(;j<N;j++){
            sum+=D[j];
            if(sum==M){
                flag=1;
                printf("%d-%d\n",i+1,j+1);
                break;
            }
            else if(sum>M) break;
        }
    }
    if(!flag){
        j=0;
        for(i=0;i<N;i++){
            if(!i) sum=0;
            else {sum-=D[i-1];sum-=D[j];}
            for(;j<N;j++){
                sum+=D[j];
                if(sum<min&&sum>M) {min=sum;break;}
                else if(sum>min) break;
            }
        }
        j=0;
        for(i=0;i<N;i++){
            if(!i) sum=0;
            else {sum-=D[i-1];sum-=D[j];}
            for(;j<N;j++){
                sum+=D[j];
                if(sum==min) {printf("%d-%d\n",i+1,j+1);break;}
                else if(sum>min) break;
            }
        }
    }
    return 0;
}