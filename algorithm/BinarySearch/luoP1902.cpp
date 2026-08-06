#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m,l,r,arr[1005][1005];
bool vis[1005][1005];
int dx[4] = {1 ,-1 ,0 ,0};
int dy[4] = {0 ,0 ,1 ,-1};

bool inBoard(int x,int y){
	return (x >= 1 && x <= n && y >= 1 && y <= m);
}

bool bfs(int x,int y,int limit){
	queue <pair<int,int>> Q;
	Q.push((pair<int,int>){x,y});
	int nx,ny;
	while(!Q.empty()){
		pair <int,int> tmp = Q.front();
		for(int i = 0;i < 4;i ++){
			nx = tmp.first + dx[i];
			ny = tmp.second + dy[i];
			if(inBoard(nx,ny) && !vis[nx][ny] && nx == n) return 1;
			if(inBoard(nx,ny) && !vis[nx][ny]){
				if(arr[nx][ny] <= limit)Q.push((pair<int,int>){nx,ny});
				vis[nx][ny] = 1;
			}
		}
		Q.pop();
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			cin >> arr[i][j];
			if(arr[i][j] > r) r = arr[i][j];
		}
	}
	while(l <= r){
		int mid = l + (r - l) / 2;
		memset(vis,0,sizeof(vis));
		if(bfs(1,1,mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << r + 1;
	return 0;
}
