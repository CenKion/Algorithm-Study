#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 105;

int n,h[MAXN],record[MAXN],LIS[MAXN],LISR[MAXN],maxl,ans = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> h[i];
		if(record[maxl] < h[i]) record[++maxl] = h[i];
		else{
			int l = 0,r = maxl + 1;
			while(l + 1 < r){
				int mid = l + ((r - l) >> 1);
				if(record[mid] < h[i]) l = mid;
				else r = mid;
			}
			record[l + 1] = h[i];
		}
		LIS[i] = maxl;
	}
	maxl = 0;
	memset(record,0,sizeof(record));
	for(int i = n;i >= 1;i --){
		if(record[maxl] < h[i]) record[++ maxl] = h[i];
		else{
			int l = 0,r = maxl + 1;
			while(l + 1 < r){
				int mid = l + ((r - l) >> 1);
				if(record[mid] < h[i]) l = mid;
				else r = mid;
			}
			record[l + 1] = h[i];
		}
		LISR[i] = maxl;
	}
	for(int i = 1;i <= n;i ++){
		int tmp = LIS[i] + LISR[i + 1];
		if(tmp > ans) ans = tmp;
	}
	cout << n - ans;
	return 0;
}

