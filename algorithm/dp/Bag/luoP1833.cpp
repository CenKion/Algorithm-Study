#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int MAXN = 10005,MAXT = 1005;
int n,hhs,hhe,mms,mme,time1,time2,dt,cnt1,cnt2,tmpT,tmpC,tmpP;
int arr1[MAXN][4],arr2[MAXN][3];
long long dp[MAXT];

int main(){
	scanf("%d:%d %d:%d %d",&hhs,&mms,&hhe,&mme,&n);
	time1 = hhs * 60 + mms;
	time2 = hhe * 60 + mme;
	dt = time2 - time1;
	for(int i = 1;i <= n;i ++){
		scanf("%d %d %d",&tmpT,&tmpC,&tmpP);
		if(tmpP == 0){
			arr2[++cnt2][1] = tmpT;
			arr2[cnt2][2] = tmpC;
		}
		else{
			arr1[++cnt1][1] = tmpT;
			arr1[cnt1][2] = tmpC;
			arr1[cnt1][3] = tmpP;
		}
	}
	for(int i = 1;i <= cnt1;i ++){
		int num = min(arr1[i][3],dt/arr1[i][1]);
		for(int k = 1;num > 0;k <<= 1){
			if(k > num) k = num;
			num -= k;
			for(int j = dt;j >= k * arr1[i][1];j --){
				dp[j] = max(dp[j],dp[j - k * arr1[i][1]] + k * arr1[i][2]);
			}
		}
	}
	for(int i = 1;i <= cnt2;i ++){
		for(int j = arr2[i][1];j <= dt;j ++){
			dp[j] = max(dp[j],dp[j - arr2[i][1]] + arr2[i][2]);
		}
	}
	cout << dp[dt];
	return 0;
}

