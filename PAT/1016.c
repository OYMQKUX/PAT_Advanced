#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct phone{
    char name[50];
    int month;
    int day;
    int hour;
    int min;
    char states[15];
};
int cmp1(const void *a, const void *b){
    struct phone *c, *d;
    c=(struct phone*) a;
    d=(struct phone*) b;
    return strcmp(c->name, d->name);
}
int cmp2(const void *a, const void *b){
    struct phone *c, *d;
    c=(struct phone*) a;
    d=(struct phone*) b;
    if(c->day!=d->day) return c->day-d->day;
    else if(c->hour!=d->hour) return c->hour-d->hour;
    else if(c->min!=d->min) return c->min-d->min;
    else return strcmp(d->states, c->states);
}
int main(int argc, char *argv[]){
    int price[25];
    int i, j, k;
    int N;
    int head=0;
    int flag=0,count=0;
    double temp_money=0;
    double money=0;
    int temp_day=0, temp_hour=0, temp_min=0;
    for(i=0;i<24;i++) {scanf("%d",&price[i]);money+=price[i];}
    price[24]=money;
    money=0;
    scanf("%d",&N);
    struct phone phone[N];
    memset(phone,0,sizeof(phone));
    for(i=0;i<N;i++){
        scanf("%s%d:%d:%d:%d",phone[i].name, &phone[i].month, &phone[i].day, &phone[i].hour, &phone[i].min);
        getchar();
        scanf("%s",phone[i].states);
    }
    qsort(phone, N, sizeof(phone[0]),cmp1);
    for(i=1;i<N;i++){
        if(strcmp(phone[i].name,phone[i-1].name)==0) continue;
        else {
            qsort(phone+head,i-head,sizeof(phone[0]),cmp2);
            flag=0;
            money=0;
            count=0;
            for(j=head;j<i;j++){
                temp_money=0;
                if(strcmp(phone[j].states,"on-line")==0){
                    temp_day=phone[j].day;
                    temp_hour=phone[j].hour;
                    temp_min=phone[j].min;
                    flag=1;
                }
                else if(flag&&strcmp(phone[j].states,"off-line")==0){
                    if(!count){printf("%s %02d\n",phone[head].name, phone[head].month); count++;}
                    printf("%02d:%02d:%02d ",temp_day,temp_hour,temp_min);
                    printf("%02d:%02d:%02d ",phone[j].day,phone[j].hour,phone[j].min);
                    printf("%d ",-(temp_day*60*24+temp_hour*60+temp_min-phone[j].day*60*24-phone[j].hour*60-phone[j].min));
                    flag=0;
                    if(phone[j].hour==temp_hour&&phone[j].day==temp_day)
                        temp_money=(phone[j].min-temp_min)*price[temp_hour];
                    else if(phone[j].day==temp_day){
                        temp_money+=(60-temp_min)*price[temp_hour];
                        temp_money+=phone[j].min*price[phone[j].hour];
                        for(k=temp_hour+1;k<=phone[j].hour-1;k++) temp_money+=price[k]*60;
                    }
                    else{
                        temp_money+=(60-temp_min)*price[temp_hour];
                        temp_money+=phone[j].min*price[phone[j].hour];
                        for(k=temp_hour+1;k<24;k++) temp_money+=price[k]*60;
                        for(k=0;k<phone[j].hour;k++) temp_money+=price[k]*60;
                        for(k=temp_day+1;k<phone[j].day;k++) temp_money+=price[24]*60;
                    }
                    printf("$%.2f\n",temp_money/100.0);
                }
                money+=temp_money;
            }
            if(money)printf("Total amount: $%.2f\n",money/100.0);
            head=i;
        }
    }
    qsort(phone+head,N-head,sizeof(phone[0]),cmp2);
    flag=0;
    money=0;
    count=0;
    for(j=head;j<N;j++){
        temp_money=0;
        if(strcmp(phone[j].states,"on-line")==0){
            temp_day=phone[j].day;
            temp_hour=phone[j].hour;
            temp_min=phone[j].min;
            flag=1;
        }
        else if(flag&&strcmp(phone[j].states,"off-line")==0){
            if(!count){printf("%s %02d\n",phone[head].name, phone[head].month);count++;}
            printf("%02d:%02d:%02d ",temp_day,temp_hour,temp_min);
            printf("%02d:%02d:%02d ",phone[j].day,phone[j].hour,phone[j].min);
            printf("%d ",-(temp_day*60*24+temp_hour*60+temp_min-phone[j].day*60*24-phone[j].hour*60-phone[j].min));
            flag=0;
            if(phone[j].hour==temp_hour&&phone[j].day==temp_day)
                temp_money=(phone[j].min-temp_min)*price[temp_hour];
            else if(phone[j].day==temp_day){
                temp_money+=(60-temp_min)*price[temp_hour];
                temp_money+=phone[j].min*price[phone[j].hour];
                for(k=temp_hour+1;k<=phone[j].hour-1;k++) temp_money+=price[k]*60;
            }
            else{
                temp_money+=(60-temp_min)*price[temp_hour];
                temp_money+=phone[j].min*price[phone[j].hour];
                for(k=temp_hour+1;k<24;k++) temp_money+=price[k]*60;
                for(k=0;k<phone[j].hour;k++) temp_money+=price[k]*60;
                for(k=temp_day+1;k<phone[j].day;k++) temp_money+=price[24]*60;
            }
            printf("$%.2f\n",temp_money/100.0);
        }
        money+=temp_money;
    }
    if(money) printf("Total amount: $%.2f\n",money/100.0);
    //for(i=0;i<N;i++) printf("%s %02d:%02d:%02d:%02d %s\n",phone[i].name, phone[i].month,phone[i].day,phone[i].hour,phone[i].min,phone[i].states);
    return 0;
}