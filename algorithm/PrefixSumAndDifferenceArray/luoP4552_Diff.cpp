#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int n,last,now,a[100005];
long long sum1,sum2,ope,results;

int main(){
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> now;
		a[i] = now - last;
		last = now;
		if(i != 1){
			if(a[i] > 0) sum1 += a[i];
			else if(a[i] < 0) sum2 += a[i];
		}
	}
	ope = max(abs(sum1),abs(sum2));
	results = abs(sum1 + sum2) + 1;
	cout << ope << '\n' << results;
	return 0;
}
