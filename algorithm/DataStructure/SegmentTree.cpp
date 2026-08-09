#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
const int MAXN = 100005;

int n, M;
ll P;
ll a[MAXN];

struct SegTree {
    ll sum, add, mul;
} tree[MAXN * 4];

void build(int rt, int l, int r) {
    tree[rt].add = 0;
    tree[rt].mul = 1;
    if (l == r) {
        tree[rt].sum = a[l] % P;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    tree[rt].sum = (tree[rt << 1].sum + tree[rt << 1 | 1].sum) % P;
}

void push_down(int rt, int l, int r) {
    int mid = (l + r) >> 1;
    int ls = rt << 1, rs = rt << 1 | 1;
    ll &mul = tree[rt].mul, &add = tree[rt].add;

    tree[ls].sum = (tree[ls].sum * mul + add * (mid - l + 1)) % P;
    tree[ls].mul = (tree[ls].mul * mul) % P;
    tree[ls].add = (tree[ls].add * mul + add) % P;

    tree[rs].sum = (tree[rs].sum * mul + add * (r - mid)) % P;
    tree[rs].mul = (tree[rs].mul * mul) % P;
    tree[rs].add = (tree[rs].add * mul + add) % P;

    mul = 1;
    add = 0;
}

void update_mul(int rt, int l, int r, int ql, int qr, ll c) {
    if (ql <= l && r <= qr) {
        tree[rt].sum = tree[rt].sum * c % P;
        tree[rt].mul = tree[rt].mul * c % P;
        tree[rt].add = tree[rt].add * c % P;
        return;
    }
    push_down(rt, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid) update_mul(rt << 1, l, mid, ql, qr, c);
    if (qr > mid)  update_mul(rt << 1 | 1, mid + 1, r, ql, qr, c);
    tree[rt].sum = (tree[rt << 1].sum + tree[rt << 1 | 1].sum) % P;
}

void update_add(int rt, int l, int r, int ql, int qr, ll c) {
    if (ql <= l && r <= qr) {
        tree[rt].sum = (tree[rt].sum + c * (r - l + 1)) % P;
        tree[rt].add = (tree[rt].add + c) % P;
        return;
    }
    push_down(rt, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid) update_add(rt << 1, l, mid, ql, qr, c);
    if (qr > mid)  update_add(rt << 1 | 1, mid + 1, r, ql, qr, c);
    tree[rt].sum = (tree[rt << 1].sum + tree[rt << 1 | 1].sum) % P;
}

ll query(int rt, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[rt].sum;
    }
    push_down(rt, l, r);
    int mid = (l + r) >> 1;
    ll res = 0;
    if (ql <= mid) res = (res + query(rt << 1, l, mid, ql, qr)) % P;
    if (qr > mid)  res = (res + query(rt << 1 | 1, mid + 1, r, ql, qr)) % P;
    return res;
}

int main() {
    scanf("%d %lld", &n, &P);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    build(1, 1, n);
    scanf("%d", &M);
    while (M--) {
        int op, t, g;
        ll c;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d %lld", &t, &g, &c);
            update_mul(1, 1, n, t, g, c % P);
        } else if (op == 2) {
            scanf("%d %d %lld", &t, &g, &c);
            update_add(1, 1, n, t, g, c % P);
        } else {
            scanf("%d %d", &t, &g);
            printf("%lld\n", query(1, 1, n, t, g));
        }
    }
    return 0;
}
    
