#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int inp[1000];
int flag1=1;
int flag2=1;
int N;
void check_search_tree(int pos, int len){
    if(len==1||len==0) return;
    int i=pos+1;
    while(inp[i]<inp[pos]&&i<pos+len) i++;
    for(int j=i;j<pos+len;j++)
        if(inp[j]<inp[pos]){
            flag1=0;
            return;
        }
    check_search_tree(pos+1,i-pos-1);
    check_search_tree(i,len-i+pos);
}
void check_mir_search_tree(int pos, int len){
    if(len==1||len==0) return;
    int i=pos+1;
    while(inp[i]>=inp[pos]&&i<pos+len) i++;
    for(int j=i;j<pos+len;j++)
        if(inp[j]>=inp[pos]){
            flag2=0;
            return;
        }
    check_mir_search_tree(pos+1,i-pos-1);
    check_mir_search_tree(i,len-i+pos);
}
void Print_2(int pos, int len){
    if(len==1){
        if(!pos) printf("%d\n",inp[pos]);
        else printf("%d ",inp[pos]);
        return;
    }
    if(len==0) return;
    int i=pos+1;
    while(inp[i]>=inp[pos]&&i<pos+len) i++;
    Print_2(pos+1,i-pos-1);
    Print_2(i,len-i+pos);
    if(pos) printf("%d ",inp[pos]);
    else printf("%d\n",inp[0]);
}
void Print_1(int pos, int len){
    if(len==1){
        if(pos) printf("%d ",inp[pos]);
        else printf("%d\n",inp[pos]);
        return;
    }
    if(len==0) return;
    int i=pos+1;
    while(inp[i]<inp[pos]&&i<pos+len) i++;
    Print_1(pos+1,i-pos-1);
    Print_1(i,len-i+pos);
    if(pos) printf("%d ",inp[pos]);
    else printf("%d\n",inp[0]);
}
int main(int argc, char *argv[]){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&inp[i]);
    check_search_tree(0,N);
    check_mir_search_tree(0,N);
    if(flag1||flag2){
        printf("YES\n");
        if(flag1) {Print_1(0,N);return 0;}
        if(flag2) Print_2(0,N);
    }
    else printf("NO\n");
    return 0;
}