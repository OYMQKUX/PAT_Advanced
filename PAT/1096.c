#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int head, tail;
int temp_head, temp_tail;
int len;
int temp_len;
int temp;
int inp;
int power(int base, int time){
  long long ans = 1;
    if(time < 2) time = 2;
    for(int i = 0; i < time; i++){
      ans *= base;
    }
    if(ans > inp) return 0;
    else return 1;
}
int main(){
    scanf("%d", &inp);
    if(inp == 1) {printf("1\n1\n");return 0;}
    temp = inp;
    for(int i = 2; i <= inp; i++){
        if(!temp_head) temp_head = i;
        if(temp % i == 0){
            temp /= i;
            temp_tail = i;
            temp_len++;
        }
        else{
            if(len < temp_len){
                head = temp_head;
                tail = temp_tail;
                len = temp_len;
            }
            if((temp * temp_head) % i == 0){
              temp *= temp_head;
                temp /= i;
              temp_head++;
                temp_tail++;
            }
            else{
              temp = inp;
                temp_head = 0;
                temp_tail = 0;
                temp_len = 0;
            }
        }
        if(!power(temp_head, len)) break;
    }
    if(len < temp_len){
        head = temp_head;
        tail = temp_tail;
        len = temp_len;
    }
    if(!len){
        len = 1;
      head = inp;
        tail = inp;
    }
    printf("%d\n", len);
    for(int i = 0; i < len - 1; i++){
        printf("%d*", head + i);
    }
    printf("%d\n", head + len - 1);
    return 0;
}