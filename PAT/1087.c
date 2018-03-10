#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 26*26*26
#define maximum 1<<30
int hash[max];
int name[201];
int happy[201];
int cost[201][201];
int num[201];
int happiness[201];
int costs[201];
int visited[201];
int diff[201];
int pre[201];
int ans[201];
int count;
int N;
int K;
int start;
int char_to_int(char *name){
  return name[2] - 'A' + (name[1] - 'A') * 26 + (name[0] - 'A') * 26 * 26;
}
char *int_to_char(int num){
  char *ans = malloc(sizeof(char) * 4);
    ans[0] = num / 26 / 26 + 'A';
    ans[1] = num % (26 * 26) / 26 + 'A';
    ans[2] = num % 26 + 'A';
    ans[3] = 0;
    return ans;
}
void Dijkstra(){
    for(int i = 0; i < N; i++){
      costs[i] = maximum;
    }
    costs[hash[start]] = 0;
    while(1){
      int min = maximum;
        int temp = -1;
        for(int i = 0; i < N; i++){
            if(!visited[i] && costs[i] < min){
              min = costs[i];
                temp = i;
            }
        }
        visited[temp] = 1;
        if(temp == -1) break;
        for(int i = 0; i < N; i++){
            if(!visited[i]){
                if(costs[i] > costs[temp] + cost[temp][i]){
                  costs[i] = costs[temp] + cost[temp][i];
                    num[i] = num[temp] + 1;
                    happiness[i] = happiness[temp] + happy[i];
                    diff[i] = diff[temp];
                    pre[i] = temp;
                }
                else if(costs[i] == costs[temp] + cost[temp][i]){
                    if(happiness[temp] + happy[i] > happiness[i]){
                      happiness[i] = happiness[temp] + happy[i];
                        num[i] = num[temp] + 1;
                        pre[i] = temp;
                    }
                    else if(happiness[temp] + happy[i] == happiness[i]){
                        if(num[i] > num[temp] + 1){
                          num[i] = num[temp] + 1;
                            diff[i] = diff[temp] + 1;
                            pre[i] = temp;
                        }
                    }
                    if(temp) diff[i] += diff[temp];
                }
            }
        }
    }
}
int main(){
    char name1[4], name2[4];
    int roma;
    scanf("%d%d", &N, &K);
    getchar();
    scanf("%s", name1);
    start = char_to_int(name1);
    hash[start] = 0;
    name[0] = start;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
          cost[i][j] = maximum;
        }
        diff[i] = 1;
    }
    for(int i = 0; i < N -1; i++){
      scanf("%s", name1);
        name[i+1] = char_to_int(name1);
        hash[name[i+1]] = i + 1;
        scanf("%d", &happy[hash[name[i+1]]]);
        getchar();
    }
    for(int i = 0; i < K; i++){
      scanf("%s%s", name1, name2);
        scanf("%d", &cost[hash[char_to_int(name1)]][hash[char_to_int(name2)]]);
        cost[hash[char_to_int(name2)]][hash[char_to_int(name1)]] = cost[hash[char_to_int(name1)]][hash[char_to_int(name2)]];
        getchar();
    }
    Dijkstra();
    roma = hash[char_to_int("ROM")];
    printf("%d %d %d %d\n", diff[roma], costs[roma], happiness[roma], happiness[roma] / num[roma]);
    while(roma){
      ans[count++] = roma;
        roma = pre[roma];
    }
    printf("%s->", int_to_char(name[0]));
    for(int i = count - 1; i > 0; i--){
      printf("%s->", int_to_char(name[ans[i]]));
    }
    printf("%s\n", int_to_char(name[ans[0]]));
    return 0;
}