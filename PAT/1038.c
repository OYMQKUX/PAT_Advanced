#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int N;
int temp;
struct string{
    char a[9];
    unsigned long len;
};
char ans[90000];
struct string str[10000];
int cmp(const void *a, const void *b){
    return strcmp((*(struct string*)a).a, (*(struct string*)b).a);
}
int main(int argc, char *argv[]){
    unsigned long i,j;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        temp=0;
        getchar();
        scanf("%s",str[i].a);
        str[i].len=strlen(str[i].a);
        if(str[i].len<8){
            for(j=str[i].len;j<8;j++){
                str[i].a[j]=str[i].a[temp%str[i].len];
                temp++;
            }
        }
        str[i].a[8]=0;
    }
    /*for(int i=0;i<N;i++)
        for(int j=0;j<str[i].len;j++)
            printf("%c",str[i].a[j]);
    printf("\n");*/
    qsort(str,N,sizeof(str[0]),cmp);
    temp=0;
    for(i=0;i<N;i++)
        for(j=0;j<str[i].len;j++)
            ans[temp++]=str[i].a[j];
    ans[temp]=0;
    temp=0;
    while(ans[temp]=='0') temp++;
    if(temp==strlen(ans)) printf("0");
    else printf("%s",ans+temp);
    /*for(i=0;i<N;i++)
        if(!temp){
            for(j=0;j<str[i].len;j++)
                if(str[i].a[j]!='0'){
                    temp=1;
                    printf("%s",str[i].a+j);
                    break;
                }
        }
        else printf("%s",str[i].a);*/
    printf("\n");
    return 0;
}