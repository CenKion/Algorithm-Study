#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int l,k;
long long x[100005],maxl,maxr,minl,minr,ansMin,ansMax;

int Judge(long long t){
	int cnt = 0;
	long long sumL = 0;
	for(int i = 1;i <= l;i ++){
		sumL += x[i];
		if(sumL < 0) sumL = 0;
		else if(sumL >= t){
			cnt ++;
			sumL = 0;
		}
	}
	if(cnt == k) return 0;
	if(cnt < k) return -1;
	if(cnt > k) return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> l >>k;
	for(int i = 1;i <= l;i ++){
		cin >> x[i];
	}
	maxl = 1,maxr = 1e18,minl = 1,minr = 1e18;
	while(maxl <= maxr){
		long long mid = maxl + (maxr - maxl) / 2;
		if(Judge(mid) == 0){
			maxl = mid + 1;
			ansMax = mid;
		}
		else if(Judge(mid) == 1){
			maxl = mid + 1;
		}
		else{
			maxr = mid - 1;
		}
	}
	while(minl <= minr){
		long long mid = minl + (minr - minl) / 2;
		if(Judge(mid) == 0){
			minr = mid - 1;
			ansMin = mid;
		}
		else if(Judge(mid) == 1){
			minl = mid + 1;
		}
		else{
			minr = mid - 1;
		}
	}
	if(ansMin == 0) cout << -1;
	else{
		cout << ansMin <<' ' << ansMax;
	}
	return 0;
}
