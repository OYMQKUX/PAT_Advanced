#include<cstdio>  
#include<iostream>  
#include<cstring>  
#include<cmath>  
#include<string>  
#include<vector>  
#include<map>  
#include<set>  
#include<algorithm>  
#include<sstream>  
using namespace std;  
int charToInt(char x)//字符转数字  
{  
    if('0'<=x&&x<='9')  
        return x-'0';  
    else  
        return x-'a'+10;  
}  
long long charToDecimal(char* x,long long radix)//字符串转对应进制数字  
{  
    int len=strlen(x);  
    long long ans=0;  
    for(int i=0;i<len;++i)  
    {  
        ans*=radix;  
        ans+=charToInt(x[i]);  
        if(ans<0)  
            return -1;  
    }  
    return ans;  
}  
int main()  
{  
    char as[15],bs[15],temp[15];  
    long long tag,radix,aimNum;  
    int lenA,lenB;  
    scanf("%s%s%lld%lld",as,bs,&tag,&radix);  
    if(tag==1)  
    {  
        strcpy(temp,as);  
        strcpy(as,bs);  
        strcpy(bs,temp);  
        tag=2;  
    }  
    lenA=strlen(as);  
    lenB=strlen(bs);  
    aimNum=charToDecimal(bs,radix);  
    long long low=2;//进制下限  
    for(int i=0,j;i<lenA;++i)  
    {  
        j=charToInt(as[i]);  
        if(j>=low)  
            low=j+1;  
    }  
    long long high=aimNum+1;//进制上限  
    long long aimRadix;  
    long long tempAns;  
    bool flag=false;  
    for(;low<=high;)//二分搜索  
    {  
        aimRadix=(high+low)/2;  
        tempAns=charToDecimal(as,aimRadix);  
        if(tempAns==-1||tempAns>aimNum)  
            high=aimRadix-1;  
        else if(tempAns<aimNum)  
            low=aimRadix+1;  
        else  
        {  
            flag=true;  
            break;  
        }  
    }  
    if(flag)  
        printf("%lld\n",aimRadix);  
    else  
        printf("Impossible\n");  
    return 0;  
}  