#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N;
double sum;
int count;
char inp[100][100];
int check(char *inp,unsigned long len){
    int dot_count = 0, neg_count = 0;
  double num;
    for(int i = 0; i < len; i++){
        if(inp[i] == '-' || inp[i] == '.' || (inp[i] >= '0' && inp[i] <= '9')){
            if(inp[i] == '.') dot_count++;
            if(inp[i] == '-') neg_count++;
        }
        else{
            return 0;
            break;
        }
    }
    if(dot_count > 1 || neg_count > 1) return 0;
    if(neg_count == 1 && inp[0] != '-') return 0;
    if(dot_count == 1 && inp[0] == '.') return 0;
    if(dot_count == 1){
        int i = 0;
        for(; i < len; i++){
            if(inp[i] == '.') break;
        }
        if(len - 1 - i > 2) return 0;
    }
  