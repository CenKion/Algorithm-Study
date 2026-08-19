#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

const int mod = 1e8 - 3;
const int MAXN = 1e5 + 5;

int n;
long long ans;

struct BIT{
	int c[MAXN];
	
	int lowbit(int x){
		return x & -x;
	}
	
	void update(int pos,int k){
		while(pos < MAXN){
			c[pos] = (c[pos] + k) % mod;
			pos += lowbit(pos);
		}
	}
	
	int query(int pos){
		int res = 0;
		while(pos > 0){
			res = (res + c[pos]) % mod;
			pos -= lowbit(pos);
		}
		return res;
	}
}t;

struct match{
	int h,num;
}a[MAXN],b[MAXN];

int reflec[MAXN];

bool cmp(match &x,match &y){
	return x.h < y.h;
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i].h;
		a[i].num = i;
    }
    for(int i = 1;i <= n;i ++){
        cin >> b[i].h;
        b[i].num = i;
    }
	sort(a + 1,a + 1 + n,cmp);
	sort(b + 1,b + 1 + n,cmp);
	for(int i = 1;i <= n;i ++){
		reflec[a[i].num] = b[i].num;
	}
	for(int i = 1;i <= n;i ++){
		t.update(reflec[i],1);
		ans = (ans + i - t.query(reflec[i])) % mod;
	}
	cout << ans;
	return 0;
}

