#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maximum 1<<30
int num;
int char_to_int(char *num){
  return (num[0] - '0') * 1000 + (num[1] - '0') * 100 + (num[2] - '0') * 10 + (num[3] - '0');
}
char *int_to_char(int num){
  char *number;
  number = (char *) malloc (sizeof(char) * 5);
  number[0] = num/1000 + '0';
  number[1] = (num % 1000) / 100 + '0';
  number[2] = (num % 100) / 10 + '0';
  number[3] = num %10 + '0';
  return number;
}
char *sort(char *num){
  char temp;
  for(int i = 0; i < 4; i++){
    for(int j = i + 1; j < 4; j++){
      if(num[i] < num[j]){
        temp = num[i];
        num[i] = num[j];
        num[j] = temp;
      }
    }
  }
  return num;
}
int cmp1(const void *a, const void *b){
  return *(char *)b - *(char *)a;
}
int cmp2(const void *a, const void *b){
  return *(char *)a - *(char *)b;
}
int main(int argc, const char * argv[]) {
  char temp1[5], temp2[5];
  scanf("%d",&num);
  //for(int i=0; i < 10000; i++){
  //  memcpy(num, int_to_char(i), 5);
  //  printf("if(num == %d) printf(\"", i);
  do{
    memcpy(temp1, int_to_char(num), 5);
    memcpy(temp2, temp1, 5);
    qsort(temp1, 4, sizeof(char), cmp1);
    qsort(temp2, 4, sizeof(char), cmp2);
    num = char_to_int(temp1) - char_to_int(temp2);
    printf("%s - %s = %04d", temp1, temp2, num);
    printf("\n");
  }while(num != 6174 && num != 0);
  //  printf("\");");
  //}
  return 0;
}