#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int n,h[MAXN],record[MAXN],maxl;

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
	}
	cout << maxl;
	return 0;
}

