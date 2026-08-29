#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define mod 1000000007

using namespace std;

const int MAXN = 105,MAXM = 205,MAXT = 205;

int n,M,T,m[MAXN],t[MAXN],dp[MAXM][MAXT];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> M >> T;
	for(int i = 1;i <= n;i ++){
		cin >> m[i] >> t[i];
	}
	for(int i = 1;i <= n;i ++){
		for(int j = M;j >= m[i];j --){
			for(int k = T;k >= t[i];k --){
				dp[j][k] = max(dp[j][k],dp[j - m[i]][k - t[i]] + 1);
			}
		}
	}
	cout << dp[M][T];
	return 0;
}

