#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int N;
int main(int argc, char *argv[]){
  long long a, b, c;
  long long ans;
  int flag=1;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    flag=1;
    scanf("%lld%lld%lld",&a,&b,&c);
    ans=a+b;
    if(a>=0&&b>=0&&ans<0) flag=1;
    else if(a<0&&b<0&&ans>=0) flag=0;
    else{
      if(ans<=c) flag=0;
    }
    if(flag) printf("Case #%d: true\n",i+1);
    else printf("Case #%d: false\n",i+1);
  }
}