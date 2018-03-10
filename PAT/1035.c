#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct team{
    char account[11];
    char password[11];
    int flag;
};
struct team team[1000], temp[1000];
int N;
int cmp(const void *a, const void *b){
    struct team *c, *d;
    c=(struct team*)a;
    d=(struct team*)b;
    return d->flag-c->flag;
}
int main(int argc, char *argv[]){
    //char *temp;
    int count=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%s%s",team[i].account,team[i].password);
        strcpy(temp[i].account,team[i].account);
        strcpy(temp[i].password,team[i].password);
        if(strchr(team[i].password,'1')||strchr(team[i].password,'0')||strchr(team[i].password,'l')||strchr(team[i].password,'O')){
            team[i].flag=1;
            temp[i].flag=1;
        }
    }
    qsort(temp,N,sizeof(team[0]),cmp);
    if(!temp[0].flag){
        if(N>1) printf("There are %d accounts and no account is modified\n", N);
        else printf("There is 1 account and no account is modified\n");
        return 0;
    }
    for(int i=0;i<N;i++){
        if(team[i].flag){
            if(strchr(team[i].password,'1')){
                for(int j=0;j<strlen(team[i].password);j++){
                    if(team[i].password[j]=='1') team[i].password[j]='@';
                }
            }
            if(strchr(team[i].password,'l')){
                for(int j=0;j<strlen(team[i].password);j++){
                    if(team[i].password[j]=='l') team[i].password[j]='L';
                }
            }
            if(strchr(team[i].password,'0')){
                for(int j=0;j<strlen(team[i].password);j++){
                    if(team[i].password[j]=='0') team[i].password[j]='%';
                }
            }
            if(strchr(team[i].password,'O')){
                for(int j=0;j<strlen(team[i].password);j++){
                    if(team[i].password[j]=='O') team[i].password[j]='o';
                }
            }
            count++;
        }
    }
    printf("%d\n",count);
    for(int i=0;i<N;i++){
        if(team[i].flag) printf("%s %s\n",team[i].account,team[i].password);
    }
    return 0;
}