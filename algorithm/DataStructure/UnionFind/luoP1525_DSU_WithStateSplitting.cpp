#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

const int MAXN = 2 * 1e4 + 5;
const int MAXM = 1e5 + 5;

class UnionFind{
	int parent[2 * MAXN],rank[2 * MAXN];
	public:
	
	UnionFind(int n){
		for(int i = 1;i <= 2 * n;i ++){
			parent[i] = i;
			rank[i] = 1;
		}
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
	}
	
};

struct hate{
	int a,b,c;
}H[MAXM];

bool cmp(hate &a,hate &b){
	return a.c > b.c;
}

int n,m;

int main(){
	cin >> n >> m;
	UnionFind un(n);
	for(int i = 1;i <= m;i ++){
		cin >> H[i].a >> H[i].b >> H[i].c;
	}
	sort(H + 1,H + 1 + m,cmp);
	for(int i = 1;i <= m;i ++){
		un.unite(H[i].a,H[i].b + n);
		un.unite(H[i].a + n,H[i].b);
		int pa = un.find(H[i].a),npa = un.find(H[i].a + n);
		int pb = un.find(H[i].b),npb = un.find(H[i].b + n);
		if(pa == npa || pb == npb){
			cout << H[i].c;
			exit(0);
		}
	}
	cout << 0;
	return 0;
}
