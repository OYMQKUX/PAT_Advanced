#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]){
    int N;
    int a[54];
    int b[54];
    int temp;
    scanf("%d",&N);
    for(int i=0;i<54;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<54;i++){
        temp=i;
        for(int j=0;j<N;j++){
            temp=a[temp]-1;
        }
        b[temp]=i;
    }
    for(int i=0;i<53;i++){
        if(b[i]/13==0) printf("S%d ",b[i]%13+1);
        else if(b[i]/13==1) printf("H%d ",b[i]%13+1);
        else if(b[i]/13==2) printf("C%d ",b[i]%13+1);
        else if(b[i]/13==3) printf("D%d ",b[i]%13+1);
        else printf("J%d ",b[i]%13+1);
    }
    if(b[53]/13==0) printf("S%d",b[53]%13+1);
    else if(b[53]/13==1) printf("H%d",b[53]%13+1);
    else if(b[53]/13==2) printf("C%d",b[53]%13+1);
    else if(b[53]/13==3) printf("D%d",b[53]%13+1);
    else printf("J%d",b[53]%13+1);
    return 0;
}