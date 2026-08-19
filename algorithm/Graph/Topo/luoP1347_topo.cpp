#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

string s;
int ind[26],ind2[26];
bool show[26];
int n, m ,k, cntShow;

vector <int> edges[26];

struct Node{
	int name;
	int layer;
};

void topo(){
	s.clear();
	int cnt = 0,ans = 1;
	Node fro;
	queue <Node> Q;
	for(int i = 0;i < 26;i ++){
		if(show[i] && ind2[i] == 0){
			Q.push((Node){i,1});
			cnt ++;
		}
	}
	while(!Q.empty()){
		fro = Q.front();
		s += (char)(fro.name + 'A');
		Q.pop();
		for(int i = 0;i < edges[fro.name].size();i ++){
			ind2[edges[fro.name][i]] --;
			if(ind2[edges[fro.name][i]] == 0){
				Q.push((Node){edges[fro.name][i],fro.layer+1});
				ans = max(ans,fro.layer+1);
				cnt ++;
			}
		}
	}
	if(cnt != cntShow){
		cout << "Inconsistency found after " << k << " relations.";
		exit(0);
	}
	if(ans == n){
		cout << "Sorted sequence determined after "<<k<<" relations: "<<s<<".";
		exit(0);
	}
}

int main(){
	cin >> n >> m;
	char uu,cmp,vv;
	for(int i = 0;i < m;i ++){
		cin >> uu>> cmp>> vv;
		if(!show[uu - 'A']){
			show[uu - 'A'] = 1;
			cntShow ++;
		}
		if(!show[vv - 'A']){
			show[vv - 'A'] = 1;
			cntShow ++;
		}
		edges[uu - 'A'].push_back(vv-'A');
		ind[vv-'A']++;
		memcpy(ind2,ind,sizeof(ind));
		k = i + 1;
		topo();
	}
	cout << "Sorted sequence cannot be determined.";
	return 0;
}
