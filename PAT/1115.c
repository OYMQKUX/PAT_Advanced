#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N;
int max_level;
int first, second;
int head, tail = -1;
struct node{
  int value;
    int level;
    struct node *left;
    struct node *right;
}*header, queue[1000];
void Insert(int temp){
    struct node *tree = header;
    int temp_level = 1;
    if(!tree){
        tree = (struct node*)malloc(sizeof(struct node));
        tree->value = temp;
        tree->level = 1;
        tree->left = NULL;
        tree->right = NULL;
        header = tree;
        return;
    }
    while(tree){
        if(tree->value >= temp){
            if(tree->left){
                tree = tree->left;
                temp_level++;
            }
            else{
                tree->left = (struct node*)malloc(sizeof(struct node));
                tree->left->value = temp;
                tree->left->level = temp_level + 1;
                tree->left->left = NULL;
                tree->left->right = NULL;
                break;
            }
        }
        else{
            if(tree->right){
                tree = tree->right;
                temp_level++;
            }
            else {
                tree->right = (struct node*)malloc(sizeof(struct node));
                tree->right->value = temp;
                tree->right->level = temp_level + 1;
                tree->right->left = NULL;
                tree->right->right = NULL;
                break;
            }
        }
    }
}
void Push(struct node *x){
    queue[++tail] = *x;
}
struct node *Pop(){
   return &queue[head++];
}
void level_traversal(){
    struct node *temp = header;
    Push(header);
    while(head <= tail){
        temp = Pop();
        if(temp->left) Push(temp->left);
        if(temp->right) Push(temp->right);
    }
}
int main(int argc, char *argv[]){
    int temp;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        if(temp >= -1000 && temp <= 1000) Insert(temp);
    }
    level_traversal();
    max_level = queue[tail].level;
    for(int i = tail; i >= 0; i--){
        if(queue[i].level == max_level) first++;
        else if(queue[i].level == max_level - 1) second++;
        else break;
    }
    printf("%d + %d = %d\n", first, second, first + second);
    return 0;
}