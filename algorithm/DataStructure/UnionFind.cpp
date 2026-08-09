#include <iostream>
#include <vector>
using namespace std;

//judge components

class UnionFind{
	vector <int> parent,rank;
	int cnt;
	public:
	UnionFind(int n):parent(n+1),rank(n+1,0),cnt(n){
		for(int i=1;i<=n;i++){
			parent[i]=i;
		}
	}
	
	int find(int x){
		return parent[x]==x?x:parent[x]=find(parent[x]);
	}
	
	void unite(int a,int b){
		int ra=find(a),rb=find(b);
		if(ra==rb) return;
		if(rank[ra]<rank[rb]) swap(ra,rb);
		parent[rb]=ra;
		if(rank[ra]==rank[rb]){
			rank[ra]++;
		}
		cnt--;
	}
	
	int count(){
		return cnt;
	}
};

int main(){
	int n,m,u,v;
	while(cin>>n>>m && (n||m)){
		UnionFind uf(n);
		for(int i=0;i<m;i++){
			cin>>u>>v;
			uf.unite(u,v);
		}
		if(uf.count()==1){
			cout<<"Yes"<<'\n';
		}
		else{
			cout<<"No"<<'\n';
		}
	}
}
