#include <stdio.h>
#include <stdlib.h>
#define maximum 1<<30
int N, M;
int F[10001][101];
int coin[10001];
int has[10001][101];
int ans[10001];
int count;
int cmp(const void *a, const void *b){
  return *(int *)b-*(int *)a;
}
int main(int argc, const char * argv[]) {
  scanf("%d%d",&N, &M);
  for(int i=1; i<=N; i++){
    scanf("%d", &coin[i]);
  }
  qsort(coin+1, N, sizeof(int), cmp);
  for(int i=1; i<=N;i++){
    for(int j=1; j<=M; j++){
      int temp = j-coin[i] >= 0 ? (F[i-1][j-coin[i]] + coin[i]) : 0;
      if(F[i-1][j] > temp)
        F[i][j] = F[i-1][j];
      else {
        F[i][j] = temp;
        has[i][j] = 1;
      }
    }
  }
  /*for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++){
      printf("%d %d %d\n", i, j, F[i][j]);
      printf("%d\n\n", has[i][j]);
    }
   */
  if(F[N][M]!=M) printf("No Solution\n");
  else{
    while(M){
      while(!has[N][M]) N--;
      ans[count++] = coin[N];
      M -= coin[N];
      N--;
    }
    for(int i=0; i<count-1;i++) printf("%d ", ans[i]);
    printf("%d\n", ans[count-1]);
  }
  return 0;
}