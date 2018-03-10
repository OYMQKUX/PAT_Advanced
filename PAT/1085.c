#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long inp[100001];
int N;
int p;
int max_len = 1;
int temp_len;
int cmp(const void *a, const void *b){
  return (int)(*(long long *)a - *(long long *)b);
}
int main(){
    scanf("%d%d", &N, &p);
    for(int i = 0; i < N; i++)
        scanf("%lld", &inp[i]);
    qsort(inp, N, sizeof(long long), cmp);
    for(int i = 0; i < N - 1; i++){
        temp_len = N - i;
        if(temp_len <= max_len) break;
        int head = i + 1, tail = N - 1, middle = (head + tail) / 2;
        while(head <= tail){
            if(inp[i] * p >= inp[middle]){
              head = middle + 1;
                middle = (head + tail) / 2;
            }
            else{
              tail = middle - 1;
                middle = (head + tail) / 2;
            }
        }
        temp_len = middle - i + 1;
        if(temp_len > max_len) max_len = temp_len;
    }
    printf("%d\n", max_len);
    return 0;
}