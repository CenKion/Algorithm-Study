#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 1 * 1e3 + 5;

class UnionFind{
	int parent[MAXN],rank[MAXN];
	int cnt;
	public:
	UnionFind(int n){
		for(int i = 1;i <= n;i ++){
			parent[i] = i;
			rank[MAXN] = 1;
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

int n,h,r,T;
double x[MAXN],y[MAXN],z[MAXN];

int main(){
	cin >> T;
	while(T --){
		cin >> n >> h >> r;
		UnionFind un(n + 2);
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		for(int i = 2;i <= n + 1;i ++){
			cin >> x[i] >> y[i] >> z[i];
			if(z[i] + r >= h) un.unite(1,i);
			if(r >= z[i]) un.unite(i,n + 2);
			for(int j = 2;j < i;j ++){
				double dx = x[i] - x[j];
				double dy = y[i] - y[j];
				double dz = z[i] - z[j];
				double dis = sqrt(dx * dx + dy * dy + dz * dz);
				if(dis <= 2 * r) un.unite(j,i);
			}
		}
		if(un.find(n + 2) == un.find(1)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
