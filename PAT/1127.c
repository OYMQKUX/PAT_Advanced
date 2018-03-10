#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N;
struct node{
    int value;
    int level;
    struct node *left;
    struct node *right;
}*root;
int post[30];
int in[30];
int head, tail = -1;
struct node* queue[30];
int ans[30][30];
int count[30];
int final[30];
int total;
struct node* build_tree(int post_head, int post_tail, int in_head, int in_tail, int len, int level){
    if(len < 1) return NULL;
    int i;
    struct node* temp = malloc(sizeof(struct node));
    temp->value = post[post_tail];
    temp->level = level;
    temp->left = NULL;
    temp->right = NULL;
    for(i = in_head; i <= in_tail; i++){
        if(in[i] == post[post_tail]){
            break;
        }
    }
    temp->left = build_tree(post_head, post_head + i - in_head - 1, in_head, i - 1, i - in_head, level + 1);
    temp->right = build_tree(post_head + i - in_head, post_tail - 1, i + 1, in_tail, in_tail - i, level + 1);
    return temp;
}
void push(struct node* x){
    queue[++tail] = x;
    ans[x->level][count[x->level]++] = x->value;
}
struct node* pop(){
    return queue[head++];
}
void level_traversal(){
    struct node* temp;
    push(root);
    while(head <= tail){
        temp = pop();
        if(temp->left) push(temp->left);
        if(temp->right) push(temp->right);
    }
}
int main(int argc, char *argv[]){
    int dir = 0, level = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &in[i]);
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &post[i]);
    }
    root = build_tree(0, N - 1, 0, N - 1, N, 0);
    level_traversal();
    while(count[level]){
        if(dir){
            for(int i = 0; i < count[level]; i++){
                final[total++] = ans[level][i];
            }
            dir = 0;
        }
        else{
            for(int i = count[level] - 1; i >= 0; i--){
                final[total++] = ans[level][i];
            }
            dir = 1;
        }
        level++;
    }
    for(int i = 0; i < total; i++){
        if(i < total - 1) printf("%d ", final[i]);
        else printf("%d\n", final[i]);
    }
    return 0;
}