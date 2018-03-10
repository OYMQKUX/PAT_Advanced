#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int K;
unsigned long len;
char inp[2011];
char ans[2011];
int printed[40];
int hash[40];   //0~9 a~z _
int count;
int total;
char chara[40];
int Hash(char x){
    if(x >= '0' && x <= '9'){
        return x - '0';
    }
    else if(x == '_') return 36;
    else return x - 'a' + 10;
}
int check(int pos){
    int i = pos + 1;
    int flag = 1;
    if(hash[Hash(inp[pos])] == 1){
        return pos;
    }
    for(; i < pos + K; i++){
        if(inp[i] != inp[pos] || i >= len){
            flag = 0;
            break;
        }
    }
    if(!flag){
        hash[Hash(inp[pos])] = 1;
        return pos;
    }
    else{
        return pos + K - 1;
    }
}
int main(int argc, char *argv[]){
    scanf("%d", &K);
    getchar();
    scanf("%s", inp);
    len = strlen(inp);
    for(int i = 0; i < len; i++){
        i = check(i);
    }
    for(int i = 0; i < len; i++){
        if(!hash[Hash(inp[i])]){
            if(!printed[Hash(inp[i])]){
                chara[total++] = inp[i];
                printed[Hash(inp[i])] = 1;
            }
            i += K - 1;
        }
        ans[count++] = inp[i];
    }
    printf("%s\n", chara);
    printf("%s\n", ans);
    return 0;
}