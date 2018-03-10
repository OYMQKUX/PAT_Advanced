#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int N;
int MSize;
int hash[100000];
int prime(int a){
    if(a == 1) return 0;
  if(a == 2 || a == 3) return 1;
    for(int i = 2; i <= sqrt(a); i++){
      if(a % i == 0) return 0;
    }
    return 1;
}
int main(int argc, char *argv[]){
    int inp;
    int flag = 0;
    memset(hash, -1, sizeof(hash));
    scanf("%d%d", &MSize, &N);
    while(!prime(MSize)) MSize++;
    for(int i = 0; i < N; i++){
      scanf("%d", &inp);
        flag = 0;
        for(int j = 0; j < MSize; j++){
            if(hash[(inp + j * j) % MSize] == -1){
              if(i != N - 1) printf("%d ", (inp + j * j) % MSize);
                else printf("%d\n", (inp + j * j) % MSize);
                hash[(inp + j * j) % MSize] = 1;
                flag = 1;
                break;
            }
        }
        if(!flag){
          if(i == N - 1) printf("-\n");
            else printf("- ");
        }
    }
    return 0;
}