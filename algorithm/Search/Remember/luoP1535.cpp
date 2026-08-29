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
int rem[MAXN][MAXM][MAXT];
string s;

bool check(int x,int y){
	if(x < 1 || x > n || y < 1 || y > m) return 0;
	return 1;
}

int dfs(int x,int y,int time){
	if(rem[x][y][time] != -1) return rem[x][y][time];
	if(abs(x - r2) + abs(y - c2) > t - time){
		rem[x][y][time] = 0;
		return 0;
	}
	if(time > t){
		rem[x][y][time] = 0;
		return 0;
	}
	if(time == t){
		if(x == r2 && y == c2){
			rem[x][y][time] = 1;
			return 1;
		}
		else{
			rem[x][y][time] = 0;
			return 0;
		}
	}
	int ans = 0;
	for(int i = 0;i < 4;i ++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(check(nx,ny) && f[nx][ny]) ans += dfs(nx,ny,time + 1);
	}
	rem[x][y][time] = ans;
	return ans;
}

int main(){
	cin >> n >> m >> t;
	memset(rem,-1,sizeof(rem));
	for(int i = 1;i <= n;i ++){
		cin >> s;
		for(int j = 0;j < m;j ++){
			if(s[j] == '.') f[i][j + 1] = 1;
		}
	}
	cin >> r1 >> c1 >> r2 >> c2; 
	cout << dfs(r1,c1,0);
	return 0;
}
