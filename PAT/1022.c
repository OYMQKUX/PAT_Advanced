#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct book{
    char ID[8];
    int num;
    char title[81];
    char author[81];
    char key[55];
    char word[5][11];
    char pub[81];
    char year[5];
};
int cmp(const void *a, const void *b){
    struct book *c=(struct book *)a;
    struct book *d=(struct book *)b;
    return strcmp(c->ID,d->ID);
}
int main(int argc, char *argv[]){
    int N, i, j, k;
    int M;
    int temp;
    int count;
    char que[1000][100];
    struct book a[10001];
    scanf("%d",&N);
    getchar();
    for(i=0;i<N;i++){
        gets(a[i].ID);
        gets(a[i].title);
        gets(a[i].author);
        gets(a[i].key);
        gets(a[i].pub);
        gets(a[i].year);
        count=0;
        temp=0;
        for(j=0;j<strlen(a[i].key);j++){
            if(a[i].key[j]!=' ') a[i].word[count][temp++]=a[i].key[j];
            else {a[i].word[count][temp]=0;count++;temp=0;}
        }
        a[i].num=count;
    }
    qsort(a,N,sizeof(a[0]),cmp);
    /*for(i=0;i<N;i++){
        printf("%d\n",a[i].num);
        for(j=0;j<=a[i].num;j++)
            puts(a[i].word[j]);
    }*/
    scanf("%d",&M);
    getchar();
    for(i=0;i<M;i++){
        gets(que[i]);
    }
    for(i=0;i<M;i++){
        count=0;
        puts(que[i]);
        temp=que[i][0]-'0';
        if(temp==1){
            for(j=0;j<N;j++){
                if(strcmp(que[i]+3,a[j].title)==0){printf("%s\n",a[j].ID);count++;}
            }
        }
        else if(temp==2){
            for(j=0;j<N;j++){
                if(strcmp(que[i]+3,a[j].author)==0){printf("%s\n",a[j].ID);count++;}
            }
        }
        else if(temp==3){
            for(j=0;j<N;j++){
                for(k=0;k<=a[j].num;k++)
                    if(strcmp(que[i]+3,a[j].word[k])==0){printf("%s\n",a[j].ID);count++;break;}
            }
        }
        else if(temp==4){
            for(j=0;j<N;j++){
                if(strcmp(que[i]+3,a[j].pub)==0){printf("%s\n",a[j].ID);count++;}
            }
        }
        else {
            for(j=0;j<N;j++){
                if(strcmp(que[i]+3,a[j].year)==0){printf("%s\n",a[j].ID);count++;}
            }
        }
        if(!count)  printf("Not Found\n");
    }
    return 0;
}