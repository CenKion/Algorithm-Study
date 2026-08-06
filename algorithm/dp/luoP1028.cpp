#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long dp[1005];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		dp[i] = dp[i - 1] + dp[i >> 1] + 1;
	}
	printf("%d",dp[n] - dp[n - 1]);
	return 0;
}
