#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

const int MAXN = 1e6 +5;
ll n,m,q,x,y,k,a[MAXN],tree[MAXN << 1],lazy[MAXN << 1];

inline ll ls(ll x){
	return x << 1;
}

inline ll rs(ll x){
	return x << 1 | 1;
}

inline void push_up(ll p){
	tree[p] = tree[ls(p)] + tree[rs(p)];
}

void build(ll p,ll l,ll r){
	lazy[p] = 0;
	if(l == r){
		tree[p] = a[l];
		return;
	}
	ll mid = (l + r) >> 1;
	build(ls(p),l,mid);
	build(rs(p),mid + 1,r);
	push_up(p);
}

inline void push_lazy(ll p,ll l,ll r,ll k){
	tree[p] += (r - l + 1) * k;
	lazy[p] += k;
}

inline void push_down(ll p,ll l,ll r){
	ll mid = (l + r) >> 1;
	push_lazy(ls(p),l,mid,lazy[p]);
	push_lazy(rs(p),mid + 1,r,lazy[p]);
	lazy[p] = 0;
}

inline void update(ll nl,ll nr,ll l,ll r,ll p,ll k){
	if(nl <= l && nr >= r){
		tree[p] += (r - l + 1) * k;
		lazy[p] += k;
		return;
	}
	push_down(p,l,r);
	ll mid = (l + r) >> 1;
	if(nl <= mid) update(nl,nr,l,mid,ls(p),k);
	if(nr > mid) update(nl,nr,mid + 1,r,rs(p),k);
	push_up(p);
}

ll query(ll x,ll y,ll l,ll r,ll p){
	if(x <= l && y >= r) return tree[p];
	ll res = 0,mid = (l + r) >> 1;
	push_down(p,l,r);
	if(x <= mid) res += query(x,y,l,mid,ls(p));
	if(y > mid) res += query(x,y,mid + 1,r,rs(p));
	return res;
}

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	build(1,1,n);
	for(int i = 1;i <= m;i ++){
		cin >> q;
		if(q == 1){
			cin >> x >> y >> k;
			update(x,y,1,n,1,k);
		}
		else{
			cin >> x >> y;
			cout << query(x,y,1,n,1) << '\n';
		}
	}
	return 0;
}
