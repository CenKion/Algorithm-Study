#include <iostream>
#include <stdio.h>

using namespace std;

int n,k,dp[205][10];

int main(){
	scanf("%d %d",&n,&k);
	dp[1][1] = 1;
	for(int i = 2;i <= n;i ++){
		for(int j = 1;j <= k && j <= i;j ++){
			dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
		}
	}
	cout << dp[n][k];
	return 0;
}
