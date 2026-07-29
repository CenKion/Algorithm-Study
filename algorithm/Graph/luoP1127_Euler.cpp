#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n;
vector <string> words(1005);
vector <int> edges[1005];
int ind[1005];
int rnd[1005];
bool vis[1005];

bool check(string a,string b){
	int la = a.length();
	return a[la - 1] == b[0];
}

void dfs(int s,string cur,int cnt){
	if(cnt == n){
		cur[cur.length() - 1] = ' ';
		cout << cur;
		exit(0);
	}
	for(auto i : edges[s]){
		if(!vis[i]){
			vis[i] = 1;
			dfs(i ,cur + words[i] + '.',cnt + 1);
			vis[i] = 0;
		}
	}
}

int main(){
	bool f1,f2;
	cin >> n;
	string tmpS;
	for(int i = 1;i <= n;i ++){
		cin >> tmpS;
		words[i]=tmpS;
		ind[tmpS[0]] ++;
		rnd[tmpS[tmpS.length() - 1]] ++;
	}
	sort(words.begin()+1,words.begin() + n + 1);
	for(int i = 1;i <= n;i ++){
		for(int j = i + 1;j <= n;j ++){
			if(check(words[i],words[j])) edges[i].push_back(j);
			if(check(words[j],words[i])) edges[j].push_back(i); 
		}
	}
	for(int i = 1;i <= n;i ++){
		if(ind[words[i][0]] == rnd[words[i][0]] + 1){
			vis[i] = 1;
			dfs(i,words[i] + '.', 1);
			vis[i] = 0;
		}
	}
	vis[1] = 1;
	dfs(1,words[1] + '.',1);
	vis[1] = 0;
	cout << "***";
	return 0;
}
