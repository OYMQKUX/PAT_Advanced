#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int M;
int N;
int L;
int T;
long long local_count = 0, count;
char slice[60][1286][128];
int queue[60*1286*128][3];
int head, tail;
void Push(int i, int j, int k){
  queue[tail][0] = i;
    queue[tail][1] = j;
    queue[tail][2] = k;
    tail++;
}
int *Pop(){
  return queue[head++];
}
void DFS(int i, int j, int k){
    int *temp;
    while(head < tail){
        temp = Pop();
        i = temp[0];
        j = temp[1];
        k = temp[2];
        local_count++;
      if(i - 1 >= 0 && slice[i-1][j][k] == 1){
        Push(i - 1, j, k);
            slice[i-1][j][k] = 2;
      }
      if(i + 1 < L && slice[i+1][j][k] == 1){
        Push(i + 1, j, k);
            slice[i+1][j][k] = 2;
      }
      if(j - 1 >= 0 && slice[i][j-1][k] == 1){
        Push(i, j - 1, k);
            slice[i][j-1][k] = 2;
      }
      if(j + 1 < M && slice[i][j+1][k] == 1){
          Push(i, j + 1, k);
            slice[i][j+1][k] = 2;
      }
      if(k - 1 >= 0 && slice[i][j][k-1] == 1){
          Push(i, j, k - 1);
            slice[i][j][k-1] = 2;
      }
      if(k + 1 < N && slice[i][j][k+1] == 1){
          Push(i, j, k + 1);
            slice[i][j][k+1] = 2;
      }
    }
}
int main(){
  scanf("%d%d%d%d", &M, &N, &L, &T);
    for(int i = 0; i < L; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < N; k++){
                getchar();
              scanf("%c", &slice[i][j][k]);
                slice[i][j][k] -= '0';
            }
        }
    }
  for(int i = 0; i < L; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < N; k++){
                if(slice[i][j][k] == 1){
                    Push(i, j, k);
                    slice[i][j][k] = 2;
                    DFS(i, j, k);
                    if(local_count >= T) count += local_count;
                    local_count = 0;
                }
            }
        }
    }
    printf("%lld\n", count);
    return 0;
}