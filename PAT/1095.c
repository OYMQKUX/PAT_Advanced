#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define max 24*3600
int N, K;
int total;
int cars;
int num[max][2];   //counting the number of cars for every seconds
struct car{
    char plate[8];
    int time;   //record the time
    int state;  // 1 for in, 0 for out
    int last;   //counting the parking time
}car[10001], ans[10001];
int cmp(const void *a, const void *b){
    struct car *c, *d;
    c = (struct car*) a;
    d = (struct car*) b;
    if(strcmp(c->plate, d->plate)) return strcmp(c->plate, d->plate);
    else return c->time - d->time;
}
int cmp1(const void *a, const void *b){
    struct car *c, *d;
    c = (struct car*) a;
    d = (struct car*) b;
    if(c->last != d->last) return d->last - c->last;
    else return strcmp(c->plate, d->plate);
}
int cmp2(const void *a, const void *b){
    struct car *c, *d;
    c = (struct car*) a;
    d = (struct car*) b;
    return c->time - d->time;
}
void remove_error(){
    char temp_id[9];
    int flag;
    qsort(car, N, sizeof(car[0]), cmp);
    for(int i = 0; i < N; i++){
        flag = 0;
        strcpy(temp_id, car[i].plate);
        while(strcmp(temp_id, car[i].plate) == 0){
            while(car[i].state){
                i++;
                if(strcmp(temp_id, car[i].plate)) {flag = 1; break;}
            }
            if(flag) break;
            if(!i) {i++; continue;}
            if(strcmp(temp_id, car[i-1].plate) == 0 && car[i-1].state){
                ans[cars] = car[i-1];
                ans[cars+1] = car[i];
                cars += 2;
            }
            i++;
        }
        i--;
    }
}
void analyse_last(){
    char temp_id[9];
    int last;
    qsort(ans, cars, sizeof(ans[0]), cmp);
    for(int i = 0; i < cars; i++){
        last = 0;
        strcpy(temp_id, ans[i].plate);
        while(strcmp(temp_id, ans[i].plate) == 0){
            last += ans[i+1].time - ans[i].time;
            i += 2;
        }
        ans[--i].last = last;
    }
}
void analyse_num(){
    int temp = 0;
    total = 1;
    qsort(ans, cars, sizeof(ans[0]), cmp2);
    while(temp < cars - 1){
        if(!num[ans[temp].time][1]){
            if(ans[temp].time) num[ans[temp].time][0] = num[ans[temp].time-1][0];
            num[ans[temp].time][1] = 1;
        }
        if(ans[temp].state) num[ans[temp].time][0]++;
        else num[ans[temp].time][0]--;
        for(int i = ans[temp].time + 1; i < ans[temp+1].time; i++){
            num[i][0] = num[i-1][0];
        }
        temp++;
    }
    if(!num[ans[temp].time][1]){
        num[ans[temp].time][0] = num[ans[temp].time-1][0];
        num[ans[temp].time][1] = 1;
    }
    if(ans[temp].state) num[ans[temp].time][0]++;
    else num[ans[temp].time][0]--;
    for(int i = ans[temp].time + 1; i < max; i++){
        num[i][0] = num[i-1][0];
    }
}
int main(int argc, char *argv[]){
    char states[4];
    int hh, mm, ss;
    int time;
    int longest, count = 0;
    scanf("%d%d", &N, &K);
    getchar();
    for(int i = 0; i < N; i++){
        scanf("%s", car[i].plate);
        scanf("%d:%d:%d", &hh, &mm, &ss);
        car[i].time = hh * 3600 + mm *60 + ss;
        getchar();
        scanf("%s", states);
        if(strcmp(states, "in") == 0) car[i].state = 1;
        else car[i].state = 0;
    }
    remove_error();
    analyse_last();
    analyse_num();
    for(int i = 0; i < K; i++){
        scanf("%d:%d:%d", &hh, &mm, &ss);
        time = hh * 3600 + mm * 60 + ss;
        printf("%d\n", num[time][0]);
    }
    qsort(ans, cars, sizeof(ans[0]), cmp1);
    longest = ans[0].last;
    for(int i = 0; i < N; i++){
        if(ans[i].last != longest) break;
        count++;
    }
    for(int i = 0; i < count; i++){
        printf("%s ", ans[i].plate);
    }
    printf("%02d:%02d:%02d\n", ans[0].last / 3600, ans[0].last % 3600 / 60, ans[0].last % 60);
    return 0;
}