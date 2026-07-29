#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1000;
const int M = 2000;

int head[N] , to[M] ,w[M] ,nxt[M] ,tot;

void init(){
	tot = 0;
	memset(head, -1, sizeof(head));
}

void add_edge(int u,int v,int weight){
	to[++tot] = v;
	w[tot] = weight;
	nxt[tot] = head[u];
	head[u] = tot;
}

int main(){
	init();
	int n,m,u,v,weight;
	cin >> n >> m;
	for(int i = 0;i < m;i ++){
		cin >> u >> v >> weight;
		add_edge(u,v,weight);
	}
	for(u = 1;u <= n;u ++){
		cout << "从" << u << "出发的边:";
		for(int i = head[u];i != -1;i = nxt[i]){
			cout << "-> " << to[i] <<"(权" <<w[i] <<")";
		}
		cout << '\n';
	}
	return 0;
}
