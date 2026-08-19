#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool vis[15],line1[40],line2[40];
vector <string> ans;
int n;

void dfs(int x,string s){
	for(int i = 1;i <= n;i ++){
		if(!vis[i]){
			if(line1[x - i + n])	continue;
			if(line2[x + i])	continue;
			bool f1 = 0,f2 = 0;
			line1[x - i + n] = 1;
			f1 = 1;
			line2[x + i] = 1;
			f2 = 1;
			vis[i] = 1;
			if(x == n){
				ans.push_back(s + to_string(i));
			}
			else dfs(x + 1,s + to_string(i) + ' ');
			vis[i] = 0;
			if(f1) line1[x - i + n] = 0;
			if(f2) line2[x + i] = 0;
		}
	}
}

int main(){
	cin >> n;
	dfs(1,"");
	for(int i = 0;i < 3;i ++){
		cout << ans[i] << '\n';
	}
	cout << ans.size();
	return 0;
}
