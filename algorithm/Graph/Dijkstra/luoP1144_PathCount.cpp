#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define mod 100003

using namespace std;

const int MAXN = 1e6 + 5,MAXM = 2 * 1e6 + 5;
int n,m,path[MAXN],tmpu,tmpv,start = 1,dist[MAXN];
bool vis[MAXN];

struct edge{
	int u,v;
};

vector <edge> edges[MAXN];

struct point{
	int v,dis;
	
	bool operator < (const point &b)const{
		return dis > b.dis;
	}
};

void dijkstra(){
	dist[start] = 0;
	path[start] = 1;
	priority_queue <point> Q;
	Q.push((point){1,0});
	while(!Q.empty()){
		point fro = Q.top();
		Q.pop();
		if(vis[fro.v]) continue;
		vis[fro.v] = 1;
		for(int i = 0;i < edges[fro.v].size();i ++){
			if(dist[edges[fro.v][i].v] > dist[fro.v] + 1){
				path[edges[fro.v][i].v] = path[fro.v];
				dist[edges[fro.v][i].v] = dist[fro.v] + 1;
				Q.push((point){edges[fro.v][i].v,dist[edges[fro.v][i].v]});
			}
			else if(dist[edges[fro.v][i].v] == dist[fro.v] + 1){
				path[edges[fro.v][i].v] = (path[edges[fro.v][i].v] + path[fro.v])%mod;
			}
		}
	}
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= m;i ++){
		cin >> tmpu >> tmpv;
		edges[tmpu].push_back((edge){tmpu,tmpv});
		edges[tmpv].push_back((edge){tmpv,tmpu});
	}
	for(int i = 1;i <= n;i ++){
		dist[i] = 0x7fffffff;
	}
	dijkstra();
	for(int i = 1;i <= n;i ++){
		cout << path[i] << '\n';
	}
	return 0;
}

