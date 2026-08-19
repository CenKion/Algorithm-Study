#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

const int MAXN = 2 * 1e5 + 5;
bool vis[MAXN];
int n,ans = MAXN,edge[MAXN],ind[MAXN];
vector <int> start;

void topo(){
	vector <int> head;
	for(int i = 1;i <= n;i ++){
		if(ind[i] == 0){
			head.push_back(i);
			vis[i] = 1;
		}
	}
	while(!head.empty()){
		int fro = head.back();
		head.pop_back();
		ind[edge[fro]] --;
		if(ind[edge[fro]] == 0){
			head.push_back(edge[fro]);
			vis[edge[fro]] = 1;
		}
	}
}

void dfs(){
	for(int i = 1;i <= n;i ++){
		if(!vis[i]) start.push_back(i);
	}
	while(!start.empty()){
		int fro = start.back();
		start.pop_back();
		if(vis[fro]) continue;
		int l = 1;
		vis[fro] = 1;
		while(!vis[edge[fro]]){
			l ++;
			fro = edge[fro];
			vis[fro] = 1;
		}
		if(ans > l) ans = l;
	}
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> edge[i];
		ind[edge[i]] ++;
	}
	topo();
	dfs();
	cout << ans;
	return 0;
}
