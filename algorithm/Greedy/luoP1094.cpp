#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAXN = 3 * 1e4 + 5;
int n,w,prize[MAXN],ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> w >> n;
	for(int i = 1;i <= n;i ++){
		cin >> prize[i];
	}
	sort(prize + 1,prize + 1 + n);
	int i = 1,j = n,ans = n;
	while(i < j){
		if(prize[i] + prize[j] <= w){
			i ++;
			j --;
			ans --;
		}
		else j --;
	}
	cout << ans;
	return 0;
}
