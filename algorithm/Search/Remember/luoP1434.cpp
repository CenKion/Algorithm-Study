#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int r,c,ans;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int arr[105][105],dp[105][105];
string s;

bool check(int x,int y){
	if(x < 1 || x > r || y < 1 || y > c) return 0;
	return 1;
}

void dfs(int x,int y){
	if(dp[x][y]) return;
	int result = 0;
	for(int i = 0;i < 4;i ++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(check(nx,ny) && arr[nx][ny] < arr[x][y]){
			dfs(nx,ny);
			result = max(result,dp[nx][ny]);
		}
	}
	dp[x][y] = result + 1;
	if(dp[x][y] > ans) ans = dp[x][y];
}

int main(){
	cin >> r >> c;
	for(int i = 1;i <= r ;i ++){
		for(int j = 1;j <= c;j ++){
			cin >> arr[i][j];
		}
	}
	for(int i = 1;i <= r;i ++){
		for(int j = 1;j <= c;j ++){
			if(!dp[i][j]) dfs(i,j);
		}
	}
	cout << ans;
	return 0;
}
