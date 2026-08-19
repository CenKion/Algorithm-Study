#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 5 * 1e5 + 5;

struct BIT{
	int c[MAXN];
	
	int lowbit(int x){
		return x & -x;
	}
	
	void update(int pos,int k){
		while(pos < MAXN){
			c[pos] += k;
			pos += lowbit(pos);
		}
	}
	
	int query(int x){
		int result = 0;
		while(x > 0){
			result += c[x];
			x -= lowbit(x);
		}
		return result;
	}
}t;

int n,m,q,x,y,k;

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> k;
		t.update(i,k);
	}
	for(int i = 1;i <= m;i ++){
		cin >> q >> x >> y;
		if(q == 1) t.update(x,y);
		else cout << t.query(y) - t.query(x - 1) << '\n';
	}
	return 0;
}
