#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(int argc, char *argv[]){
    int N;
    scanf("%d",&N);
    int i;
    int a[N];
    int flag=0;
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
        if(a[i]>=0) flag=1;
    }
    int temp_sum=0, temp_max=-1, head=a[0], tail=a[0];
    int first=head, second=tail;
    for(i=0;i<N;i++){
        temp_sum+=a[i];
        tail=a[i];
        if(temp_sum<0) {temp_sum=0;head=a[i+1];tail=a[i+1];}
        if(temp_sum>temp_max){
            temp_max=temp_sum;
            first=head;
            second=tail;
        }
    }
    if(N==0) return 0;
    else{
        if(!flag) printf("%d %d %d\n", 0, a[0], a[N-1]);
        else printf("%d %d %d\n",temp_max, first, second);
        return 0;
    }
}