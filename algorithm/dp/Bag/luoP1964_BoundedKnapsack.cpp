#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm> 
using namespace std;

#define capacity 21

struct item{
	int count;
	int value;
	int space;
	char name[105];
};

item arr[105];
int dp[22];

int main() {
    int m,n,v,cnt = 1;
    cin >> m >>n;
    v = capacity - m;
    for(int i = 1;i <= n;i ++){
    	cin >> arr[i].count >> arr[i].value >> arr[i].space >> arr[i].name;
	}
	for(int i = 2;i <= n;i ++){
		bool f = 0;
		for(int j = 1;j <= cnt;j ++){
			if(strcmp(arr[i].name,arr[j].name) == 0){
				f = 1;
				arr[j].count += arr[i].count;
				break;
			}
		}
		if(!f) cnt ++;
	}
	for(int i = 1;i <= cnt;i ++){
		for(int j = v;j >= 0;j --){
			for(int k = 0;k <= arr[i].count;k ++){
				int s = (k + arr[i].space - 1)/arr[i].space;
				if(j < s) break;
				dp[j] = max(dp[j],dp[j - s] + k * arr[i].value);
			}
		}
	}
	cout << dp[v];
    return 0;
}

