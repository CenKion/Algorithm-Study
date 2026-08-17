#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

struct point{
	double x,y,r;
}points[7];

int N;
double ax,ay,bx,by,ans,edge[7],dis[7][7],pi = acos(-1);
bool vis[7];

void dfs(int cnt,double size){
	if(cnt == N){
		if(size > ans) ans = size;
		return;
	}
	for(int i = 1;i <= N;i ++){
		if(!vis[i]){
			vis[i] = 1;
			points[i].r = edge[i];
			for(int j = 1;j <= N;j ++){
				if(i == j) continue;
				if(vis[j]){
					if(dis[i][j] <= points[j].r){
						points[i].r = 0;
						break;
					}
					else if(dis[i][j] - points[j].r < points[i].r)
						points[i].r = dis[i][j] - points[j].r;
				}
			}
			dfs(cnt + 1,size + pi * points[i].r * points[i].r);
			vis[i] = 0;
			points[i].r = 0;
		}
	}
}

int main(){
	cin >> N >> ax >> ay >> bx >> by;
	for(int i = 1;i <= N;i ++){
		cin >> points[i].x >> points[i].y;
		points[i].r = 0;
		edge[i] = min(min(fabs(points[i].x - ax),fabs(points[i].x - bx)),
					min(fabs(points[i].y - ay),fabs(points[i].y - by)));
	}
	for(int i = 1;i < N;i ++){
		for(int j = i + 1;j <= N;j ++){
			double dx = points[i].x - points[j].x;
			double dy = points[i].y - points[j].y;
			dis[i][j] = sqrt(dx * dx + dy * dy);
			dis[j][i] = dis[i][j];
		}
	}
	for(int i = 1;i <= N;i ++){
		vis[i] = 1;
		points[i].r = edge[i];
		dfs(1,pi * points[i].r * points[i].r);
		vis[i] = 0;
		points[i].r = 0;
	}
	cout << (int)(fabs((ax - bx) * (ay - by)) - ans + 0.5); 
	return 0;
}
