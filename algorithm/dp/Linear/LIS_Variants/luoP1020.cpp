#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int cnt,cnt2,h[MAXN],record[MAXN],group[MAXN],maxl;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	record[0] = 0x7fffffff;
	while(cin >> h[++cnt]){
		if(h[cnt] <= record[maxl]) record[++maxl] = h[cnt];
		else{
			int l = 0,r = maxl + 1;
			while(l + 1 < r){
				int mid = l + ((r - l) >> 1);
				if(record[mid] < h[cnt]) r = mid;
				else l = mid;
			}
			record[l + 1] = h[cnt];
		}
		if(group[cnt2] < h[cnt]) group[++cnt2] = h[cnt];
		else{
			int l = 0,r = cnt2;
			while(l + 1 < r){
				int mid = l + ((r - l) >> 1);
				if(group[mid] >= h[cnt]) r = mid;
				else l = mid;
			}
			group[r] = h[cnt];
		}
	}
	cout << maxl << '\n' << cnt2;
	return 0;
}

