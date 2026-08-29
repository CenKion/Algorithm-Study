#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int mod = 1000007;

int W[6] = {1 ,2 ,3 ,5 ,10 ,20};
int a[6];
int dp[1001];

int main(){
	for(int i = 0;i < 6;i ++) cin >> a[i];
	int sum = 0;
	for(int i = 0;i < 6;i ++) sum += W[i]*a[i];
	for(int i = 0;i <= a[0];i ++){
		dp[i * W[0]] = 1;
	}
	for(int i = 1;i < 6;i++){
		for(int j = sum;j >= 0;j --){
			for(int k = 1;k <= a[i] && j >= k*W[i];k ++){
				dp[j] += dp[j-k*W[i]];
			}
		}
	}
	int cnt = 0;
	for(int i = 1;i <= sum;i ++){
		if(dp[i] > 0) cnt ++;
	}
	cout << "Total="<<cnt;
	return 0;
}
