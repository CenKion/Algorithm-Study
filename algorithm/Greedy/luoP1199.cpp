#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAXN = 505;
int n,hero[MAXN][MAXN],ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		for(int j = i + 1;j <= n;j ++){
			cin >> hero[i][j];
			hero[j][i] = hero[i][j];
		}
		for(int j = 1;j <= n;j ++){
			if(i == j) continue;
			if(hero[i][j] > hero[i][n + 1]){
				hero[i][n + 2] = hero[i][n + 1];
				hero[i][n + 1] = hero[i][j];
			}
			else if(hero[i][j] > hero[i][n + 2]) hero[i][n + 2] = hero[i][j];
		}
		if(ans < hero[i][n + 2]) ans = hero[i][n + 2];
	}
	cout << 1 << '\n' <<ans;
	return 0;
}
