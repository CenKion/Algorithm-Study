#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int n,m,a[50005],l,r,L,ans;

bool Judge(int x){
	int tot = 0,i = 0,now = 0;
	while(i < n + 1){
		i ++;
		if(a[i] - a[now] < x) tot ++;
		else now = i;
	}
	if(tot > m) return 0;
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> L >> n >> m;
	a[n + 1] = L;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	l = 1,r = L;
	while(l <= r){
		int mid = l + (r - l) / 2;
		if(Judge(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << l - 1;
	return 0;
}
