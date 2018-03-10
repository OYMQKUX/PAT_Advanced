#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(int argc, char *argv[]){
    int req_num, i;
    int time=0;
    scanf("%d",&req_num);
    int a, b;
    a=0;
    for(i=1;i<=req_num;i++){
        scanf("%d",&b);
        if(b>a) time+=(b-a)*6+5;
        else  time+=(a-b)*4+5;
        a=b;
    }
    printf("%d\n",time);
    return 0;
}