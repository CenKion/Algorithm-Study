#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 105,MAXM = 105,MAXT = 16;
int n,m,t,r1,c1,r2,c2;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool f[MAXN][MAXM];
int dp[MAXN][MAXM][MAXT];
string s;

bool check(int x,int y){
	if(x < 1 || x > n || y < 1 || y > m) return 0;
	return 1;
}

int main(){
	cin >> n >> m >> t;
	for(int i = 1;i <= n;i ++){
		cin >> s;
		for(int j = 0;j < m;j ++){
			if(s[j] == '*') f[i][j + 1] = 1;
		}
	}
	cin >> r1 >> c1 >> r2 >> c2;
	dp[r1][c1][0] = 1;
	for(int nt = 1;nt <= t;nt ++){
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= m;j ++){
				for(int k = 0;k < 4;k ++){
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(!f[nx][ny]) dp[i][j][nt] += dp[nx][ny][nt - 1];
				}
			}
		}
	}
	cout << dp[r2][c2][t];
	return 0;
}
