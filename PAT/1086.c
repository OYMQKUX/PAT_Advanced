#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N;
int arr[30];
int arr_count;
int inorder[30];
int  inorder_count;
int pre_order[30];
int pre_order_count;
int post_order[30];
int post_order_count;
void traversal(int head1, int head2, int head3, int len){
    if(!len) return;
    int i;
    int temp1, temp2;
  post_order[head3 + len - 1] = pre_order[head1];
    for(i = head2; i < head2 + len; i++){
        if(inorder[i] == pre_order[head1]){
          break;
        }
    }
    temp1 = i - head2;
    temp2 = len - temp1 - 1;
    traversal(head1 + 1, i - temp1, head3, temp1);
    traversal(head1 + 1 + temp1, i + 1, head3 + temp1, temp2);
}
int main(){
    char temp[5];
  scanf("%d", &N);
    while(inorder_count < N){
        scanf("%s", temp);
        if(strcmp(temp, "Push") == 0){
          scanf("%d", &arr[arr_count++]);
            pre_order[pre_order_count++] = arr[arr_count - 1];
        }
        else{
          inorder[inorder_count++] = arr[arr_count-1];
            arr_count--;
        }
  }
    traversal(0, 0, 0, N);
    for(int i = 0; i < N - 1; i++) printf("%d ", post_order[i]);
    printf("%d\n", post_order[N-1]);
    return 0;
}