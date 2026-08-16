#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int n,c,cnt = 0;
long long ans,w[1005],pre[1005];

void dfs(int k,int sum){
	if(sum + pre[k] <= ans) return;
	if(ans < sum) ans = sum;
	if(k == 0) return;
	if(sum + w[k] <= c) dfs(k - 1,sum + w[k]);
	dfs(k - 1,sum);
}

int main(){
	cin >> n >> c;
	for(int i = 1;i <= n;i ++){
		cin >> w[i];
		pre[i] = pre[i - 1] + w[i];
		if(w[i] <= c) cnt ++;
	}
	dfs(cnt,0);
	cout << ans;
	return 0;
}
