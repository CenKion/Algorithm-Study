#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define mod 1000000007

using namespace std;

int T,M,dp[1005],t[105],val[105];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T >> M;
	for(int i = 1;i <= M;i ++){
		cin >> t[i] >> val[i];
	}
	for(int i = 1;i <= M;i ++){
		for(int j = T;j >= t[i];j --){
			dp[j] = max(dp[j],dp[j - t[i]] + val[i]);
		}
	}
	cout << dp[T];
	return 0;
}
