#include <iostream>
#include <cstring>
typedef long long ll;

using namespace std;

int n,X,T,cnt;
bool isPrime[100005];
int Prime[100005];

void GetPrime(int n){
	memset(isPrime,1,sizeof(isPrime));
	isPrime[1] = 0;
	for(int i = 2;i <= n;i ++){
		if(isPrime[i]) Prime[++cnt] = i;
		for(int j = 1;j <= cnt && Prime[j] * i <= 100005;j ++){
			isPrime[Prime[j] * i] = 0;
			if(i % Prime[j] == 0) break;
		}
	}
}

int fastPow(int x,int p,int n){
	int res = 1;
	while(p > 0){
		if((p & 1) == 1) res = (1ll * res * x) % n;
		x = 1ll * x * x % n;
		p >>= 1;
	}
	return res;
}

int main(){
	GetPrime(100005);
	cin >> X >> T;
	if(X == 1){
		while(T --){
			cin >> n;
			if((n & 1) == 0){
				cout << 2;
				for(int i = n;i >= 1;i --){
					cout << ' ';
					if(i == n) cout << n;
					else if(((n - i) & 1) == 0) cout << n - i;
					else cout << i; 
				}
				cout << '\n';
			}
			else if(n == 1){
				cout << "2 1\n";
			}
			else{
				cout << "0\n";
			}
		}
	}
	else{
		while(T --){
			cin >> n;
			if(n == 1) cout << "2 1\n";
			else if(n == 2) cout << "2 1 2\n";
			else if(n == 4) cout << "2 1 3 2 4\n";
			else if(!isPrime[n]) cout << 0 << '\n';
			else{
				cout << "2 1";
				for(int i = 2;i <= n - 1;i ++){
					int t = fastPow(i - 1,n - 2,n);
					cout << ' ' << 1ll * i * t % n;
				}
				cout << ' ' << n << '\n';
			}
		}
	}
	return 0;
}
