#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x7fffffff;
int n,ans1,ans2,a[205];
int rem1[205][205],rem2[205][205];

int dfs1(int L,int R){
	if(rem1[L][R]) return rem1[L][R];
	if(L == R) return 0;
	int res = INF;
	for(int i = L;i < R;i ++){
		res = min(res,dfs1(L,i) + dfs1(i + 1,R) + a[R] - a[L - 1]);
	}
	rem1[L][R] = res;
	return res;
}

int dfs2(int L,int R){
	if(rem2[L][R]) return rem2[L][R];
	if(L == R) return 0;
	int res = 0;
	for(int i = L;i < R;i ++){
		res = max(res,dfs2(L,i) + dfs2(i + 1,R) + a[R] - a[L - 1]);
	}
	rem2[L][R] = res;
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		a[i + n] = a[i];
	}
	for(int i = 1;i <= 2 * n;i ++){
		a[i] += a[i - 1];
	}
	dfs1(1,2 * n);
	dfs2(1,2 * n);
	ans1 = INF,ans2 = 0;
	for(int i = 1;i <= n;i ++){
		ans1 = min(ans1,rem1[i][i + n - 1]);
		ans2 = max(ans2,rem2[i][i + n - 1]);
	}
	cout << ans1 << '\n' << ans2;
	return 0;
}

