#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int n,m;

int dp[105];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 2;i <= n;i ++){
		dp[i] = (dp[i - 1] + m) % i;
	}
	cout << dp[n] + 1;
	return 0;
}
