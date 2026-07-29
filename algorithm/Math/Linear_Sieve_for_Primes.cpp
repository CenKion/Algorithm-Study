#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool isPrime[100000010];
int Prime[6000010];
int cnt = 0;

void GetPrime(int n){
	isPrime[1] = 0;
	memset(isPrime,1,sizeof(isPrime));
	for(int i = 2;i <= n;i ++){
		if(isPrime[i]){
			Prime[++cnt] = i;
		}
		
		for(int j = 1;j <= cnt && Prime[j] * i <= n;j ++){
			isPrime[Prime[j] * i] = 0;
			
			if(i % Prime[j] == 0) break;
		}
	}
}

int main(){
	int n;
	cin >> n;		//n>=17时,分配内存可用安全上界:save = (int)(1.25506*n/log(n)) + 100
					//vector <int> primes;primes.reserve(save);
	GetPrime(n);
	int q,k;
	cin >> q;
	for(int i = 0;i < q;i ++){
		cin >> k;
		cout << Prime[k] <<'\n';
	}
	return 0;
}
