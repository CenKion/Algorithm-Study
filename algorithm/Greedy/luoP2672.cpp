#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

inline int read(){
	char c = getchar();
	int x = 0,f = 1;
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

const int MAXN = 100005;
int n,sum[MAXN],q[MAXN],h[MAXN];
struct liver{
	int s,a;
}v[MAXN];

bool cmp(liver &A,liver &B){
	return A.a > B.a;
}

int main(){
	n = read();
	for(int i = 1;i <= n;i ++){
		v[i].s = read();
	}
	for(int i = 1;i <= n;i ++){
		v[i].a = read();
	}
	sort(v + 1,v + 1 + n,cmp);
	for(int i = 1;i <= n;i ++){
		sum[i] = sum[i - 1] + v[i].a;
		q[i] = max(q[i - 1],v[i].s);
	}
	for(int i = n;i >= 1;i --){
		h[i] = max(h[i + 1],2 * v[i].s + v[i].a);
	}
	for(int i = 1;i <= n;i ++){
		cout << max(sum[i] + 2* q[i],sum[i - 1] + h[i]) << '\n';
	}
	return 0;
}
