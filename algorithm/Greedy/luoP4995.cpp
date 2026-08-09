#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int n;
long long ans,stone[305],f[305],t[305],r[305];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> stone[i];
	}
	sort(stone + 1,stone + 1 + n);
	int i = 1,j = n,cnt = 0;
	ans += stone[n] * stone[n];
	while(cnt < n - 1){
		long long d = stone[j] - stone[i];
		ans += d * d;
		if((cnt & 1) == 0) j --;
		else i++;
		cnt ++;
	}
	cout << ans;
	return 0;
}
