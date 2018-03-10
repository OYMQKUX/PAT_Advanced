#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
long long ans[10000][2];
int count;
int prime(int x){
  if(x==2||x==3) return 1;
  for(int i=2;i<=sqrt(x);i++){
    if(x%i==0) return 0;
  }
  return 1;
}
int main(int argc, char *argv[]){
  long long inp;
  long long temp;
  int i;
  scanf("%lld",&inp);
  temp=inp;
  //printf("%lf\n",sqrt(inp));
  for(i=2;i<=sqrt(inp)&&inp;i++){
    if(prime(i)&&inp%i==0){
      ans[count][0]=i;
      while(inp%i==0){
        inp/=i;
        ans[count][1]++;
      }
      count++;
    }
    //printf("%lf %d\n",sqrt(inp),i);
  }
  if(inp>1) ans[count++][0]=inp;
  if(count==0) ans[count++][0]=1;
  inp=temp;
  printf("%lld=",inp);
  for(i=0;i<count-1;i++)
    if(ans[i][1]>1) printf("%lld^%lld*",ans[i][0],ans[i][1]);
    else printf("%lld*",ans[i][0]);
  if(ans[i][1]>1) printf("%lld^%lld\n",ans[i][0],ans[i][1]);
  else printf("%lld\n",ans[i][0]);
  return 0;
}