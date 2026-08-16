#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int T,n;
long long c[20005];

struct minister{
	long long left;
	long long right;
	int d;
};

bool cmp(minister &a,minister &b){
	if(a.d != b.d) return a.d < b.d;
    if(a.d <= 0) return a.left < b.left;
    return a.right > b.right;
}

minister arr[20005];

int main(){
	cin >> T;
	while(T -- ){
		cin >> n;
		for(int i = 1;i <= n;i ++){
			cin >> arr[i].left >> arr[i].right;
			arr[i].d = (arr[i].left > arr[i].right)?1:((arr[i].left == arr[i].right)?0:-1);
		}
		sort(arr + 1,arr + 1 + n,cmp);
		c[1] = arr[1].left + arr[1].right;
		long long SumLeft = arr[1].left;
		for(int i = 2;i <= n;i ++){
			SumLeft += arr[i].left;
			c[i] = max(c[i - 1],SumLeft) + arr[i].right;
		}
		cout << c[n] << '\n';
	}
	return 0;
}
