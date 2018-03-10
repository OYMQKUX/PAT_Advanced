#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N;
int arr[1000000];
int matrix[1000][1000];
int dire_x[4] = {0, 1, 0, -1};
int dire_y[4] = {1, 0, -1, 0};
int cmp(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}
int find(){
    int m;
    for(m = sqrt(N); m >= 1; m--){
        if(N % m == 0){
            break;
        }
    }
    return m;
}
int main(int argc, char *argv[]){
    int x = 0, y = 0;
    int m, n;
    int direction = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), cmp);
    memset(matrix, -1, sizeof(matrix));
    m = find();
    n = N / m;
    if(n > m){
        int temp = n;
        n = m;
        m = temp;
    }
    for(int i = 0; i < N; i++){
        matrix[x][y] = arr[i];
        if(x + dire_x[direction] >= m || x + dire_x[direction] < 0 || y + dire_y[direction] >= n || y + dire_y[direction] < 0 || matrix[x + dire_x[direction]][y + dire_y[direction]] != -1){
            direction++;
            direction %= 4;
        }
        x += dire_x[direction];
        y += dire_y[direction];
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n - 1; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("%d\n", matrix[i][n-1]);
    }
    return 0;
}