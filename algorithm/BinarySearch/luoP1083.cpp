#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long int n,m,l,r,need[1000005],diff[1000005],rest[1000005],d[1000005],s[1000005],t[1000005];

bool Judge(int x){
	memset(diff,0,sizeof(diff));
	for(int i = 1;i <= x;i ++){
		diff[s[i]] += d[i];
		diff[t[i] + 1] -= d[i];
	}
	for(int i = 1;i <= n;i ++){
		need[i] = need[i - 1] + diff[i];
		if(need[i] > rest[i]) return 0;
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> rest[i];
	}
	for(int i = 1;i <= m;i ++){
		cin >> d[i] >> s[i] >> t[i];
	}
	l = 1,r = m;
	while(l <= r){
		int mid = l + (r - l) / 2;
		if(Judge(mid)) l = mid + 1;
		else r = mid - 1;
	}
	if(l == m + 1) cout << 0;
	else cout << -1 << '\n' << l;
	return 0;
}
