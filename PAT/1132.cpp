#include <iostream>
#include <cmath>
int N;
int num(int Z){
    int ans = 0;
    while(Z){
        ans++;
        Z /= 10;
    }
    return ans / 2;
}
int main(int argc, char *argv[]){
    int Z = 0;
    int a = 0, b = 0;
    long long product = 0;
    std::cin >> N;
    while(N--){
        std::cin >> Z;
        b = Z % (int)pow(10, num(Z));
        a = (Z - b) / (int)pow(10, num(Z));
        product = a * b;
        if(product == 0) std::cout << "No" << std::endl;
        else if(Z % product == 0) std::cout << "Yes" << std::endl;
        else std::cout << "No" << std::endl;
    }
    return 0;
}