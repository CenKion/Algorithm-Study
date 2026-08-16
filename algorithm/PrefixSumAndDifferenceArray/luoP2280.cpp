#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int n,m,x,y,v,ans,arr[5005][5005];

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> x >> y >> v;
		arr[x][y] += v;
	}
	for(int i = 0;i <= 5000;i ++){
		for(int j = 0;j <= 5000;j ++){
			if(i == 0 && j == 0) continue;
			if(i == 0) arr[i][j] += arr[i][j - 1];
			else if(j == 0) arr[i][j] += arr[i - 1][j];
			else arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}
	for(int i = m - 1;i <= 5000;i ++){
		for(int j = m - 1;j <= 5000;j ++){
			int tmp;
			if(i == m - 1 && j == m - 1){
				tmp = arr[i][j];
			}
			else if(i == m - 1){
				tmp = arr[i][j] - arr[i][j - m];
			}
			else if(j == m - 1){
				tmp = arr[i][j] - arr[i - m][j];
			}
			else tmp = arr[i][j] - arr[i - m][j] - arr[i][j - m] + arr[i - m][j - m];
			if(tmp > ans) ans = tmp;
		}
	}
	cout << ans;
	return 0;
}
