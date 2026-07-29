#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool Floyd[1005][1005];
int cntColumn[1005];
int K,N,M,ans;
set <int> hasCow;

int main(){
	cin >> K >> N >> M;
	int ci,a,b;
	for(int i = 1;i <= N;i ++){
		Floyd[i][i] = 1;
	}
	for(int i = 0;i < K;i ++){
		cin >> ci;
		hasCow.insert(ci);
	}
	for(int i = 0;i < M;i ++){
		cin >> a >> b;
		Floyd[a][b] = 1;
	}
	for(int i = 1;i <= N;i ++){
		for(int j = 1;j <= N;j ++){
			if(Floyd[j][i]){
				for(int k = 1;k <= N;k ++){
					Floyd[j][k] = Floyd[i][k] || Floyd[j][k];
				}
			}
		}
	}
	bool f;
	for(int i = 1;i <= N;i ++){
		f = 1;
		for(auto it : hasCow){
			if(!Floyd[it][i]){
				f = 0;
				break; 
			}
		}
		if(f) ans++;
	}
	cout << ans;
	return 0;
}
