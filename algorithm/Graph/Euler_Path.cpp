#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
const int MaxN = 100005;
int cnt[2], ind[MaxN], od[MaxN], vis[MaxN];
vector <int> edges[MaxN];
stack <int> st;

void dfs(int now){
	for(int i = vis[now];i < edges[now].size();i = vis[now]){
		vis[now] = i + 1;
		dfs(edges[now][i]);
	}
	st.push(now);
}

int main(){
	int n, m, u, v,S = 1;
	cin >> n >>m;
	for(int i = 0;i < m;i ++){
		cin >> u >>v;
		edges[u].push_back(v);
		ind[v] ++;
		od[u] ++;
	}
	for(int i = 1;i <= n;i ++) sort(edges[i].begin(),edges[i].end());
	bool f = 1;
	for(int i = 1;i <= n;i ++){
		if(ind[i] == od[i]) continue;
		f = 0;
		if(ind[i] == od[i] + 1) cnt[0]++;
		else if(od[i] == ind[i] + 1){
			cnt[1] ++;
			S = i;
		}
	}
	if(!f && !(cnt[0] == 1 && cnt[1] == 1)) cout <<"No";
	else{
		dfs(S);
		while(!st.empty()){
			cout << st.top() <<' ';
			st.pop();
		}
	}
	return 0;
}
