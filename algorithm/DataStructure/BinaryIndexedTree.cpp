#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int N = 5e5 + 5;

struct BIT{
	int c[N],lowbit(int x){return x & -x;}
	void update(int x,int k){while(x < N) c[x] += k,x += lowbit(x);}
	int query(int x){int s = 0;while(x > 0) s += c[x], x -= lowbit(x);return s;}
}t;

int main(){
	int n,m,q,x,k;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> x;
		t.update(i,x);
	}
	for(int i = 0;i < m;i ++){
		cin >> q >> x >> k;
		switch(q){
			case 1:
				t.update(x,k);
				break;
			case 2:
				cout << t.query(k) - t.query(x - 1) << '\n';
				break;
		}
	}
	return 0;
}
