#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n,a[70],maxNum,sum,cnt,times[70],nex[70],len,target;
bool vis[70],ok;

void dfs(int k,int last,int rest){
	if(!rest){
		int i;
		if(k == target){
			ok = 1;
			return;
		}
		for(i = 1;i <= n;i ++){
			if(!vis[i]) break;
		}
		vis[i] = 1;
		dfs(k + 1,i,len - a[i]);
		vis[i] = 0;
		if(ok) return;
	}
	int l = last + 1,r = n;
	while(l < r){
		int mid = (l + r) >> 1;
		if(a[mid] > rest) l = mid + 1;
		else r = mid;
	}
	for(int i = l;i <= n;i ++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(k,i,rest - a[i]);
			vis[i] = 0;
			if(ok) return;
			
			if(rest == a[i] || rest == len) return;
			i = nex[i];
			if(i == n) return;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1,a + 1 + n,greater<int>());
	nex[n] = n;
	for(int i = n - 1;i > 0;i --){
		if(a[i] == a[i + 1]) nex[i] = nex[i + 1];
		else nex[i] = i;
	}
	for(len = a[1];len <= sum/2;len ++){
		if(sum % len != 0) continue;
		target = sum / len;
		vis[1] = 1;
		ok = 0;
		dfs(1,1,len - a[1]);
		vis[1] = 0;
		if(ok){
			cout << len;
			return 0;
		}
	}
	cout << sum;
	return 0;
}
