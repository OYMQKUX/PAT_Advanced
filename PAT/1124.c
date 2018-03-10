#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int M;
int N;
int S;
int count;
char forward[1001][21];
char ans[1001][21];
int check(char *temp){
    int flag = 1;
    for(int i = 0;i < count; i++)
        if(!strcmp(ans[i], temp)){
            flag = 0;
            break;
        }
    return flag;
}
int main(int argc, char *argv[]){
    scanf("%d%d%d", &M, &N, &S);
    getchar();
    for(int i = 1; i <= M; i++){
        scanf("%s", forward[i]);
    }
    if(S > M) printf("Keep going...\n");
    else{
        while(S <= M){
            if(check(forward[S])) strcpy(ans[count++], forward[S]);
            else{
                while(!check(forward[S]) && S <= M){
                    S++;
                }
                if(check(forward[S])) strcpy(ans[count++], forward[S]);
            }
            S += N;
        }
        for(int i = 0; i < count; i++)
            printf("%s\n", ans[i]);
    }
    return 0;
}