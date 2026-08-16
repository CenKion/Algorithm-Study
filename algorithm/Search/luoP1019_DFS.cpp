#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

string ss[25];
int n,ans,cnt[25][25],vis[25];
char head;

void dfs(int k,int l){
	if(l > ans) ans = l;
	for(int i = 1;i <= n;i ++){
		if(vis[i] < 2 && cnt[k][i] > 0){
			vis[i] ++;
			dfs(i,l + ss[i].length() - cnt[k][i]);
			vis[i] --;
		}
	}
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> ss[i];
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			int maxL = 0;
			int la = ss[i].length(),lb = ss[j].length();
			for(int k = la - 1;k > 0 && k >= la - lb;k --){
				int pos = k,l = 0;
				while(pos < la && l < lb){
					if(ss[i][pos] == ss[j][l]){
						pos ++;
						l ++;
					}
					else break;
				}
				if(l == lb) break;
				else if(pos == la){
					maxL = l;
					break;
				}
			}
			cnt[i][j] = maxL;
		}
	}
	cin >> head;
	for(int i = 1;i <= n;i ++){
		if(ss[i][0] == head){
			vis[i] ++;
			dfs(i,ss[i].length());
			vis[i] --;
		}
	}
	cout << ans;
	return 0;
}
