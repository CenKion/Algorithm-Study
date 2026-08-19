#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

const int MAXN = 2 * 1e4 + 5;
const int MAXM = 1e5 + 5;

class UnionFind{
	int parent[MAXN],rank[MAXN];
	int cnt;
	public:
	
	UnionFind(int x){
		for(int i = 1;i <= x;i ++){
			parent[i] = i;
			rank[i] = 1;
		}
		cnt = x;
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

struct hate{
	int a,b,c;
}H[MAXM];

bool cmp(hate &a,hate &b){
	return a.c > b.c;
}

int n,m,enemy[MAXN];

int main(){
	cin >> n >> m;
	UnionFind un(n);
	for(int i = 1;i <= m;i ++){
		cin >> H[i].a >> H[i].b >> H[i].c;
	}
	sort(H + 1,H + 1 + m,cmp);
	for(int i = 1;i <= m;i ++){
		int px = un.find(H[i].a),py = un.find(H[i].b);
		if(px == py){
			cout << H[i].c;
			exit(0);
		}
		if(enemy[H[i].a] == 0) enemy[H[i].a] = H[i].b;
		else un.unite(enemy[H[i].a],H[i].b);
		
		if(enemy[H[i].b] == 0) enemy[H[i].b] = H[i].a;
		else un.unite(enemy[H[i].b],H[i].a);
	}
	cout << 0;
	return 0;
}
