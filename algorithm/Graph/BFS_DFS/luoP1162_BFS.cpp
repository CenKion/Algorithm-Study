#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

int n,M[35][35];
bool vis[35][35];
int dx[4] = {1 ,0 , -1, 0};
int dy[4] = {0 ,-1 ,0 , 1};

bool check(int x,int y){
	if(x < 1 || x > n || y < 1 || y > n) return 0;
	return 1;
}

void bfs(int x,int y){
	pair <int,int> p = {x,y};
	queue <pair<int,int>> Q;
	Q.push(p);
	while(!Q.empty()){
		int nx,ny;
		pair <int,int> fro = Q.front();
		Q.pop();
		for(int i = 0;i < 4;i ++){
			nx = fro.first + dx[i];
			ny = fro.second + dy[i];
			if(check(nx,ny) && !vis[nx][ny] && M[nx][ny] != 1){
				pair<int,int> np = {nx,ny};
				Q.push(np);
				vis[nx][ny] = 1;
			}
		}
	}
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			cin >> M[i][j];
		}
	}
	for(int i = 1;i <= n;i ++){
		if(i == 1 || i == n){
			for(int j = 1;j <= n;j ++){
				if(!vis[i][j] && M[i][j] != 1){
					bfs(i,j);
				}
			}
		}
		else{
			if(!vis[i][1] && M[i][1] != 1)bfs(i,1);
			if(!vis[i][n] && M[i][n] != 1)bfs(i,n);
		}
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			if(vis[i][j] || M[i][j] == 1) cout << M[i][j];
			else cout << 2;
			if(j == n) cout << '\n';
			else cout << ' ';
		}
	}
	return 0;
}
