#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(int argc, char *argv[]){
    int a, b;
    scanf("%d%d",&a,&b);
    if(abs(a+b)>=1000&&abs(a+b)<1000000){
        if(a+b>0) printf("%d,%03d\n",(a+b)/1000,(a+b)%1000);
        else printf("-%d,%03d\n",-(a+b)/1000,-(a+b)%1000);
    }
    else if(abs(a+b)>=1000000){
        if(a+b>=1000000) printf("%d,%03d,%03d\n",(a+b)/1000000,(a+b)%1000000/1000,(a+b)%1000);
        else printf("-%d,%03d,%03d\n",-(a+b)/1000000,-(a+b)%1000000/1000,-(a+b)%1000);
    }
    else {
        printf("%d\n",a+b);
    }
    return 0;
}