#include <iostream>
#include <cstdio>
using namespace std;
struct list{
    int addr;
    int value;
    int next;
}inp[100000], tmp[100000], ans[100000];
int pos;
int main(int argc, char *argv[]){
    int head, N, K;
    int addr;
    int len = 0;
    int i = 0;
    cin >> head >> N >> K;
    for(i = 0; i < N; i++){
        cin >> addr;
        inp[addr].addr = addr;
        cin >> inp[addr].value >> inp[addr].next;
    }
    i = 0;
    while(head != -1){
        tmp[i] = inp[head];
        head = tmp[i].next;
        i++;
    }
    len = i;
    for(i = 0; i < len; i++){
        if(tmp[i].value < 0) ans[pos++] = tmp[i];
    }
    for(i = 0; i < len; i++){
        if(tmp[i].value >= 0 && tmp[i].value <= K) ans[pos++] = tmp[i];
    }
    for(i = 0; i < len; i++){
        if(tmp[i].value > K) ans[pos++] = tmp[i];
    }
    for(i = 0; i < len - 1; i++){
        printf("%05d %d %05d\n", ans[i].addr, ans[i].value, ans[i+1].addr);
    }
    printf("%05d %d -1\n", ans[len-1].addr, ans[len-1].value);
    return 0;
}