#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int* getNext(string p){
	int l = p.length();
	int *next = new int[l];
	next[0] = -1;
	int i , j;
	for(i = 1;i < l;i++){
		j = next[i - 1];
		while(j >= 0 && p[i] != p[j + 1]){
			j = next[j];
		}
		if(p[i] == p[j + 1]){
			next[i] = j + 1;
		}
		else{
			next[i] = -1;
		}
	}
	return next;
}

bool kmpJudge(int *next , string p , string t){		//仅能判断存在及找出第一个位置 
	int lp = p.length(), lt = t.length();
	int i = 0, j = 0;
	while(i < lp && j < lt){
		if(p[i] == t[j]){
			i ++;
			j ++;
		}
		else if(i > 0){
			i = next[i - 1] + 1;
		}
		else{
			j ++;
		}
	}
	if(i == lp){
		return 1;
	}
	return 0;
}

vector <int> kmpSearch(int *next , string p , string t){		//找出所有位置 
	vector <int> pos;
	int lp = p.length(), lt = t.length();
	int i = 0, j = 0;
	while(j + lp <= lt){
		while(i < lp && p[i] == t[j + i]){
			i ++;
		}
		if(i == lp){
			pos.push_back(j);
			j ++;
			i = 0;
		}
		else if(i > 0){
			j +=i - 1 - next[i - 1];
			i = next[i - 1] + 1;
		}
		else{
			j ++;
		}
	}
	return pos; 
}

int main(){
	string s1,s2;
    cin >> s1 >> s2;
    int *next = getNext(s2);
    vector <int> ans = kmpSearch(next ,s2 ,s1);
	for(int i = 0;i < ans.size();i ++){
        cout << ans[i] + 1 << '\n';
    }
    for(int i = 0;i < s2.length();i ++){
        cout << next[i] + 1 << ' ';
    }
	return 0;
}
