#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct digit{
  int M;
  int num[10000];
}digit[50];
struct numb{
  int value;
  struct numb *next;
}head,*temp3,*temp4;
int N;
int M;
int N_C;
int N_T;
int main(int argc, char *argv[]){
  int i, j, k;
  int temp;
  int count;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    head.next=NULL;
    temp3=NULL;
    temp4=NULL;
    count=0;
    scanf("%d",&digit[i].M);
    for(j=0;j<digit[i].M;j++){
      scanf("%d",&temp);
      temp3=(struct numb*)malloc(sizeof(struct numb));
      temp3->value=temp;
      if(head.next==NULL){temp3->next=head.next;head.next=temp3;}
      else{
        temp4=&head;
        while(temp4->next&&temp4->next->value<temp){
          temp4=temp4->next;
        }
        if(temp4->next){
          if(temp4->next->value==temp) count++;
          else {temp3->next=temp4->next;temp4->next=temp3;}
        }
        else{
          if(temp4->value<temp) {temp3->next=NULL;temp4->next=temp3;}
          else if(temp4->value==temp) count++;
        }
      }
    }
    temp4=head.next;
    j=0;
    while(temp4){
      digit[i].num[j++]=temp4->value;
      temp4=temp4->next;
    }
    digit[i].M-=count;
  }
  /*for(i=0;i<N;i++){
    printf("\n%d %d\n",digit[i].M,N);
    for(j=0;j<digit[i].M;j++)
      printf("%d ",digit[i].num[j]);
  }*/
  scanf("%d",&M);
  int temp1, temp2;
  int head, tail;
  double ans;
  for(i=0;i<M;i++){
    scanf("%d%d",&temp1,&temp2);
    N_C=0;
    N_T=digit[temp1-1].M+digit[temp2-1].M;
    for(j=0;j<digit[temp1-1].M;j++){
      head=0;tail=digit[temp2-1].M-1;
      while(head<=tail){
        temp=digit[temp1-1].num[j];
        if(digit[temp2-1].num[(head+tail)/2]>digit[temp1-1].num[j]) tail=(head+tail)/2-1;
        else if(digit[temp2-1].num[(head+tail)/2]<digit[temp1-1].num[j]) head=(head+tail)/2+1;
        else {N_C++;break;}
      }
    }
    N_T-=N_C;
    ans=N_C*100.0/N_T;
    printf("%.1lf%%\n",ans);
  }
  
  return 0;
}