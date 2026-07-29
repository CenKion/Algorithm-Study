#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int N = 5e5 + 5;
int a[N];
struct BIT{
	int c[N];
	int lowbit(int x){
		return x & -x;
	}
	void update(int x,int k){
		while(x < N){
			c[x] += k;
			x += lowbit(x);
		}
	}
	
	int query(int x){
		int s = 0;
		while(x > 0){
			s += c[x];
			x -= lowbit(x);
		}
		return s;
	}
}t;		//一定注意，初始得把c置为全0！！！放在int main里面就写 BIT t{}; 

int n,m,q,x,y,k;
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		t.update(i,a[i] - a[i - 1]);
	}
	for(int i = 0;i < m;i ++){
		cin >> q;
		switch(q){
			case 1:
				cin >> x >> y >>k;
				t.update(x,k);
				t.update(y + 1,-k);
				break;
			case 2:
				cin >> x;
				cout << t.query(x) << '\n';
				break;
		}
	}
	return 0;
}
