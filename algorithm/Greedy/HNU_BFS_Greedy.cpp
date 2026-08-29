#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 2 * 1e3 + 5;
const int MAXM = 2 * 1e3 + 5;

long long arr[MAXN][MAXM],start[MAXN][MAXM],ans = -1;
bool vis[MAXN][MAXM];
int n,m,w;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct minhole{
	int x,y;
	long long dis;
}h1,h2;

bool inBoard(int x,int y){
	if(x < 1 || x > n || y < 1 || y > m) return 0;
	return 1;
}

void bfs(int x,int y,bool f){
	memset(vis,0,sizeof(vis));
	memset(start,0,sizeof(start));
	minhole tmp = {0,0,-1};
	queue<pair<int,int>> Q;
	Q.push((pair<int,int>){x,y});
	vis[x][y] = 1;
	while(!Q.empty()){
		pair<int,int> fro = Q.front();
		Q.pop();
		for(int i = 0;i < 4;i ++){
			int nx = fro.first + dx[i];
			int ny = fro.second + dy[i];
			if(inBoard(nx,ny) && !vis[nx][ny] && arr[nx][ny] >= 0){
				start[nx][ny] = start[fro.first][fro.second] + 1;
				Q.push((pair<int,int>){nx,ny});
				vis[nx][ny] = 1;
				if(arr[nx][ny] > 0 && (tmp.dis == -1 || tmp.dis > start[nx][ny] * w + arr[nx][ny])){
					tmp.x = nx;
					tmp.y = ny;
					tmp.dis = start[nx][ny] * w + arr[nx][ny];
				}
			}
		}
	}
	if(arr[x][y] > 0 && (tmp.dis == -1 || tmp.dis > arr[x][y])){
		tmp.x = x;
		tmp.y = y;
		tmp.dis = start[x][y] * w + arr[x][y];
	}
	if(f) h1 = tmp;
	else h2 = tmp;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> w;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			cin >> arr[i][j];
		}
	}
	bfs(1,1,1);
	if(start[n][m]) ans = start[n][m] * w;
	bfs(n,m,0);
	if(h1.dis == -1 || h2.dis == -1){
		cout << ans;
		exit(0);
	}
	long long tmpAns = h1.dis + h2.dis;
	if(h1.x == h2.x && h1.y == h2.y) tmpAns -= 2 * arr[h1.x][h1.y];
	if(ans == -1) ans = tmpAns;
	else ans = min(ans,tmpAns);
	cout << ans;
	return 0;
}

