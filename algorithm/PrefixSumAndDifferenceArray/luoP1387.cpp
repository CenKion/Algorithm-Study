#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int sum[105][105],n,m,ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			cin >> sum[i][j];
			if(i == 1 && j == 1) continue;
			if(j == 1) sum[i][j] += sum[i - 1][j];
			else if(i == 1) sum[i][j] += sum[i][j - 1];
			else sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			int maxA = min(i,j);
			if(maxA <= ans) continue;
			for(int k = maxA;k > ans && k >= 1;k --){
				int S;
				if(i - k >= 1 && j - k >= 1)
					S = sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k];
				else if(i - k >= 1) S = sum[i][j] - sum[i - k][j];
				else if(j - k >= 1) S = sum[i][j] - sum[i][j - k];
				else S = sum[i][j];
				if(S == k * k){
					ans = k;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
