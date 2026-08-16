#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

const int SaveSpace = 6813450,MAXN = 100000000;

bool notPrime[MAXN];
int T,cnt,cnt2,Prime[SaveSpace],ans,start = 1030,Possi[SaveSpace];
int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool checkDay(string x){
	int lx = x.length();
	if(x[lx - 1] == '-' || x[lx - 2] == '-') return 1;
	int tmp = stoi(x.substr(lx - 2,2));
	return !notPrime[tmp];
}

bool checkMonth(string x){
	int lx = x.length();
	for(int i = lx - 4;i < lx;i ++){
		if(x[i] == '-') return 1;
	}
	int tmp = stoi(x.substr(lx - 4,4));
	return !notPrime[tmp];
}

bool check(string x){
	int year = stoi(x.substr(0,4));
	int mon = stoi(x.substr(4,2));
	int day = stoi(x.substr(6,2));
	if(year % 400 == 0) month[2] = 29;
	else if(year % 4 == 0 && year % 100 != 0) month[2] = 29;
	else month[2] = 28;
	if(year < 1 || year > 9999) return 0;
	if(mon > 12 || mon < 1) return 0;
	if(day > month[mon] || day < 1) return 0;
	if(notPrime[stoi(x.substr(0,8))]) return 0;
	return 1;
}

void GetPrime(){
	notPrime[1] = 1;
	for(int i = 2;i < MAXN;i ++){
		if(!notPrime[i]){
			Prime[++ cnt] = i;
			if(i > 10000 && checkDay(to_string(i)) && checkMonth(to_string(i))) Possi[++cnt2] = i;
		}
		for(int j = 1;j <= cnt && Prime[j] * i < MAXN;j ++){
			notPrime[Prime[j] * i] = 1;
			
			if(i % Prime[j] == 0) break;
		}
	}
}

void dfs(string &s,int pos,string x){
	if(pos == 0){
		if(check(x)) ans++;
		return;
	}
	if(pos == 6 && !checkDay(x)) return;
	else if(pos == 4 && !checkMonth(x)) return;
	if(s[pos - 1] == '-'){
		for(int i = 0;i <= 9;i ++){
			dfs(s,pos - 1,to_string(i) + x);
		}
	}
	else dfs(s,pos - 1,s[pos - 1] + x);
}

int main(){
	GetPrime();
	cin >> T;
	string date;
	while(T --){
		cin >> date;
		bool f = 1;
		for(char c : date){
			if(c != '-'){
				f = 0;
				break;
			}
		}
		
		ans = 0;
		if(checkDay(date) && checkMonth(date)){
			if(!f) dfs(date,8,"");
			else{
				for(int i = 1;i <= cnt2;i ++){
					string tmpS = to_string(Possi[i]);
					while(tmpS.length() < 8) tmpS = '0' + tmpS;
					if(check(tmpS)) ans ++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
