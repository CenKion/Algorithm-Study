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

struct point{
	int val,num;
}a[MAXN];

bool cmp(point &x,point &y){
	if(x.val != y.val) return x.val < y.val;
	return x.num < y.num;
}


int n,record[MAXN];
long long ans;

int main(){
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i].val;
		a[i].num = i;
	}
	sort(a + 1,a + 1 + n,cmp);
	for(int i = 1;i <= n;i ++){
		record[a[i].num] = i;
	}
	for(int i = 1;i <= n;i ++){
		t.update(record[i],1);
		ans += i - t.query(record[i]);
	}
	cout << ans;
	return 0;
}
