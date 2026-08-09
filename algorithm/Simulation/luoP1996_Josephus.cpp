#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,a[105];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 0;i < n;i ++){
		a[i] = i + 1;
	}
	int p = 0;
	while(n > 0){
		p = (p - 1 + m % n + n) % n;
		cout << a[p] <<' ';
		copy(a + p + 1,a + n,a + p);
		n--;
	}
	return 0;
}
