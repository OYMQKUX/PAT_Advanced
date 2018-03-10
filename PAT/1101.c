#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int N;
int arr[100000];
int max_arr[100000];
int min_arr[100000];
int ans[100000];
int count;
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int main(int argc, char *argv[]){
    int maximum = 0, min = INT_MAX;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < N; i++){
        if(arr[i] > maximum) maximum = arr[i];
        max_arr[i] = maximum;
    }
    for(int i = N -1; i >= 0; i--){
        if(arr[i] < min) min = arr[i];
        min_arr[i] = min;
    }
    for(int i = 0; i < N; i++){
        if(arr[i] == max_arr[i] && arr[i] == min_arr[i])
            ans[count++] = arr[i];
    }
    qsort(ans, count, sizeof(int), cmp);
    printf("%d\n", count);
    for(int i = 0; i < count - 1; i++){
        printf("%d ", ans[i]);
    }
    if(count) printf("%d", ans[count-1]);
    printf("\n");
    return 0;
}