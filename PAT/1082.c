#include<stdio.h>
int inp[10];
char brr[9][6]={" Yi"," Qian"," Bai"," Shi"," Wan"," Qian"," Bai"," Shi", ""};
char crr[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int flag;
int pos;
void output(int i,int x){
    if(x){
        if(pos++) printf(" ");
        if(flag){
          printf("ling ");
        }
        flag = 0;
        printf("%s%s", crr[x], brr[i]);
    }
    else{
        if(i == 4){
          printf(" Wan");
            flag = 0;
            return;
        }
        if(i == 8){
          return;
        }
      flag = 1;
    }
}

int main(){
    int x,i,j;
    scanf("%d",&x);
    if(x == 0){
      printf("ling\n");
        return 0;
    }
    if(x < 0){
        printf("Fu ");
        x = -x;
    }
    if(x % 100000000 == 0){
      printf("%s Yi\n", crr[x / 100000000]);
        return 0;
    }
    j = 0;
    i = 100000000;
    while(i){
      inp[j++] = x / i;
        x %= i;
        i /= 10;
    }
    for(i = 0; i < 9; i++){
      if(inp[i]) break;
    }
    for(; i < 9; i++){
      output(i, inp[i]);
    }
    printf("\n");
    return 0;
}