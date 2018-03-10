#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char inp1[60],inp2[60],inp3[60],inp4[60];
unsigned long len1, len2, len3, len4;
int day;
int hour;
int min;
int main(int argc, char *argv[]){
  //scanf("%s%s%s%s",inp1,inp2,inp3,inp4);
  gets(inp1);
  gets(inp2);
  gets(inp3);
  gets(inp4);
  len1 = strlen(inp1);
  len2 = strlen(inp2);
  len3 = strlen(inp3);
  len4 = strlen(inp4);
  int index=0;
  for(int i=0;i<(len1<len2?len1:len2);i++){
    if(inp1[i]>='A'&&inp1[i]<='G'&&inp1[i]==inp2[i]){
      day=inp1[i]-'A'+1;
      index=i;
      break;
    }
  }
  for(int i=index+1;i<(len1<len2?len1:len2);i++){
    if(((inp1[i]>='0'&&inp1[i]<='9')||(inp1[i]>='A'&&inp2[i]<='N'))&&inp1[i]==inp2[i]){
        if(inp1[i]>='0'&&inp1[i]<='9') hour=inp1[i]-'0';
        else hour=10+inp1[i]-'A';
        break;
    }
  }
  for(int i=0;i<(len3<len4?len3:len4);i++){
    if(((inp3[i]>='A'&&inp3[i]<='Z')||(inp3[i]>='a'&&inp4[i]<='z'))&&inp3[i]==inp4[i]){
      min=i;
      break;
    }
  }
  switch(day){
    case 1: printf("MON ");break;
    case 2: printf("TUE ");break;
    case 3: printf("WED ");break;
    case 4: printf("THU ");break;
    case 5: printf("FRI ");break;
    case 6: printf("SAT ");break;
    default: printf("SUN ");break;
  }
  printf("%02d:%02d\n",hour,min);
  return 0;
}