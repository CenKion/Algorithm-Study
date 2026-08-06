#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct player{
	int number;
	int s;
	int w;
};

bool cmp(player &A,player &B){
	if(A.s != B.s) return A.s > B.s;
	return A.number < B.number;
}

int N,R,Q,cntWin,cntLose;
player arr[200005],win[200005],lose[200005];

void MergeSort(){
	int i = 0,j = 0,k = 1;
	while(i < cntWin && j < cntLose){
		if(cmp(win[i],lose[j])) arr[k ++] = win[i ++];
		else arr[k ++] = lose[j ++];
	}
	while(i < cntWin) arr[k ++] = win[i ++];
	while(j < cntLose) arr[k ++] = lose[j ++];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> R >> Q;
	for(int i = 1;i <= 2 * N;i ++){
		cin >> arr[i].s;
		arr[i].number = i;
	}
	for(int i = 1;i <= 2 * N;i ++){
		cin >> arr[i].w;
	}
	sort(arr + 1,arr + 1 + 2 * N,cmp);
	for(int i = 1;i <= R;i ++){
		cntWin = 0,cntLose = 0;
		for(int j = 1;j < 2 * N;j += 2){
			if(arr[j].w < arr[j + 1].w){
				arr[j + 1].s++;
				win[cntWin ++] = arr[j + 1];
				lose[cntLose ++] = arr[j];
			}
			else{
				arr[j].s++;
				win[cntWin ++] = arr[j];
				lose[cntLose ++] = arr[j + 1];
			}
		}
		MergeSort();
	}
	cout << arr[Q].number;
	return 0;
}
