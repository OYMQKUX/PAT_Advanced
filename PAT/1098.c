#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N;
int arr[100];
int sort_arr[100];
int heap[1000];
int Times;
int check(){
    int i;
    int flag = 1;
    for(i = 1; i < N; i++) if(sort_arr[i] < sort_arr[i-1]) break;
    flag = i;
    for(;i < N; i++) if(sort_arr[i] != arr[i]) flag = 0;
    return flag;
}
void exchange(int pos){
    int temp;
    if(heap[pos * 2 + 1] != -1){
        if(heap[pos] < heap[pos * 2] || heap[pos] < heap[pos * 2 + 1]){
            if(heap[pos * 2] > heap[pos * 2 + 1]){
                temp = heap[pos * 2];
                heap[pos * 2] = heap[pos];
                heap[pos] = temp;
                if(heap[pos * 2] < heap[pos * 4] || heap[pos * 2] < heap[pos * 4 + 1])
                    exchange(pos * 2);
            }
            else{
                temp = heap[pos * 2 + 1];
                heap[pos * 2 + 1] = heap[pos];
                heap[pos] = temp;
                if(heap[pos * 2 + 1] < heap[pos * 4 + 2] || heap[pos * 2 + 1] < heap[pos * 4 + 3])
                    exchange(pos * 2 + 1);
            }
        }
    }
    else{
        if(heap[pos] < heap[pos * 2]){
            temp = heap[pos * 2];
            heap[pos * 2] = heap[pos];
            heap[pos] = temp;
        }
    }
}
int complete(){
    int flag = 1;
    for(int i = 0; i < N; i++){
        if(sort_arr[i] != heap[i+1]) {flag = 0;break;}
    }
    return flag;
}
void build(){
    for(int i = 0; i < N; i++)
        heap[i+1] = arr[i];
    for(int i = N; i >= 1; i--){
        if(heap[i * 2] != -1){
            exchange(i);
        }
    }
}
void operate(){
    int temp;
    int parent;
    int child;
    temp = heap[1];
    heap[1] = heap[N-Times];
    heap[N-Times] = temp;
    temp = heap[1];
    parent = 1;
    while(1){
        child = parent * 2;
        if(child + 1 >= N - Times) break;
        if(heap[child + 1] > heap[child]) child++;
        if(temp < heap[child]){
            heap[parent] = heap[child];
            parent = child;
        }
        else break;
    }
    if(child < N - Times && heap[child] > temp) {heap[parent] = heap[child]; parent = child;}
    heap[parent] = temp;
}
int main(int argc, char *argv[]){
    int flag;
    int i;
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < N; i++){
        scanf("%d", &sort_arr[i]);
    }
    flag = check();
    if(flag){
        printf("Insertion Sort\n");
        for(i = 0; i < N; i++){
            if(sort_arr[i] < sort_arr[flag]) printf("%d ", sort_arr[i]);
            else break;
        }
        printf("%d ", sort_arr[flag]);
        for(; i < N - 1; i++){
            if(i != flag) printf("%d ", sort_arr[i]);
        }
        printf("%d\n", sort_arr[N-1]);
    }
    else{
        memset(heap, -1, sizeof(heap));
        printf("Heap Sort\n");
        build();
        //for(int i = 1; i <= N; i++) printf("%d ", heap[i]);
        //printf("\n");
        while(!complete() && Times <= N){
            operate();
            Times++;
            //for(int i = 1; i <= N; i++) printf("%d ", heap[i]);
            //printf("\n");
        }
        if(Times < N) operate();
        for(int i = 1; i < N; i++) printf("%d ", heap[i]);
        printf("%d\n", heap[N]);
    }
    return 0;
}