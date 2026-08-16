#include <iostream>
#include <string>
#include <cstring>

using namespace std;

short int a[505];
short int b[505];
short int SumAB[510];

void StringToNum(short int* a,string s){
	int l = s.length();
	for(int i = l-1;i >=0;i --){
		a[l-i-1] = s[i] - '0';
	}
}

void sum(short int* a,short int* b,short int* result,int la,int lb,int &lr){
	int i = 0;
	short int c = 0;
	lr = max(la ,lb);
	while(i < lr){
		result[i] = a[i] + b[i] + c;
		c = result[i] / 10;
		result[i] %= 10;
		i ++;
	}
	if(c != 0) {
		result[i] = c;
		lr ++;
	}
}

void show(short int* result,int lr){
	for(int i = 0;i < lr;i ++){
		cout<<result[lr-1-i];
	}
}

int main(){
	string s;
	cin >> s;
	StringToNum(a,s);
	int la = s.length();
	cin >> s;
	StringToNum(b,s);
	int lb = s.length();
	int lr;
	sum(a,b,SumAB,la,lb,lr);
	show(SumAB,lr);
    return 0;
}
