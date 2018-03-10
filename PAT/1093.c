#include<stdio.h>
#include<string.h>
char inp[100010];
long long P, PA, PAT;
int main(){
    P = PA = PAT = 0;
    scanf("%s", inp);
    long len = strlen(inp);
    for(int i = 0; i < len; i++){
        if(inp[i] == 'P') {P++;}
        if(inp[i] == 'A') {PA += P;}
        if(inp[i] == 'T') {PAT += PA;}
    }
    printf("%lld\n", PAT % 1000000007);
    return 0;
}