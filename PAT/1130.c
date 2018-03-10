#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N;
int root = 1;
struct node{
    char str[11];
    int father;
    struct node *left;
    struct node *right;
}node[21];
void dfs(struct node *a){
    if(a->father != 0){
        if(a->left || (strcmp(a->str, "-") == 0)){
            printf("(");
        }
    }
    if(a->left){
        dfs(a->left);
    }
    printf("%s", a->str);
    if(a->right){
        dfs(a->right);
    }
    if(a->father != 0){
        if(a->left || (strcmp(a->str, "-") == 0)){
            printf(")");
        }
    }
}
int main(int argc, char *argv[]){
    int left, right;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        getchar();
        scanf("%s", node[i].str);
        scanf("%d%d", &left, &right);
        if(left != -1) node[i].left = &node[left];
        if(right != -1) node[i].right = &node[right];
        if(left != -1) node[left].father = i;
        if(right != -1) node[right].father = i;
    }
    while(node[root].father != 0){
        root = node[root].father;
    }
    dfs(&node[root]);
    printf("\n");
    return 0;
}