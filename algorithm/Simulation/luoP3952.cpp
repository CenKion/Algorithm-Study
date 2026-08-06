#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int w,maxw,t,line,expectation,f,cntF;
bool flag[26],contri[105];
vector <char> vari;
char start,name,x,y,soldier;
string Complex,s;

int main(){
	scanf("%d",&t);
	for(int i = 0;i < t;i ++){
		vari.clear();
		memset(flag,0,sizeof(flag));
		memset(contri,-1,sizeof(contri));
		w = 0;
		maxw = 0;
		f = 2;
		soldier = '0';
		cntF = 0;
		cin >> line >> Complex;
		if(Complex == "O(1)") expectation = 0;
		else{
			int p = 0;
			for(int i = 4;i < Complex.length() && Complex[i] != ')';i ++){
				p = p * 10 + Complex[i] - '0';
			}
			expectation = p;
		}
		getline(cin,s);
		for(int j = 0;j < line;j ++){
			getline(cin,s);
			if(f != 2) continue;
			if(s == "E"){
				if(vari.empty()){
					f = -1;
					continue;
				}
				else{
					if(soldier == vari[vari.size() - 1]) soldier = '0';
					flag[vari[vari.size() - 1] - 'a'] = 0;
					vari.pop_back();
					if(contri[cntF--] != 0) w--;
				}
			}
			else{
				if(flag[s[2] - 'a']){
					f = -1;
					continue;
				}
				else{
					flag[s[2] - 'a'] = 1;
					vari.push_back(s[2]);
				}
				if(soldier != '0'){
					contri[++cntF] = 0;
					continue;
				}
				if(s[s.length() - 1] == 'n' && s[4] != 'n'){
					w ++;
					if(maxw < w) maxw = w;
					contri[++cntF] = 1;
				}
				else if(s[s.length() - 1] != 'n' && s[4] != 'n'){
					int p1 = 0,p2 = 0,i = 4;
					while(i < s.length() && s[i] != ' '){
						p1 = p1 * 10 + s[i] - '0';
						i ++;
					}
					i++;
					while(i < s.length()){
						p2 = p2 * 10 + s[i] - '0';
						i ++;
					}
					if(p1 > p2) soldier = s[2];
					contri[++cntF] = 0;
				}
				else if(s[s.length() - 1] != 'n' && s[4] == 'n'){
					soldier = s[2];
					contri[++cntF] = 0;
				}
				else contri[++cntF] = 0;
			}
		}
		if(f == 2){
			if(!vari.empty()) f = -1;
			else if(expectation == maxw) f = 1;
			else f = 0;
		}
		if(f == 1) cout << "Yes\n";
		else if(f == 0) cout << "No\n";
		else if(f == -1) cout << "ERR\n";
	}
	return 0;
}
