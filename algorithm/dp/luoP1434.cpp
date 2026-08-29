#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int r,c,ans;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int arr[105][105],dp[105][105];
vector <pair<int,int>> points;
string s;

bool cmp(pair<int,int> &a,pair<int,int> &b){
	return arr[a.first][a.second] > arr[b.first][b.second];
}

bool check(int x,int y){
	if(x < 1 || x > r || y < 1 || y > c) return 0;
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> r >> c;
	for(int i = 1;i <= r ;i ++){
		for(int j = 1;j <= c;j ++){
			cin >> arr[i][j];
			points.push_back((pair<int,int>){i,j});
		}
	}
	sort(points.begin(),points.end(),cmp);
	for(int i = 0;i < r * c;i ++){
		int j = points[i].first;
		int k = points[i].second;
		int tmp = 0;
		for(int l = 0;l < 4;l ++){
			int nx = j + dx[l];
			int ny = k + dy[l];
			if(check(nx,ny) && arr[j][k] < arr[nx][ny]) tmp = max(tmp,dp[nx][ny]);
		}
		dp[j][k] = tmp + 1;
		if(dp[j][k] > ans){
			ans = dp[j][k];
		}
	}
	cout << ans;
	return 0;
}
