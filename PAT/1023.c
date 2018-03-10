#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]){
    char inp[22];
    char dou[22];
    int a[10];
    int b[10];
    int carry=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(inp,0,sizeof(inp));
    memset(dou,0,sizeof(dou));
    scanf("%s",inp);
    long i;
    for(i=strlen(inp)-1;i>=0;i--){
        a[inp[i]-'0']++;
        if((inp[i]-'0')*2+carry<10){
            dou[i]=(inp[i]-'0')*2+carry+'0';
            carry=0;
        }
        else{
            dou[i]=(inp[i]-'0')*2+carry-10+'0';
            carry=1;
        }
        b[dou[i]-'0']++;
    }
    for(i=0;i<=9;i++) if(a[i]!=b[i]) break;
    if(i<10||carry) printf("No\n");
    else printf("Yes\n");
    if(carry) printf("1");
    puts(dou);
}