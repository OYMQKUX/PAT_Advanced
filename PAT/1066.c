#include <stdio.h>
#include <stdlib.h>
typedef int Type;

typedef struct AVLTreeNode{
  Type key;
  int height;
  struct AVLTreeNode *left;
  struct AVLTreeNode *right;
}Node, *AVLTree;

static Node *avltree_create_node(Type key, Node *left, Node *right){
  Node *p;
  if((p = (Node *)malloc(sizeof(Node))) == NULL)
    return NULL;
  p->key = key;
  p->height = 0;
  p->left = left;
  p->right = right;
  return p;
}

static Node *avltree_maximum(Node *tree){
  while(tree->right){
    tree = tree->right;
  }
  return tree;
}

static Node *avltree_minimum(Node *tree){
  while(tree->left){
    tree = tree->left;
  }
  return tree;
}

static Node *avltree_search(Node *tree, Type key){
  int flag = 0;
  while(tree){
    if(key < tree->key) tree = tree ->left;
    else if(key > tree->key) tree = tree->right;
    else {flag = 1; break;}
  }
  if(flag) return tree;
  else return NULL;
}

int height(Node *node){
  if(node == NULL) return 0;
  else return node->height;
}

int MAX(int a, int b) {return a > b ? a : b;}

//left-left rotation
static Node *left_left_rotation(Node *k2){
  Node *k1;
  k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;
  k2->height = MAX(height(k2->left), height(k2->right)) + 1;
  k1->height = MAX(height(k1->left), k2->height) + 1;
  return k1;
}

//right-right rotation
static Node *right_right_rotation(Node *k1){
  Node *k2;
  k2 = k1->right;
  k1->right = k2->left;
  k2->left = k1;
  k1->height = MAX(height(k1->left), height(k1->right)) + 1;
  k2->height = MAX(k1->height, height(k2->right)) + 1;
  return k2;
}

//left-right rotation
/*
 Iterative rotation method
 static Node *left_right_rotation(Node *k3){
  Node *k2, *k1;
 k1 = k3->left;
 k2 = k1->right;
 k1->right = k2->left;
 k2->left = k1;
 k3->left = k2;
 k3->left = k2->right;
 k2->right = k3;
 k1->height = MAX(height(k1->left), height(k1->right)) + 1;
 k3->height = MAX(height(k3->left), height(k3->right)) + 1;
 k2->height = MAX(k1->height, k3->height) + 1;
  return k2;
 }
 */
//recursion method
static Node *left_right_rotation(Node *k3){
  k3->left = right_right_rotation(k3->left);
  return left_left_rotation(k3);
}

//right-right rotation
/*
 Iterative rotation method
 static Node *right_left_rotation(Node *k1){
 Node *k2, *k3;
 k3 = k1->right;
 k2 = k3->left;
 k3->left = k2->right;
 k2->right = k3;
 k1->right = k2;
 k1->right = k2->left;
 k2->left = k1;
 k3->height = MAX(height(k3->left), height(k3->right)) + 1;
 k2->height = MAX(height(k2->left), height(k2->right)) + 1;
 k1->height = MAX(height(k1->left), height(k1->right)) + 1;
 return k2;
 }
 */
//recursion method
static Node *right_left_rotation(Node *k1){
  k1->right = left_left_rotation(k1->right);
  return right_right_rotation(k1);
}

static Node *insert_node(Node *tree, Type key){
  if(tree == NULL){
    tree = avltree_create_node(key, NULL, NULL);
    if(tree == NULL){
      printf("ERROR: create avltree node failed!\n");
      return NULL;
    }
  }
  else if(key < tree->key){
    tree->left = insert_node(tree->left, key);
    if(height(tree->left) == height(tree->right) + 2){
      if(key < tree->left->key)
        tree = left_left_rotation(tree);
      else
        tree = left_right_rotation(tree);
    }
  }
  else if(key > tree->key){
    tree->right = insert_node(tree->right, key);
    if(height(tree->left) + 2 == height(tree->right)){
      if(key < tree->right->key)
        tree = right_left_rotation(tree);
      else
        tree = right_right_rotation(tree);
    }
  }
  else{
    //key == tree->key
    printf("Same value can't be added into one tree!\n");
  }
  tree->height = MAX(height(tree->left), height(tree->right)) + 1;
  return tree;
}

static Node *delete_node(Node *tree, Node *z){
  if(tree == NULL || z==NULL) return NULL;
  if(z->key < tree->key){
    tree->left = delete_node(tree->left, z);
    if(height(tree->right) == height(tree->left) + 2){
      if(height(tree->right->left) > height(tree->right->right))
        tree = right_left_rotation(tree);
      else
        tree = right_right_rotation(tree);
    }
  }
  else if(z->key > tree->key){
    tree->right = delete_node(tree->right, z);
    if(height(tree->right) + 2 == height(tree->left)){
      if(height(tree->left->left) > height(tree->left->right))
        tree = left_left_rotation(tree);
      else
        tree = left_right_rotation(tree);
    }
  }
  else{
    if(tree->left && tree->right){
      if(height(tree->left) > height(tree->right)){
        Node *max = avltree_maximum(tree->left);
        tree->key = max->key;
        tree->left = delete_node(tree->left, max);
      }
      else{
        Node *min = avltree_minimum(tree->right);
        tree->key = min->key;
        tree->right = delete_node(tree->right, min);
      }
    }
    else{
      Node *tmp = tree;
      tree = tree->left ? tree->left: tree->right;
      free(tmp);
    }
  }
  return tree;
}

static Node *avltree_delete(Node *tree, Type key){
  Node *z;
  if((z = avltree_search(tree, key)))
    tree = delete_node(tree, z);
  else
    printf("The node you want to delete doesn't exist in this tree!\n");
  return tree;
}

int main(int argc, const char * argv[]) {
  int N;
  int inp;
  Node *tree = NULL;
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    scanf("%d", &inp);
    tree = insert_node(tree, inp);
  }
  printf("%d\n", tree->key);
  return 0;
}