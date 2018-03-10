#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int inp[100000];
int check[10000];
int N;
int flag;
int main(int argc, char *argv[]){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&inp[i]);
        check[inp[i]]++;
    }
    for(int i=0;i<N;i++)
        if(check[inp[i]]==1){
            printf("%d\n",inp[i]);
            flag=1;
            break;
        }
    if(!flag) printf("None\n");
    return 0;
}