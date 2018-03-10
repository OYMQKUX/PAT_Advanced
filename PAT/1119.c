#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N;
int queue[30];
int count;
struct tree{
    int value;
    struct tree *left;
    struct tree *right;
}*root;
int pre[30];
int post[30];
int pair_pre[29];
int pair_post[29];
void Build(struct tree *node, int head_pre, int tail_pre, int head_post, int tail_post, int len){
    if(len < 1) return;
    int i;
    int temp;
    int temp_len;
    struct tree *left, *right;
    right = (struct tree*)malloc(sizeof(struct tree));
    temp = pre[head_pre];
    for(i = head_post; i <= tail_post; i++)
        if(post[i] == temp) break;
    temp_len = i - head_post;
    if(i == tail_post){
        right->value = post[i];
        right->left = NULL;
        right->right = NULL;
        node->right = right;
        Build(right, head_pre + 1, tail_pre, head_post, tail_post - 1, len - 1);
    }
    else{
        left = (struct tree*)malloc(sizeof(struct tree));
        left->value = post[i];
        left->left = NULL;
        left->right = NULL;
        node->left = left;
        Build(left, head_pre + 1, head_pre + temp_len, head_post, i - 1, temp_len);
        right->value = pre[head_pre + temp_len + 1];
        right->left = NULL;
        right->right = NULL;
        node->right = right;
        Build(right, head_pre + temp_len + 2, tail_pre, i + 1, tail_post - 1, len - temp_len - 2);
    }
}
void Inorder_traversal(struct tree *node){
    if(node->left) Inorder_traversal(node->left);
    queue[count++] = node->value;
    if(node->right) Inorder_traversal(node->right);
}
int main(int argc, char *argv[]){
    int flag = 1;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &pre[i]);
        if(i) pair_pre[pre[i]] = pre[i-1];
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &post[i]);
        if(i) pair_post[post[i]] = post[i-1];
    }
    for(int i = 1; i < N; i++){
        if(pre[i] == pair_post[pair_pre[pre[i]]]){
            flag = 0;
        }
    }
    root = (struct tree*)malloc(sizeof(struct tree));
    root->value = pre[0];
    root->left = NULL;
    root->right = NULL;
    Build(root, 1, N - 1, 0, N - 2, N - 1);
    if(flag) printf("Yes\n");
    else printf("No\n");
    Inorder_traversal(root);
    for(int i = 0; i < count - 1; i++)
        printf("%d ", queue[i]);
    printf("%d\n", queue[count-1]);
    return 0;
}