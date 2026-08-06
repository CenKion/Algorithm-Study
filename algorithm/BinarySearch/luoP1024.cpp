#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

double ERR = 0.0001,a,b,c,d,now,resultNow,resultUpdate;

double fast_pow(double a,int b){
	double res = 1;
	while(b > 0){
		if((b & 1) == 1) res *= a;
		b = b >> 1;
		a *= a;
	}
	return res;
}

double cal(double x){
	return (a*fast_pow(x,3) + b*fast_pow(x,2) + c*x + d);
}

double f(double l,double r,double resultL,double resultR){
	double mid;
	while(r - l >= ERR){
		mid = l + (r - l) / 2;
		if(cal(mid) == 0) return mid;
		if(cal(mid) * resultR > 0)	r = mid;
		else l = mid;
	}
	return mid;
}

vector <double> ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> b >> c >>d;
	now = -101;
	resultNow = cal(now);
	for(int i = -100;i <= 101 && ans.size() < 3;i ++){
		resultUpdate = cal((double)i);
		if(resultUpdate == 0){
			ans.push_back((double)i);
			now = i + 0.1;
			resultNow = cal(now);
		}
		else if(resultUpdate * resultNow < 0){
			ans.push_back(f(now,(double)i,resultNow,resultUpdate));
			now = i;
			resultNow = resultUpdate;
		}
	}
	sort(ans.begin(),ans.end());
	for(int i = 0;i < ans.size();i ++){
		cout << fixed << setprecision(2) << ans[i] <<' ';
	}
	return 0;
}
