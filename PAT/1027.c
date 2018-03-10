#include <stdio.h>
int main(int argc, char *argv[]){
    int a, b, c;
    char _a[3],_b[3],_c[3];
    scanf("%d%d%d",&a,&b,&c);
    if(a/13<=9) _a[0]=a/13+'0';
    else _a[0]=a/13-10+'A';
    if(a%13<=9) _a[1]=a%13+'0';
    else _a[1]=a%13-10+'A';
    if(b/13<=9) _b[0]=b/13+'0';
    else _b[0]=b/13-10+'A';
    if(b%13<=9) _b[1]=b%13+'0';
    else _b[1]=b%13-10+'A';
    if(c/13<=9) _c[0]=c/13+'0';
    else _c[0]=c/13-10+'A';
    if(c%13<=9) _c[1]=c%13+'0';
    else _c[1]=c%13-10+'A';
    _a[2]=0;_b[2]=0;_c[2]=0;
    printf("#%s%s%s\n",_a,_b,_c);
    return 0;
}