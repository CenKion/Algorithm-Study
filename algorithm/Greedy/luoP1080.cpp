#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int c[5000],lc,n;
string ans = "0";

struct man{
	int left,right;
	string MultiResult;
};

string multi(string x,string y){
	int lx = x.length(),ly = y.length();
	lc = lx + ly;
	memset(c,0,sizeof(c));
	for(int i = lx - 1;i >= 0;i --){
		for(int j = ly - 1;j >= 0;j --){
			c[lx - i + ly - j - 1] += (x[i] - '0') * (y[j] - '0');
		}
	}
	for(int i = 1;i <= lc;i ++){
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	while(lc > 0 && c[lc] == 0) lc--;
	if(lc == 0) return "0";
	string t;
	for(int i = lc;i >= 1;i --){
		t += to_string(c[i]);
	}
	return t;
}

string divide(string x,int y){
	int tmp = 0;
	string t;
	for(char k : x){
		tmp = tmp * 10 + k - '0';
		if(tmp >= y){
			t += (char)(tmp / y + '0');
			tmp %= y;
		}
		else if(t.length() > 0) t += '0';
	}
	if(t.length() == 0) t = "0";
	return t;
}

bool cmp(man &x,man &y){
	if(x.MultiResult.length() != y.MultiResult.length()) return x.MultiResult.length() < y.MultiResult.length();
	return x.MultiResult < y.MultiResult;
}

man arr[1005];
string Results[1005];

int main(){
	cin >> n;
	for(int i = 1;i <= n + 1;i ++){
		cin >> arr[i].left >> arr[i].right;
		arr[i].MultiResult = to_string(arr[i].left * arr[i].right);
	}
	sort(arr + 2, arr + 2 + n,cmp);
	Results[1] = to_string(arr[1].left);
	for(int i = 2;i <= n + 1;i ++){
		Results[i] = multi(Results[i - 1],to_string(arr[i].left));
		string tmp = divide(Results[i - 1],arr[i].right);
		cout << Results[i - 1] << "  " << arr[i].right << "  " << tmp << '\n';
		if(tmp.length() > ans.length()) ans = tmp;
		else if(tmp.length() == ans.length() && ans < tmp) ans = tmp;
	}
	cout << ans;
	return 0;
}
