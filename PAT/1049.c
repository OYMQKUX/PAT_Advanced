#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n;
int temp;
int count;
int temp1[10];
int power(int a, int b){
    int sum=1;
    if(b==0) return 1;
    for(int i=0;i<b;i++){
        sum*=a;
    }
    return sum;
}
int main(int argc, char *argv[]){
    int total=0;
  scanf("%d",&n);
  count=0;
    temp=n;
    while(temp/10){
        temp1[count++]=temp%10;
        temp/=10;
    }
  temp1[count]=temp;
  for(int i=0;i<=count;i++){
    if(temp1[i]==0){
      total+=power(10,i)*(n/power(10,i+1));
    }
    else if(temp1[i]==1){
      total+=power(10,i)*(n/power(10,i+1)?(n/power(10,i+1)):0)+n%power(10,i)+1;
    }
    else if(temp1[i]>1){
      total+=power(10,i)*(n/power(10,i+1)+1);
    }
  }
  printf("%d\n",total);
    return 0;
}