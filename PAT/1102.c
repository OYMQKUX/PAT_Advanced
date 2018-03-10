#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int N;
int head;
int count;
int ans[11];
int queue[11];
int queue_head;
int queue_tail = -1;
struct tree{
    int visited;
    int father;
    int left;
    int right;
}tree[11];
void level_traversal(){
    queue[++queue_tail] = head;
    while(queue_head <= queue_tail){
        if(tree[queue[queue_head]].left != -1)
            queue[++queue_tail] = tree[queue[queue_head]].left;
        if(tree[queue[queue_head]].right != -1)
            queue[++queue_tail] = tree[queue[queue_head]].right;
        queue_head++;
    }
    for(int i = 0; i < queue_tail; i++)
        printf("%d ", queue[i]);
    printf("%d\n", queue[queue_tail]);
}
void inorder_traversal(int pos){
    if(pos == -1) return;
    inorder_traversal(tree[pos].left);
    ans[count++] = pos;
    inorder_traversal(tree[pos].right);
}
int main(int argc, char *argv[]){
    char temp;
    memset(tree, -1, sizeof(tree));
    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; i++){
        scanf("%c", &temp);
        getchar();
        if(temp != '-') {
            tree[i].right = temp - '0';
            tree[tree[i].right].father = i;
        }
        scanf("%c", &temp);
        getchar();
        if(temp != '-'){
            tree[i].left = temp - '0';
            tree[tree[i].left].father = i;
        }
    }
    while(1){
        if(tree[head].father != -1) head = tree[head].father;
        else break;
    }
    level_traversal();
    inorder_traversal(head);
    for(int i = 0; i < count - 1; i++)
        printf("%d ", ans[i]);
    printf("%d\n", ans[count-1]);
    return 0;
}