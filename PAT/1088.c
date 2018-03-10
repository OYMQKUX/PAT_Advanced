#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long a, b, c, d;
long long integer;
char ans[6][1000];
char ope[4] = {'+', '-', '*', '/'};
int digit(long long num){
    int i = 0;
    while(num){
        num /= 10;
        i++;
    }
    return i;
}

char *int_to_string(long long num){
  char *ans;
    int i = digit(num);
    ans = (char *)malloc(sizeof(char) * (i + 3));
    if(num < 0) {ans[0] = '('; ans[1] = '-'; ans[i+2] = ')';num *= -1;i++;}
    else i--;
    while(num){
      ans[i--] = num % 10 + '0';
        num /= 10;
    }
    return ans;
}

char *mix_number_to_string(long long integer, long long zi, long long mu){
  char *ans;
    int i = digit(integer) + digit(zi) + digit(mu);
    int j, k;
    ans = (char *)malloc(sizeof(char) * (i + 5));
    if(integer < 0){
      ans[0] = '(';
        ans[1] = '-';
        ans[i+4] = ')';
        integer *= -1;
        i = digit(integer) + 1;
        j = i + 1 + digit(zi);
        k = j + 1 + digit(mu);
        ans[k+2] = 0;
    }
    else{
        i = digit(integer) - 1;
      j = i + 1 + digit(zi);
        k = j + 1 + digit(mu);
        ans[k+1] = 0;
    }
    ans[i + 1] = ' ';
    ans[j + 1] = '/';
    while(integer){
      ans[i--] = integer % 10 + '0';
        integer /= 10;
    }
    while(zi){
      ans[j--] = zi % 10 + '0';
        zi /= 10;
    }
    while(mu){
      ans[k--] = mu % 10 + '0';
        mu /= 10;
    }
    return ans;
}
char *fraction_to_string(long long zi, long long mu){
  char *ans;
    int i = digit(zi) + digit(mu);
    int j;
    ans = (char *)malloc(sizeof(char) * (i + 4));
    if(zi < 0){
        ans[0] = '(';
        ans[1] = '-';
        ans[i+3] = ')';
        zi *= -1;
        i = digit(zi) + 1;
        j = i + 1 + digit(mu);
        ans[j+2] = 0;
    }
    else{
        i = digit(zi) - 1;
        j = i + 1 + digit(mu);
        ans[j+1] = 0;
    }
    ans[i + 1] = '/';
    while(zi){
        ans[i--] = zi % 10 + '0';
        zi /= 10;
    }
    while(mu){
        ans[j--] = mu % 10 + '0';
        mu /= 10;
    }
    return ans;
}
long long gcd(long long a, long long b){
  long long temp;
    while(b){
      temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
void change(long long num1, long long num2, int num){
    long long temp;
    if(num2 == 0 && num ==5) {strcpy(ans[5], "Inf"); return;}
  if(!num1) ans[num][0] = '0';
    else{
      temp = gcd(num1, num2);
        num1 /= temp;
        num2 /= temp;
        if(num1 < 0 || num2 < 0) {num2 = llabs(num2); num1 = llabs(num1) * -1;}
        if(num1 % num2 == 0){
          strcpy(ans[num], int_to_string(num1 / num2));
        }
        else{
            if(llabs(num1) > llabs(num2)){
              integer = num1 / num2;
                num1 -= integer * num2;
                if(integer < 0) {num2 = llabs(num2);num1 = llabs(num1);}
                strcpy(ans[num], mix_number_to_string(integer, num1, num2));
            }
            else{
              strcpy(ans[num], fraction_to_string(num1, num2));
            }
        }
    }
}
int main(){
    scanf("%lld/%lld%lld/%lld", &a, &b, &c, &d);
    change(a, b, 0);
    change(c, d, 1);
  change(a * d + c * b, b * d, 2);
    change(a * d - c * b, b * d, 3);
    change(a * c, b * d, 4);
    change(a * d, b * c, 5);
    for(int i = 0; i < 4; i++){
        printf("%s %c %s = %s\n", ans[0], ope[i], ans[1], ans[i+2]);
    }
    return 0;
}