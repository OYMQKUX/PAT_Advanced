#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char owner[1000];
char Eva[1000];
int Eva_hash[70];
int owner_hash[70];
char Eva_color[70];
int count;
int miss;
int hash(char inp){
  if(inp >= '0' && inp <= '9') return inp - '0';
    if(inp >= 'A' && inp <= 'Z') return inp - 'A' + 10;
    return inp - 'a' + 36;
}
int main(){
    scanf("%s%s", owner, Eva);
    for(int i = 0; i < strlen(Eva); i++){
        if(!Eva_hash[hash(Eva[i])]){
          Eva_color[count++] = Eva[i];
        }
        Eva_hash[hash(Eva[i])]++;
    }
    for(int i = 0; i < strlen(owner); i++){
      owner_hash[hash(owner[i])]++;
    }
    for(int i = 0; i < count; i++){
      if(Eva_hash[hash(Eva_color[i])] > owner_hash[hash(Eva_color[i])])
            miss += Eva_hash[hash(Eva_color[i])] - owner_hash[hash(Eva_color[i])];
    }
    if(miss) printf("No %d\n", miss);
    else printf("Yes %ld\n", strlen(owner) - strlen(Eva));
    return 0;
}