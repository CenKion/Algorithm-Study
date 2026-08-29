#include <bits/stdc++.h>
using namespace std;

int ai[31];
int dp[31][300000];

int main() {
	int n,x,sum=0,ans=0;
	cin >> n >> x;
	for(int i = 1;i <= n; i++){
		cin >> ai[i];
		sum += ai[i];
	}
	sum -= x;
	for(int i=1;i <= n;i++){
		for(int j = 0;j <= sum; j++){
			if(j>=ai[i]){	
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-ai[i]]+ai[i]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
			if(dp[i][j]>ans){
				ans=dp[i][j];
			}
		}
	}
	cout << x + sum - ans;
	
    return 0;
}
