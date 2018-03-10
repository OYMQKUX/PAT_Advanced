#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int max(double *a){
    if(a[0]>a[1]){
        if(a[0]>a[2]) return 0;
        else{
            return 2;
        }
    }
    else{
        if(a[1]>a[2]) return 1;
        else return 2;
    }
}
int main(int argc, char *argv[]){
    double a[3][3];
    int i, j, maxium[3];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%lf",&a[i][j]);
    for(i=0;i<3;i++){
        maxium[i]=max(a[i]);
        switch(maxium[i]){
            case 0: printf("W "); break;
            case 1: printf("T "); break;
            default: printf("L "); break;
        }
    }
    printf("%.2f\n",(a[0][maxium[0]]*a[1][maxium[1]]*a[2][maxium[2]]*0.65-1)*2);
    return 0;
}