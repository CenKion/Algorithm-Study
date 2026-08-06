#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int ans[25][25][25];

bool Judge(int a,int b,int c){
	return (a > 0 && a < 21 && b > 0 && b < 21 && c > 0 && c < 21);
}

int w(int a,int b,int c){
	int result;
	if(Judge(a,b,c) && ans[a][b][c] != 0) return ans[a][b][c];
	else if(a <= 0 || b <= 0 || c <= 0){
		result = 1;
		a = 0,b = 0,c = 0;
	}
	else if(a > 20 || b > 20 || c > 20){
		result = w(20,20,20);
		a = 20,b = 20,c = 20;
	}
	else if(a < b && b < c) result = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	else result = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	if(ans[a][b][c] == 0) ans[a][b][c] = result;
	return result;
}

int main(){
	int a,b,c;
	string sa,sb,sc;
	while(cin >> sa >> sb >> sc && !(sa == "-1" && sb == "-1" && sc == "-1")){
		if(sa[0] == '-' || sb[0] == '-' || sc[0] == '-'){
			a = 0,b = 0,c = 0;
		}
		else if(sa.length() > 2 || sb.length() > 2 || sc.length() > 2){
			a = 20,b = 20,c = 20;
		}
		else{
			a = stoi(sa),b = stoi(sb),c = stoi(sc);
		}
		cout << "w("<<sa<<", "<<sb<<", "<<sc<<") = "<<w(a,b,c)<<'\n';
	}
	return 0;
}
