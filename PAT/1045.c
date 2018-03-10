#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define INT_MAX 2<<29
int N;
int M;
int L;
int len[201][10001];
int fav[201];
int given[10001];
int max;
void LCS(){
    int i, j;
    for(i=1;i<=M;i++){
        for(j=1;j<=L;j++){
            max=len[i-1][j-1];
            if(max<len[i-1][j]) max=len[i-1][j];
            if(max<len[i][j-1]) max=len[i][j-1];
            if(given[j-1]==fav[i-1])
                len[i][j]=max+1;
            else len[i][j]=max;
        }
    }
}
int main(int argc, char *argv[]){
    int i;
    scanf("%d",&N);
    scanf("%d",&M);
    for(i=0;i<M;i++) scanf("%d",&fav[i]);
    scanf("%d",&L);
    for(i=0;i<L;i++) scanf("%d",&given[i]);
    LCS();
    printf("%d\n",len[M][L]);
    return 0;
}