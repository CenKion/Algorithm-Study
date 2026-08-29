#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define mod 1000000007

using namespace std;

const int MAXN = 1005;
const int MAXM = 205;

int n,m,tk,cnt = 1;
long long dp[2][MAXM][MAXN],tail[2][MAXM][MAXN];
string A,B;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> tk;
	cin >> A >> B;
	A = '0' + A;
	B = '0' + B;
	for(int i = 1;i <= n;i ++){
		dp[1][1][i] = dp[1][1][i - 1];
		if(A[i] == B[1]){
			dp[1][1][i] ++;
			tail[1][1][i] = 1;
		}
	}
	for(int k = 1;k <= tk;k ++){
		for(int i = 1;i <= m;i ++){
			if(k == 1 && i == 1) continue;
			for(int j = 1;j <= n;j ++){
				dp[cnt][i][j] = dp[cnt][i][j - 1];
				if(A[j] == B[i]){
					tail[cnt][i][j] = (tail[cnt][i - 1][j - 1] + dp[1 - cnt][i - 1][j - 1]) % mod;
					dp[cnt][i][j] = (dp[cnt][i][j] + tail[cnt][i - 1][j - 1] + dp[1 - cnt][i - 1][j - 1]) % mod;
				}
				else tail[cnt][i][j] = 0;
			}
		}
		cnt = 1 - cnt;
	}
	cout << dp[1 - cnt][m][n];
	return 0;
}

