#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N, M, K;
struct edge{
    int v1, v2;
}edge[10000];
int check[10000];
int check_edge(){
    for(int i = 0; i < M; i++){
        if(!check[edge[i].v1] && !check[edge[i].v2]) return 0;
    }
    return 1;
}
int main(int argc, char *argv[]){
    int Nv = 0, num = 0, flag;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> edge[i].v1 >> edge[i].v2;
    }
    cin >> K;
    while(K--){
        cin >> Nv;
        flag = 1;
        memset(check, 0, sizeof(check));
        while(Nv--){
            cin >> num;
            if(num >= N) flag = 0;
            else{
                check[num] = 1;
            }
        }
        if(!flag) cout << "No" << endl;
        else{
            if(check_edge()) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}