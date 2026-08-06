#include <iostream>
#include <stdio.h>
#define mod 100003
using namespace std;

int dp[100005],N,K;

int main(){
	dp[0] = 1;
	dp[1] = 1;
	scanf("%d %d",&N,&K);
	for(int i = 2;i <= N;i ++){
		for(int j = i - 1;j >= 0 && j >= i - K;j --){
			dp[i] = (dp[i] + dp[j]) % mod;
		}
	}
	cout << dp[N];
	return 0;
}
