#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

class UnionFind{
	int parent[MAXN],rank[MAXN];
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

bool open[MAXN];
int n,m,x,number,button[MAXM][3];

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> open[i];
	}
	for(int i = 1;i <= m;i ++){
		cin >> x;
		for(int j = 1;j <= x;j ++){
			cin >> number;
			button[number][++ button[number][0]] = x;
		}
	}
	UnionFind un(n);
	for(int i = 1;i <= n;i ++){
		if(open[i]){
			un.unite(button[i][1],button[i][2]);
			un.unite(button[i][1] + n,button[i][2] + n);
		}
		else{
			un.unite(button[i][1] + n,button[i][2]);
			un.unite(button[i][1],button[i][2] + n);
		}
		int pa = un.find(button[i][1]),npa = un.find(button[i][1] + n);
		int pb = un.find(button[i][2]),npb = un.find(button[i][2] + n);
		if(pa == npa || pb == npb){
			cout << "NO";
			exit(0);
		}
	}
	cout << "YES";
	return 0;
}
