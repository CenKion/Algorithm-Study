#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAXN = 200005;
const double INF = 1e18;
int n,tmp[MAXN];

struct Point{
	double x,y;
}S[MAXN];

bool cmp(Point &A,Point &B){
	if(A.x != B.x) return A.x < B.x;
	return A.y < B.y;
}

bool cmps(int a,int b){
	return S[a].y < S[b].y;
}

double getMin(double a,double b){
	return (a > b)?b:a;
}

double distance2(Point a,Point b){
	double dx = b.x - a.x;
	double dy = b.y - a.y;
	return sqrt(dx*dx + dy*dy);
}

double merge(int left,int right){
	double d = INF;
	if(left >= right) return d;
	if(left + 1 == right) return distance2(S[left],S[right]);
	int mid = left + ((right - left) >> 1);
	double d1 = merge(left,mid);
	double d2 = merge(mid + 1,right);
	d = getMin(d1,d2);
	int k = 0;
	for(int i = left;i <= right;i ++){
		if(fabs(S[i].x - S[mid].x) <= d) tmp[++ k] = i;
		else if(S[i].x - S[mid].x > d) break;
	}
	sort(tmp + 1,tmp + k + 1,cmps);
	for(int i = 1;i <= k;i ++){
		for(int j = i + 1;j <= k && S[tmp[j]].y - S[tmp[i]].y <= d;j ++){
			double d3 = distance2(S[tmp[i]],S[tmp[j]]);
			if(d3 < d) d = d3;
		}
	}
	return d;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> S[i].x >> S[i].y;
	}
	sort(S + 1,S + n + 1,cmp);
	cout << fixed << setprecision(4) << merge(1,n);
	return 0;
}
