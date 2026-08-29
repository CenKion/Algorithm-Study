#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m,a[355],dp[45][45][45][45],card[5],crd;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(int i = 1;i <= m;i ++){
		cin >> crd;
		card[crd] ++;
	}
	dp[0][0][0][0] = a[1];
	for(int x1 = 0;x1 <= card[1];x1 ++){
		for(int x2 = 0;x2 <= card[2];x2 ++){
			for(int x3 = 0;x3 <= card[3];x3 ++){
				for(int x4 = 0;x4 <= card[4];x4 ++){
					int pos = x1 + 2*x2 + 3*x3 + 4*x4;
					if(x1 + x2 + x3 + x4 == 0) continue;
					int r1 = (x1 > 0) ? (dp[x1 - 1][x2][x3][x4]) : 0;
					int r2 = (x2 > 0) ? (dp[x1][x2 - 1][x3][x4]) : 0;
					int r3 = (x3 > 0) ? (dp[x1][x2][x3 - 1][x4]) : 0;
					int r4 = (x4 > 0) ? (dp[x1][x2][x3][x4 - 1]) : 0;
					dp[x1][x2][x3][x4] = a[pos + 1] + max(max(r1,r2),max(r3,r4));
				}
			}
		}
	}
	cout << dp[card[1]][card[2]][card[3]][card[4]];
	return 0;
}

