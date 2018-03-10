#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int N;
long long gcd(long long a, long long b){
    long long temp;
    while(a % b){
        temp = b;
      b = a % b;
        a = temp;
    }
    return b;
}
long long lcm(long long a, long long b){
    return a * b / gcd(a, b);
}
void change(long long mu1, long long zi1){
    if(zi1 == 0) printf("0\n");
  else if(llabs(mu1) > llabs(zi1))
        if(mu1 * zi1 < 0) printf("-%lld/%lld\n", llabs(zi1), llabs(mu1));
      else printf("%lld/%lld\n", zi1, mu1);
    else if(zi1 % mu1 == 0 && mu1 / zi1 >= 0) printf("%lld\n", zi1/mu1);
    else if(zi1 % mu1 == 0 && mu1 / zi1 < 0) printf("-%lld\n", zi1/mu1);
    else if(zi1 < 0){
      printf("%lld ", zi1/mu1);
        printf("%lld/%lld\n", zi1 * -1 % mu1, mu1);
    }
    else if (zi1 > 0){
      printf("%lld ", zi1/mu1);
        printf("%lld/%lld\n", zi1 % mu1, mu1);
    }
}
int main(int argc, char *argv[]){
    long long zi1, mu1, zi2, mu2;
    long long temp;
  scanf("%d", &N);
    scanf("%lld/%lld", &zi1, &mu1);
    for(int i = 1; i < N; i++){
        temp = gcd(zi1, mu1);
        zi1 /= temp;
        mu1 /= temp;
      scanf("%lld/%lld", &zi2, &mu2);
        temp = gcd(zi2, mu2);
        zi2 /= temp;
        mu2 /= temp;
        zi1 = lcm(mu1, mu2) / mu1 * zi1 + lcm(mu1, mu2) / mu2 * zi2;
        mu1 = lcm(mu1, mu2);
    }
    temp = gcd(zi1, mu1);
    zi1 /= temp;
    mu1 /= temp;
    change(mu1, zi1);
    return 0;
}