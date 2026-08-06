#include <iostream>
#include <stdio.h>

using namespace std;

long long int dfs(int n,int k,int now,int nowSum){
	if(k == 0){
		if(nowSum == n) return 1;
		return 0;
	}
	long long int ans = 0,t = (n - nowSum)/k;
	for(int i = now;i <= t;i ++){
		ans += dfs(n,k-1,i,nowSum + i);
	}
	return ans;
}

int n,k;

int main(){
	scanf("%d %d",&n,&k);
	cout << dfs(n,k,1,0);
	return 0;
}
