#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N;
int head, tail = -1;
int count;
struct node{
    int value;
    int height;
    struct node *left;
    struct node *right;
}*root, *queue[21], *ans[100];
int height(struct node* node){
    if(node) return node->height;
    else return 0;
}
int max(int a, int b){return a > b ? a : b;}
struct node* left_left_rotation(struct node *node){
    struct node* temp;
    temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    return temp;
}
struct node* right_right_rotation(struct node *node){
    struct node* temp;
    temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    temp->height = max(height(temp->left), height(node->right)) + 1;
    return temp;
}
struct node* left_right_rotation(struct node *node){
    node->left = right_right_rotation(node->left);
    return left_left_rotation(node);
}
struct node* right_left_rotation(struct node *node){
    node->right = left_left_rotation(node->right);
    return right_right_rotation(node);
}
struct node* create_node(int x){
    struct node* temp = malloc(sizeof(struct node));
    temp->value = x;
    temp->height = 0;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct node* insert_node(struct node* node, int x){
    if(!node) node = create_node(x);
    else if(x < node->value){
        node->left = insert_node(node->left, x);
        if(height(node->left) > height(node->right) + 1){
            if(node->left->value < x) node = left_right_rotation(node);
            else node = left_left_rotation(node);
        }
    }
    else{
        node->right = insert_node(node->right, x);
        if(height(node->right) > height(node->left) + 1){
            if(node->right->value < x) node = right_right_rotation(node);
            else node = right_left_rotation(node);
        }
    }
    node->height = max(height(node->left), height(node->right)) + 1;
    return node;
}
void push(struct node* x){
    queue[++tail] = x;
}
struct node* pop(){
    return queue[head++];
}
void level_traversal(){
    struct node* temp;
    push(root);
    ans[count++] = root;
    while(head <= tail){
        temp = pop();
        if(temp->left) {push(temp->left); ans[count++] = temp->left;}
        else ans[count++] = NULL;
        if(temp->right) {push(temp->right); ans[count++] = temp->right;}
        else ans[count++] = NULL;
    }
    
}
int main(int argc, char *argv[]){
    int num;
    int flag = 1;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        root = insert_node(root, num);
    }
    level_traversal();
    for(int i = 0; i <= tail; i++){
        if(i < tail) printf("%d ", queue[i]->value);
        else printf("%d\n", queue[i]->value);
    }
    for(int i = 0; i <= tail; i++){
        if(!ans[i]){
            flag = 0;
          break;
        }
    }
    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}