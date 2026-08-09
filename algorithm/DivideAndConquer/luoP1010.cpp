#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string f(int n){
	vector <int> number;
	int k = 0;
	while(n > 0){
		if((n & 1) == 1) number.push_back(k);
		n >>= 1;
		k ++;
	}
	string s;
	for(int i = number.size() - 1;i >= 0;i --){
		int t = number[i];
		if(s.length() > 0) s += "+";
		if(t == 0) s += "2(0)";
		else if(t == 1) s += "2";
		else s += "2(" + f(t) + ")";
	}
	return s;
}

int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	cout << f(n);
	return 0;
}
