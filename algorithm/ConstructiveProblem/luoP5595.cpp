#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string s;
bool showed[3];
int a[1000005];
int b[1000005];

int main(){
	cin >> s;
	int l = s.length();
	for(int i = l - 1;i >= 0;i --){
		if(s[i] == 'Z' && (showed[0] || showed[1])){
			cout << -1;
			exit(0);
		}
		if(s[i] == 'Z') showed[2] = 1;
		else if(s[i] == 'X') {
			a[l - i] ++;
			showed[0] = 1;
		}
		else{
			b[l - i] ++;
			showed[1] = 1;
		}
	}
	for(int i = l;i >= 1;i --){
		cout << a[i];
	}
	cout << '\n';
	for(int i = l;i >= 1;i --){
		cout << b[i];
	}
	return 0;
}
