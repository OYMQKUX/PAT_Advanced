#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N;
int K;
struct stu{
    char name[9];
    int height;
}stu[10000];
int cmp(const void *a, const void *b){
    struct stu *c, *d;
    c = (struct stu*) a;
    d = (struct stu*) b;
    if(c->height != d->height) return c->height - d->height;
    return strcmp(d->name, c->name);
}
void change(int head, int tail, int len){
    struct stu temp[len];
    int flag = 1;
    int pos = len / 2;
    for(int i = 0; i < len; i++){
        pos += i * flag;
        temp[pos] = stu[tail - i];
        flag *= -1;
    }
    for(int i = head; i <= tail; i++)
        stu[i] = temp[i-head];
}
int main(int argc, char *argv[]){
    int i;
    int num;
    scanf("%d%d", &N, &K);
    num = N / K;
    for(i = 0; i < N; i++){
        getchar();
        scanf("%s", stu[i].name);
        scanf("%d", &stu[i].height);
    }
    qsort(stu, N, sizeof(stu[0]), cmp);
    for(i = 0; i < K - 1; i++){
        change(i * num, i * num + num - 1, num);
    }
    change(i * num, N - 1, N - i * num);
  for(int j = i * num; j < N-1; j++)
        printf("%s ", stu[j].name);
    printf("%s\n", stu[N-1].name);
    for(int j = i - 1; j >= 0; j--){
        for(int k = j * num; k < j * num + num - 1; k++){
            printf("%s ", stu[k].name);
        }
        printf("%s\n", stu[j * num + num - 1].name);
    }
    return 0;
}