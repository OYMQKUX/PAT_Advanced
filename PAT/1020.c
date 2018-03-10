#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct node{
    int element;
    struct node *left;
    struct node *right;
}*tree;
tree a[30];
tree in_order(int *post, int *in, int length){
    if(!length) return NULL;
    tree node;
    int i, index;
    node=(tree)malloc(sizeof(struct node));
    node->element=post[length-1];
    for(i=0;i<length;i++){
        if(in[i]==node->element) break;
    }
    index=i+1;
    node->left=in_order(post, in, index-1);
    node->right=in_order(post+index-1, in+index, length-index);
    return node;
}
void level_traversal(tree node){
    int head=0, tail=0;
    int count=1;
    a[0]=node;
    while(head<=tail){
        if(a[head]->left!=NULL){
            a[count++]=a[head]->left;
        }
        if(a[head]->right!=NULL){
            a[count++]=a[head]->right;
        }
        if(head==tail){
            tail=count-1;
        }
        head++;
    }
}
int main(int argc, char *argv[]){
    int N;
    scanf("%d",&N);
    int post[30];
    int in[30];
    int i;
    tree root;
    for(i=0;i<N;i++) scanf("%d",&post[i]);
    for(i=0;i<N;i++) scanf("%d",&in[i]);
    root=in_order(post, in, N);
    level_traversal(root);
    for(i=0;i<N-1;i++) printf("%d ",a[i]->element);
    printf("%d\n",a[i]->element);
    return 0;
}