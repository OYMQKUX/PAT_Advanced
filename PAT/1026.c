#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <set>
using namespace std;

const int N = 10004;
const int M = 102;
const int close_ = 3600 * 21;

struct node {
    int time;
    int id;
    int type;
};  // type = 0, table free, 1 person come


bool operator<(const node &a,const node &b) {
    if (a.time > b.time) {
        return true;
    }
    if (a.time < b.time) {
        return false;
    }
    return (a.time > b.time) || ((a.time == b.time) && (a.type < b.type));
}

int num[M];
int play[N];
bool isvipperson[N];
bool isviptable[M];
set<int> ordtable;
set<int> viptable;

set<pair<int,int> > vipperson;
set<pair<int,int> > ordperson;

priority_queue<node> affair;

int gettable() {
    int r;
    if (ordtable.empty()) {
        r = *viptable.begin();
        viptable.erase(viptable.begin());
        return r;
    }
    if (viptable.empty()) {
        r = *ordtable.begin();
        ordtable.erase(ordtable.begin());
        return r;
    }
    if (*ordtable.begin() < *viptable.begin()) {
        r = *ordtable.begin();
        ordtable.erase(ordtable.begin());
    }
    else {
        r = *viptable.begin();
        viptable.erase(viptable.begin());
    }
    return r;
}

pair<int,int> getperson() {
    pair<int,int> r;
    if (ordperson.empty()) {
        r = *vipperson.begin();
        vipperson.erase(vipperson.begin());
        return r;
    }
    if (vipperson.empty()) {
        r = *ordperson.begin();
        ordperson.erase(ordperson.begin());
        return r;
    }
    if (ordperson.begin()->first < vipperson.begin()->first) {
        r = *ordperson.begin();
        ordperson.erase(ordperson.begin());
    }
    else {
        r = *vipperson.begin();
        vipperson.erase(vipperson.begin());
    }
    return r;
}

void freetable(int x) {
    if (isviptable[x]) {
        viptable.insert(x);
    }
    else {
        ordtable.insert(x);
    }
}

void print(int x,int y) {
    printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",x / 3600, x % 3600 / 60, x % 60, y / 3600, y % 3600 / 60, y % 60, (y - x + 30) / 60);
}

int main() {
    int n;
    node temp;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        int x;
        int hh,mm,ss;
        scanf("%d:%d:%d %d%d",&hh,&mm,&ss,&play[i],&x);
        isvipperson[i] = x;
        temp.id = i;
        temp.time = hh * 3600 + mm * 60 + ss;
        temp.type = 1;
        play[i] = min(play[i], 120);
        play[i] *= 60;
        affair.push(temp);
    }
    int a;
    for (scanf("%d%d",&n,&a);a;--a) {
        int x;
        scanf("%d",&x);
        isviptable[--x] = true;
        viptable.insert(x);
    }
    for (int i  = 0; i < n; ++i) {
        if (!isviptable[i]) {
            ordtable.insert(i);
        }
    }
    while (!affair.empty()) {
        temp = affair.top();
        affair.pop();
        int now = temp.time;
        if (now >= close_) {
            break;
        }
        if (temp.type == 0) {
            freetable(temp.id);
            while ((!affair.empty()) && (affair.top().type == 0) && (affair.top().time == now)) {
                freetable(affair.top().id);
                affair.pop();
                
            }
            while ((!viptable.empty()) && (!vipperson.empty())) {
                temp.time = now + vipperson.begin()->second;
                temp.type = 0;
                ++num[temp.id = *viptable.begin()];
                print(vipperson.begin()->first, now);
                affair.push(temp);
                viptable.erase(viptable.begin());
                vipperson.erase(vipperson.begin());
            }
            while (((!ordperson.empty()) || (!vipperson.empty())) && ((!ordtable.empty()) || (!viptable.empty()))) {
                pair<int,int> g = getperson();
                temp.time = now + g.second;
                temp.type = 0;
                ++num[temp.id = gettable()];
                print(g.first,now);
                affair.push(temp);
            }
            
            
        }
        else if (isvipperson[temp.id]) {
            if (!viptable.empty()) {
                
                temp.time = now + play[temp.id];
                print(now, now);
                temp.type = 0;
                ++num[temp.id = *viptable.begin()];
                affair.push(temp);
                viptable.erase(viptable.begin());
                
            }
            else if (!ordtable.empty()) {
                temp.time = now + play[temp.id];
                print(now, now);
                temp.type = 0;
                ++num[temp.id = *ordtable.begin()];
                affair.push(temp);
                ordtable.erase(ordtable.begin());
            }
            else  {
                vipperson.insert(make_pair(now, play[temp.id]));
                
            }
        }
        else if ((!viptable.empty()) || (!ordtable.empty())) {
            temp.time = now + play[temp.id];
            print(now, now);
            temp.type = 0;
            ++num[temp.id = gettable()];
            affair.push(temp);
        }
        else {
            ordperson.insert(make_pair(now, play[temp.id]));
            
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i) {
            putchar(' ');
        }
        printf("%d",num[i]);
    }
    puts("");
    return 0;
}