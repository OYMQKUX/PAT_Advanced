#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N;
int M;
int Union[501];
int degree[501];
int odd;
int find(int x){
    if(Union[x] < 0) return x;
    else return Union[x] = find(Union[x]);
}
void merge(int x, int y){
    int a = find(x), b = find(y);
    if(a != b){
        Union[a] += Union[b];
        Union[b] = a;
    }
}
int connected(){
    int num = 0;
    for(int i = 1; i <= N; i++)
        if(Union[i] < 0) num++;
    if(num > 1) return 0;
    else return 1;
}
int main(int argc, char *argv[]){
    int p1, p2;
    int flag;
    scanf("%d%d", &N, &M);
    memset(Union, -1, sizeof(int) * 501);
    for(int i = 0; i < M; i++){
        scanf("%d%d", &p1, &p2);
        merge(p1, p2);
        degree[p1]++;
        degree[p2]++;
    }
    for(int i = 1; i <= N; i++){
        if(i < N) printf("%d ", degree[i]);
        else printf("%d\n", degree[i]);
        if(degree[i] % 2) odd++;
    }
    flag = connected();
    if(!flag) printf("Non-Eulerian\n");
    else{
      if(!odd) printf("Eulerian\n");
      else if(odd == 2) printf("Semi-Eulerian\n");
        else printf("Non-Eulerian\n");
    }
    return 0;
}