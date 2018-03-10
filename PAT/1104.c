#include<stdio.h>
int N;
double sum = 0;
int main(int argc, char *argv[]){
    double temp;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lf", &temp);
        sum += temp * (i + 1) * (N - i);
    }
    printf("%.2lf\n", sum);
    return 0;
}