#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1<<30
int N;
int M;
int S, D; //source and destination
struct pos{
    struct info *next;
}pos[500];
struct info{
    int num;
    int dis;
    int time;
    struct info *next;
};
int visited[500];
int path[500];
int Times[500];
int pre[500];
struct fastest{
    int time;
    int pre;
    int count;
}fastest[500];
int ans1[500];
int count1;
int ans2[500];
int count2;
void Initialize(){
    for(int i = 0; i < 500; i++){
        path[i] = max;
        Times[i] = max;
        fastest[i].time = max;
        fastest[i].count = max;
    }
    memset(pre, -1, sizeof(pre));
}
void DFS(){
    path[S] = 0;
    Times[S] = 0;
    while(1){
        int temp = -1, min = max;
        struct info *tempt;
        for(int i = 0; i < N; i++){
            if(fastest[i].time < min && !visited[i]){
                temp = i;
                min = fastest[i].time;
            }
        }
        if(temp == -1) break;
        visited[temp] = 1;
        tempt = pos[temp].next;
        while(tempt){
            if(!visited[tempt->num]){
                if(fastest[temp].time + tempt->time < fastest[tempt->num].time){
                    fastest[tempt->num].time = fastest[temp].time + tempt->time;
                    fastest[tempt->num].pre = temp;
                    fastest[tempt->num].count = fastest[temp].count + 1;
                }
                else if(fastest[temp].time + tempt->time == fastest[tempt->num].time){
                    if(fastest[tempt->num].count > fastest[temp].count + 1){
                        fastest[tempt->num].pre = temp;
                        fastest[tempt->num].count = fastest[temp].count + 1;
                    }
                }
            }
            tempt = tempt->next;
        }
    }
}
void Dijkstra(){
    path[S] = 0;
    while(1){
        int temp = -1, min = max;
        struct info *tempt;
        for(int i = 0; i < N; i++){
            if(path[i] < min && !visited[i]){
                temp = i;
                min = path[i];
            }
        }
        if(temp == -1) break;
        visited[temp] = 1;
        tempt = pos[temp].next;
        while(tempt){
            if(!visited[tempt->num]){
                if(path[temp] + tempt->dis < path[tempt->num]){
                    path[tempt->num] = path[temp] + tempt->dis;
                    Times[tempt->num] = Times[temp] + tempt->time;
                    pre[tempt->num] = temp;
                }
                else if(path[temp] + tempt->dis == path[tempt->num]){
                    if(Times[tempt->num] > Times[temp] + tempt->time){
                        Times[tempt->num] = Times[temp] + tempt->time;
                        pre[tempt->num] = temp;
                    }
                }
            }
            tempt = tempt->next;
        }
    }
}
int check(){
    if(count1 != count2) return 0;
    else{
        for(int i = count1 - 1; i >= 0; i--){
            if(ans1[i] != ans2[i]) return 0;
        }
        return 1;
    }
}
int main(int argc, char *argv[]){
    int a, b;
    int one_way;
    int dis, ti;
    struct info *temp;
    scanf("%d%d", &N, &M);
    Initialize();
    for(int i = 0; i < M; i++){
        temp = (struct info *)malloc(sizeof(struct info));
        scanf("%d%d%d%d%d", &a, &b, &one_way, &dis, &ti);
        temp->dis = dis;
        temp->time = ti;
        temp->num = b;
        temp->next = pos[a].next;
        pos[a].next = temp;
        if(!one_way){
            temp = (struct info *)malloc(sizeof(struct info));
            temp->dis = dis;
            temp->time = ti;
            temp->num = a;
            temp->next = pos[b].next;
            pos[b].next = temp;
        }
    }
    scanf("%d%d", &S, &D);
    Dijkstra();
    memset(visited, 0, sizeof(visited));
    fastest[S].time = 0;
    fastest[S].count = 1;
    DFS();
    a = D;
    ans1[count1++] = D;
    while(a != S){
        a = pre[a];
        ans1[count1++] = a;
    }
    b = D;
    ans2[count2++] = D;
    while(b != S){
        b = fastest[b].pre;
        ans2[count2++] = b;
    }
    if(check()){
        printf("Distance = %d; Time = %d: ", path[D], fastest[D].time);
        for(int i = count1 - 1; i > 0; i--)
            printf("%d -> ", ans1[i]);
        printf("%d\n", ans1[0]);
    }
    else{
        printf("Distance = %d: ", path[D]);
        for(int i = count1 - 1; i > 0; i--)
            printf("%d -> ", ans1[i]);
        printf("%d\n", ans1[0]);
        printf("Time = %d: ", fastest[D].time);
        for(int i = count2 - 1; i > 0; i--)
            printf("%d -> ", ans2[i]);
        printf("%d\n", ans2[0]);
    }
    return 0;
}