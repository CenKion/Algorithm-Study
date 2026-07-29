#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int a[20005];
int b[20005];
int c[20005];

void StringToNum(int *x,string s,int l){
	for(int i = 0;i < l;i ++){
		x[i] = s[l - 1 -i] - '0';
	}
}

void Sum(int* a,int *b,int *c,int la,int lb,int& lc){
	lc = la+lb;
	for(int i = 0;i < la;i ++){
		for(int j = 0;j < lb;j ++){
			c[i+j] += a[i] * b[j];
		}
	}
	for(int i = 0;i < lc;i ++){
		if(c[i]>9){
			c[i + 1] += c[i] /10;
			c[i] %= 10;
		}
	}
	while(lc > 1 && c[lc-1] == 0){
		lc--;
	}
}

void show(int *x,int lx){
	for(int i = 0;i < lx;i ++){
		cout <<x[lx-i-1];
	}
}

int main(){
	string sa,sb;
	cin >> sa >> sb;
	int la = sa.length(),lb = sb.length();
	StringToNum(a,sa,la);
	StringToNum(b,sb,lb);
	int lc;
	Sum(a,b,c,la,lb,lc);
	show(c,lc);
	return 0;
}
