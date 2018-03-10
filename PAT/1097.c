#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int hash[10010];
struct list{
    int value;
    int next;
}list[100010];
struct removed{
    int addr;
    int value;
}remained[100010], removed[100010];
int head;
int count1, count2;
int N;
int main(int argc, char *argv[]){
    int addr;
  scanf("%d%d", &head, &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &addr);
        scanf("%d%d", &list[addr].value, &list[addr].next);
    }
    addr = head;
    while(addr != -1){
        if(hash[abs(list[addr].value)]){
            removed[count2].value = list[addr].value;
            removed[count2].addr = addr;
            count2++;
        }
        else{
            remained[count1].value = list[addr].value;
            remained[count1].addr = addr;
            count1++;
            hash[abs(list[addr].value)] = 1;
        }
        addr = list[addr].next;
    }
    for(int i = 0; i < count1 - 1; i++)
        printf("%05d %d %05d\n", remained[i].addr, remained[i].value, remained[i+1].addr);
    printf("%05d %d -1\n", remained[count1-1].addr, remained[count1-1].value);
    for(int i = 0; i < count2 - 1; i++){
        printf("%05d %d %05d\n", removed[i].addr, removed[i].value, removed[i+1].addr);
    }
    if(count2) printf("%05d %d -1\n", removed[count2-1].addr, removed[count2-1].value);
    return 0;
}