#include <stdio.h>
int main(){  
    int a1,b1,c1,a2,b2,c2;  
    scanf("%d.%d.%d",&a1,&b1,&c1);  
    scanf("%d.%d.%d",&a2,&b2,&c2);  
    int a,b,c,carry;  
    c=(c1+c2)%29;  
    carry=(c1+c2)/29;  
    b=(b1+b2+carry)%17;  
    carry=(b1+b2+carry)/17;  
    a=a1+a2+carry;  
    printf("%d.%d.%d",a,b,c);  
    return 0;  
}  