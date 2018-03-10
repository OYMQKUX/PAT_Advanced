#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N;
int root;
int ans[200];
int queue[200];
int head = 0, tail = 0;
int count = 1;
struct tree{
    int left, right;
    int father;
}tree[20];
void push_queue(int x){
    queue[++tail] = x;
}
void push_ans(int x){
    ans[count++] = x;
}
int pop_queue(){
    return queue[head++];
}
void level_traversal(){
    int temp;
    queue[0] = root;
    ans[0] = root;
    while(head <= tail){
        temp = pop_queue();
        if(tree[temp].left != -1) push_queue(tree[temp].left);
        if(tree[temp].right!= -1) push_queue(tree[temp].right);
        push_ans(tree[temp].left);
        push_ans(tree[temp].right);
    }
}
int main(int argc, char *argv[]){
    char left[3], right[3];
    int flag = 1;
    scanf("%d", &N);
    getchar();
    memset(tree, -1, sizeof(tree));
    memset(queue, -1, sizeof(queue));
    for(int i = 0; i < N; i++){
        scanf("%s%s", left, right);
        if(left[0] != '-') {
            if(strlen(left) == 1) tree[i].left = left[0] - '0';
            else tree[i].left = left[1] - '0' + (left[0] - '0') * 10;
            tree[tree[i].left].father = i;
        }
        if(right[0] != '-') {
            if(strlen(right) == 1) tree[i].right = right[0] - '0';
            else tree[i].right = right[1] - '0' + (right[0] - '0') * 10;
            tree[tree[i].right].father = i;
        }
    }
    while(tree[root].father != -1){
        root = tree[root].father;
    }
    level_traversal();
    for(int i = 0; i <= N - 1; i++){
        if(ans[i] == -1){
            flag = 0;
            break;
        }
    }
    if(flag){
        printf("YES %d\n", ans[N-1]);
    }
    else printf("NO %d\n", root);
    return 0;
}