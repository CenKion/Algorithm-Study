#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 2 * 1e5 + 5;

int head[MAXN],weight[MAXM],nxt[MAXM],to[MAXM],dis[MAXN],cnt,n,m,s,u,v,w;
bool vis[MAXN];

void add_edge(int u,int v,int w){
	cnt ++;
	weight[cnt] = w;
	nxt[cnt] = head[u];
	to[cnt] = v;
	head[u] = cnt;
}

struct node{
	int dis;
	int pos;
	
	bool operator <(const node &b) const{
		return b.dis < dis;
	}
};

priority_queue <node> Q;

void dijkstra(){
	dis[s] = 0;
	Q.push((node){0,s});
	while(!Q.empty()){
		node fro = Q.top();
		Q.pop();
		int x = fro.pos, d = fro.dis;
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = head[x];i != 0;i = nxt[i]){
			int y = to[i];
			if(dis[y] > dis[x] + weight[i]){
				dis[y] = dis[x] + weight[i];
				if(!vis[y]) Q.push((node){dis[y],y});
			}
		}
	}
}

int main(){
	cin >> n >> m >> s;
	for(int i = 1;i <= m;i ++){
		cin >> u >> v >> w;
		add_edge(u,v,w);
	}
	for(int i = 1;i <= n;i ++){
		dis[i] = 0x7fffffff;
	}
	dijkstra();
	cout << dis[1];
	for(int i = 2;i <= n;i ++){
		cout << ' ' << dis[i];
	}
	return 0;
}

