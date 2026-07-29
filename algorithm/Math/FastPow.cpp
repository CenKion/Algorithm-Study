#include <iostream>

using namespace std;

long long fastPow(long long a,long long b,long long p){
    long long res = 1;
    while(b!=0){
        if((b & 1) == 1) res = res * a % p;
        a = a * a % p;
        b = b >> 1;
    }
    return res;
}

int main(){
    long long a , b ,p;
    cin >> a >> b >> p;
    cout << a << '^'<<b<<" mod " <<p <<'='<<fastPow(a,b,p);
    return 0;
}
