#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

char pre[65],in[65],post[65];
int n,pos[65];
string s;

void PreInToPost(int l,int r,int il,int ir,int nl,int nr){
	if(l > r) return; 
	post[nr] = pre[l];
	if(l == r) return;
	int root = pos[l];
	int leftLen = root - il;
	int rightLen = ir - root;
	PreInToPost(l + 1,l + leftLen,il,root - 1,nr - ir + il,nr - rightLen - 1);
	PreInToPost(l + leftLen + 1,r,root + 1,root + rightLen,nr - rightLen,nr - 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> s;
	n = s.length();
	for(int i = 1;i <= n;i ++){
		in[i] = s[i - 1];
	}
	cin >> s;
	for(int i = 1;i <= n;i ++){
		pre[i] = s[i - 1];
		for(int j = 1;j <= n;j ++){
			if(in[j] == pre[i]) pos[i] = j;
		}
	}
	PreInToPost(1,n,1,n,1,n);
	for(int i = 1;i <= n;i ++){
		cout << post[i];
	}
	cout << '\n';
	return 0;
}

