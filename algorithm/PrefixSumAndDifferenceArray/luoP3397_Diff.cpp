#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n,m,x1,y1,x2,y2;

int arr[1005][1005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= m;i ++){
		cin >> x1 >> y1 >> x2 >> y2;
		for(int j = x1;j <= x2;j ++){
			arr[j][y1] ++;
			arr[j][y2 + 1] --;
		}
	}
	for(int i = 1;i <= n;i ++){
		int tmp = 0;
		for(int j = 1;j <= n;j ++){
			tmp += arr[i][j];
			cout << tmp;
			if(j != n) cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}
