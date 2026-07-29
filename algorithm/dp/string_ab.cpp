#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

/*给定一个由字符'a'和字符'b'组成的字符串，可以删除若干字符，使得剩下来的字符串满足前后段为a，中间段为b（aaa....aaabbbb.....bbbbaaa.....aaa）,区段可以没有字符（ba,ab,b,aa都是合法的），求最长剩下字符串的长度。

【输入形式】

      输入为一行一个长度不超过5000的非空字符串，字符串仅由字符'a'和字符'b'组成。
【输出形式】

      输出为一个整数，表示符合要求的最长剩下字符串长度*/

int prefA[5005];
int prefB[5005];
int sufA[5005];

void CntAB(string s){
	int l = s.length();
	for(int i = 1;i <= l;i ++){
		prefA[i] =(s[i - 1] == 'a')?(prefA[i - 1] + 1):(prefA[i - 1]);
		prefB[i] =(s[i - 1] == 'b')?(prefB[i - 1] + 1):(prefB[i - 1]);
	}
	for(int i = l - 1;i >= 0;i --){
		sufA[i] = (s[i] == 'a')?(sufA[i + 1] + 1):(sufA[i + 1]);
	}
}

int main(){
	string s;
	cin >> s;
	CntAB(s);
	int max_left = - 6000;
	int l = s.length();
	int ans = 0;
	for(int r = 0;r <= l;r ++){
		max_left = max(max_left ,prefA[r] - prefB[r]);
		int cur = max_left + prefB[r] + sufA[r];
		if(cur > ans) ans = cur;
	}
	cout << ans;
	return 0;
}
