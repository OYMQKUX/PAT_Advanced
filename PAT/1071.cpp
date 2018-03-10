#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cstdio>
#include <stdexcept>
#include <map>
using namespace std;
map<string, int> m;
int main(int argc, char *argv[]){
  string a, b;
    int max = -1;
    getline(cin,a);
    for(auto i: a){
        if(isalnum(i)){
          b += tolower(i);
        }
        else{
          if(b.length()) m[b]++;
            b.clear();
        }
    }
    if(b.length()) m[b]++;
    for(auto i = m.begin(); i != m.end(); i++){
        if(i->second > max){
          max = i->second;
            b = i->first;
        }
    }
    cout<<b<<" "<<max<<endl;
    return 0;
}