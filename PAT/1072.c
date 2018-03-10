#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Infinity 1<<30
struct node{
    int weight;
    int num;
    struct node *next;
}node[1111];
int dis[1111];
int visited[1111];

int N;//number of house
int M;//number of candidate location
int K;//number of roads connecting houses and the gas stations
int D_S;//maximum service range of the gas station
int total;
void Dijkstra(int start){
    dis[start] = 0;
    while(1){
        struct node *temp1 = NULL;
      int temp = -1;
        int min = Infinity;
        for(int i = 1; i <= total; i++){
            if(!visited[i] && dis[i] < min){
              min = dis[i];
                temp = i;
            }
        }
        if(temp == -1) break;
        visited[temp] = 1;
        temp1 = node[temp].next;
        while(temp1){
          if(!visited[temp1->num] && min + temp1->weight < dis[temp1->num])
                dis[temp1->num] = min +temp1->weight;
            temp1 = temp1->next;
        }
    }
}
int check(int num){
  struct node *temp;
    int flag = 1;
    temp = node[num].next;
    for(int i = 1; i <= N; i++){
        if(dis[i] > D_S){
          flag = 0;
            break;
        }
    }
    return flag;
}
int string_to_num(char *string, unsigned long len){
    int ans = 0;
    for(int i = 0;i < len; i++){
      ans *= 10;
        ans += string[i] - '0';
    }
    return ans;
}
int change(char *inp){
    int ans = 0;
    if(inp[0] == 'G'){
      ans = string_to_num(inp + 1, strlen(inp) - 1);
        ans += N;
    }
    else ans = string_to_num(inp, strlen(inp));
    return ans;
}
void SCANF(){
    char inp1[10], inp2[10];
    struct node *temp1, *temp2;
    for(int i = 0; i < K; i++){
        scanf("%s", inp1);
        scanf("%s", inp2);
        temp1 = (struct node*)malloc(sizeof(struct node));
        temp2 = (struct node*)malloc(sizeof(struct node));
        temp1->num = change(inp1);
        temp2->num = change(inp2);
        scanf("%d", &temp1->weight);
        temp2->weight = temp1->weight;
        temp1->next = node[change(inp2)].next;
        temp2->next = node[change(inp1)].next;
        node[change(inp2)].next = temp1;
        node[change(inp1)].next = temp2;
    }
}
int main(int argc, char *argv[]){
    int max = -1;
    double ans = Infinity;
    int temp_min = 0;
    int flag = 0;
    int index = 0;
    double sum = 0.0;
    scanf("%d%d%d%d", &N, &M, &K, &D_S);
    total = N + M;
    SCANF();
    for(int i = N+1; i <= total; i++){
        memset(visited, 0, sizeof(int) * (total + 1));
        for(int j = 1; j<=total; j++)
            dis[j] = Infinity;
        Dijkstra(i);
        if(check(i)){
            flag = 1;
            temp_min = Infinity;
            sum = 0;
            for(int j = 1; j <= N; j++){
              if(temp_min > dis[j]) temp_min = dis[j];
              sum += dis[j];
            }
            if(temp_min > max){
              max = temp_min;
                ans = sum/N;
                index = i;
            }
            else if(temp_min == max){
                if(ans > sum/N){
                  ans = sum/N;
                    index = i;
                }
            }
        }
    }
    if(!flag) printf("No Solution\n");
    else{
      printf("G%d\n", index - N);
        printf("%.1f ", max*1.0);
        printf("%.1f\n", (int)(ans * 10 + 0.5) / 10.0);
    }
    return 0;
}