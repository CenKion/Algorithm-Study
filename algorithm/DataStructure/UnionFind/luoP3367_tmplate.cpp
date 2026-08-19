#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

const int MAXN = 2 * 1e5 + 5;

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

int n,m,z,x,y;

int main(){
	cin >> n >> m;
	UnionFind un(n);
	for(int i = 1;i <= m;i ++){
		cin >> z >> x >> y;
		if(z == 1) un.unite(x,y);
		else{
			int px = un.find(x),py = un.find(y);
			if(px == py) cout << "Y\n";
			else cout << "N\n";
		}
	}
	return 0;
}
