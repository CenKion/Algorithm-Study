#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int id[50005],sum[50005],first[7],last[7],n,maxL;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> id[i];
		sum[i] = (sum[i - 1] + id[i]) % 7;
		if(sum[i] == 0){
			maxL = i;
			continue;
		}
		if(first[sum[i]] == 0) first[sum[i]] = i;
		last[sum[i]] = i;
		if(last[sum[i]] - first[sum[i]] > maxL) maxL = last[sum[i]] - first[sum[i]];
	}
	cout << maxL;
	return 0;
}
