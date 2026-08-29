#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

int cnt,head[MAXN],weight[MAXM << 1],nxt[MAXM << 1],to[MAXM << 1],dist[MAXN],start = 1;
bool vis[MAXN];
vector <int> path[MAXN];

void add_edge(int u,int v,int w){
	cnt ++;
	weight[cnt] = w;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
	cnt ++;
	weight[cnt] = w;
	to[cnt] = u;
	nxt[cnt] = head[v];
	head[v] = cnt;
}

struct node{
	int dis;
	int y;
	
	bool operator < (const node& b) const{
		return b.dis < dis;
	}
};

priority_queue <node> Q;

bool cmp(vector <int> &p1,vector <int> &p2){
	int l1 = p1.size(),l2 = p2.size();
	for(int i = 0;i < min(l1,l2);i ++){
		if(p1[i] > p2[i]) return 0;
	}
	return 1;
}

void dijkstra(){
	dist[start] = 0;
	Q.push((node){0,start});
	path[start].push_back(start);
	while(!Q.empty()){
		node fro = Q.top();
		Q.pop();
		int x = fro.y,d = fro.dis;
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = head[x]; i;i = nxt[i]){
			if(dist[to[i]] > dist[x] + weight[i]){
				dist[to[i]] = dist[x] + weight[i];
				path[to[i]] = path[x];
				path[to[i]].push_back(to[i]);
			}
			else if(dist[to[i]] == dist[x] + weight[i]){
				vector <int> tmp = path[x];
				tmp.push_back(to[i]);
				if(cmp(tmp,path[to[i]])) path[to[i]] = tmp;
			}
			if(!vis[to[i]]) Q.push((node){dist[to[i]],to[i]});
		}
	}
}

int n,m,u,v,w;

int main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i ++){
		cin >> u >> v >> w;
		add_edge(u,v,w);
	}
	for(int i = 1;i <= n;i ++){
		dist[i] = 0x7fffffff;
	}
	dijkstra();
	if(!vis[n]) cout << -1;
	else{
		cout << path[n][0];
		for(int i = 1;i < path[n].size();i ++){
			cout << ' ' << path[n][i];
		}
	}
	return 0;
}

