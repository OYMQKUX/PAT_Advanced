#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N;
int K;
struct stu{
    int exist;
    int checked;
    int rank;
}stu[10000];
int prime(int x){
    if(x == 2 || x == 3) return 1;
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0) return 0;
    }
    return 1;
}
int main(int argc, char *argv[]){
    int id;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &id);
        stu[id].exist = 1;
        stu[id].rank = i;
    }
    scanf("%d", &K);
    for(int i = 0; i < K; i++){
        scanf("%d", &id);
        printf("%04d: ", id);
        if(!stu[id].exist) printf("Are you kidding?\n");
        else if(stu[id].checked) printf("Checked\n");
        else{
            if(stu[id].rank == 1) printf("Mystery Award\n");
            else if(prime(stu[id].rank)) printf("Minion\n");
            else printf("Chocolate\n");
            stu[id].checked = 1;
        }
    }
    return 0;
}