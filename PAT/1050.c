#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int minus[256];
char inp[10000];
char delete[10000];
unsigned long len;
int j;
int main(int argc, char *argv[]){
  gets(inp);
  gets(delete);
  len=strlen(inp);
  for(int i=0;i<strlen(delete);i++)
    minus[delete[i]]=1;
  for(int i=0;i<len;i++)
    if(minus[inp[i]]) inp[i]=0;
  for(int i=0;i<len;i++)
    if(inp[i]) inp[j++]=inp[i];
  printf("%s\n",inp);
    return 0;
}