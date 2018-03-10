#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int N;
int L;
int ans[1001];
int visited[1001];
int sum;
struct User{
    int num2;
    int followed[1001];
}user[1001];
void BFS(int temp, int level){
    if(level > L) return;
    visited[temp] = 1;
    for(int i = 0; i < user[temp].num2; i++){
        if(!ans[user[temp].followed[i]]){
          sum++;
            ans[user[temp].followed[i]] = 1;
        }
    }
    for(int i = 0; i < user[temp].num2; i++){
        if(visited[user[temp].followed[i]] == 0){
            BFS(user[temp].followed[i], level+1);
        }
    }
}
int main(int argc, char *argv[]){
    int num;
    int temp;
    scanf("%d%d", &N, &L);
    for(int i = 1; i <= N; i++){
      scanf("%d", &num);
        for(int j = 0; j < num; j++){
          scanf("%d", &temp);
            user[temp].followed[user[temp].num2++] = i;
        }
    }
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        sum = 0;
         memset(ans, 0, sizeof(ans));
        memset(visited, 0, sizeof(visited));
      scanf("%d", &temp);
        ans[temp] = 1;
        BFS(temp, 1);
        printf("%d\n", sum);
    }
    return 0;
}