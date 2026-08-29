#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 105,MAXA = 2.5 * 1e4 +5;
int T,n,a[MAXN],ans;
bool dp[MAXA];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while(T --){
		memset(dp,0,sizeof(dp));
		cin >> n;
		for(int i = 1;i <= n;i ++){
			cin >> a[i];
		}
		ans = n;
		sort(a + 1,a + 1 + n);
		for(int i = 1;i <= n;i ++){
			if(dp[a[i]]){
				ans --;
				continue;
			}
			dp[a[i]] = 1;
			for(int j = a[i] + 1;j <= a[n];j ++){
				dp[j] = dp[j] || dp[j - a[i]];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

