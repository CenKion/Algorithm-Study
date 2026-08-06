#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long int n,m,l,r,s,ans = -1,li[200005],ri[200005],w[200005],v[200005];
long long result1[200005],result2[200005];

long long int CalY(long long int weight){
	long long int sum = 0;
	for(int i = 1;i <= n;i ++){
		if(w[i] >= weight){
			result1[i] = 1 + result1[i - 1];
			result2[i] = v[i] + result2[i - 1];
		}
		else{
			result1[i] = result1[i - 1];
			result2[i] = result2[i - 1];
		}
	}
	for(int i = 1;i <= m;i ++){
		sum += (result1[ri[i]] - result1[li[i] - 1]) * (result2[ri[i]] - result2[li[i] - 1]);
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >>s;
	for(int i = 1;i <= n;i ++){
		cin >> w[i] >> v[i];
		if(w[i] > r) r = w[i];
	}
	for(int i = 1;i <= m;i ++){
		cin >> li[i] >> ri[i];
	}
	while(l <= r){
		long long int mid = l + (r - l) / 2;
		long long int cal = CalY(mid);
		if(ans == -1) ans = cal;
		if(cal == s){
			ans = cal;
			break;
		}
		if(cal > s){
			if(cal - s < abs(ans - s)) ans = cal;
			l = mid + 1;
		}
		else{
			if(s - cal < abs(ans - s)) ans = cal;
			r = mid - 1;
		}
	}
	cout << abs(ans - s);
	return 0;
}
