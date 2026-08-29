#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define mod 1000000007

using namespace std;

int n,m,dp[30005],v[25],p[25];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= m;i ++){
		cin >> v[i] >> p[i];
	}
	for(int i = 1;i <= m;i ++){
		for(int j = n;j >= v[i];j --){
			dp[j] = max(dp[j],dp[j - v[i]] + v[i] * p[i]);
		}
	}
	cout << dp[n];
	return 0;
}

