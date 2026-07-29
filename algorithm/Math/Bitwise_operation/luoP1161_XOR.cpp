#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans;

int main(){
	double a;
	int t,n,pos;
	cin >> n;
	for(int i = 0;i < n;i ++){
		cin >> a >> t;
		for(int j = 1;j <= t;j ++){
			ans ^= (int)(a * j);
		}
	}
	cout << ans;
	return 0;
}
