#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N,E,M,A;
vector <int> edge[200005];
int maxA[200005],a[200005],start[200005];

void bfs(int x,int c){
	queue <int> Q;
	if(maxA[x] < c){
		Q.push(x);
		maxA[x] = c;
	}
	int fro;
	while(!Q.empty()){
		fro = Q.front();
		Q.pop();
		for(int i = 0;i < edge[fro].size();i ++){
			if(edge[fro][i] != A && maxA[fro] >= a[edge[fro][i]] && maxA[fro] > maxA[edge[fro][i]]){
				maxA[edge[fro][i]] = maxA[fro];
				Q.push(edge[fro][i]);
			}
		}
	}
}

int main(){
	int u,v;
	scanf("%d %d %d %d",&N,&E,&M,&A);
	memset(maxA,-1,sizeof(maxA));
	for(int i = 1;i <= N;i ++){
		scanf("%d",&a[i]);
	}
	for(int i = 1;i <= E;i ++){
		scanf("%d %d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i = 1;i <= M;i ++){
		scanf("%d",&start[i]);
		bfs(start[i],a[start[i]]);
	}
	int cnt = 0;
	for(int i = 0;i < edge[A].size();i ++){
		if(maxA[edge[A][i]] != -1) cnt++;
	}
	printf("%d",cnt);
	return 0;
}
