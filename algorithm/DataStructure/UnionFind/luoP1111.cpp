#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

const int MAXN = 1 * 1e3 + 5;
const int MAXM = 1 * 1e5 + 5;

class UnionFind{
	int parent[MAXN],rank[MAXN];
	int cnt;
	public:
	UnionFind(int n){
		for(int i = 1;i <= n;i ++){
			parent[i] = i;
			rank[i] = 1;
		}
		cnt = n;
	}
	
	int find(int x){
		return (parent[x] == x) ? x : (parent[x] = find(parent[x]));
	}
	
	void unite(int a,int b){
		int pa = find(a),pb = find(b);
		if(pa == pb) return;
		if(rank[pa] < rank[pb]) swap(pa,pb);
		parent[pb] = pa;
		if(rank[pa] == rank[pb]) rank[pa] ++;
		cnt --;
	}
	
	int count(){
		return cnt;
	}
};

struct path{
	int x,y,t;
}paths[MAXM];

bool cmp(path &a,path &b){
	return a.t < b.t;
}

int n,m;

int main(){
	cin >> n >> m;
	UnionFind un(n);
	for(int i = 1;i <= m;i ++){
		cin >> paths[i].x >> paths[i].y >> paths[i].t;
	}
	sort(paths + 1,paths + 1 + m,cmp);
	for(int i = 1;i <= m;i ++){
		un.unite(paths[i].x,paths[i].y);
		if(un.count() == 1){
			cout << paths[i].t;
			exit(0);
		}
	}
	cout << -1;
	return 0;
}
