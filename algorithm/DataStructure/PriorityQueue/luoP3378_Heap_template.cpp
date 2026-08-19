#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

const int MAXN = 1e6 + 5;

struct heap{
	int a[MAXN];
	int size;
	
	void sift_down(int pos){
		int child;
		while((pos << 1) <= size){
			child = pos << 1;
			if(child + 1 <= size && a[child + 1] < a[child]) child ++;
			if(a[child] > a[pos]) return;
			swap(a[child],a[pos]);
			pos = child;
		}
	}
	
	void sift_up(int pos){
		while(pos > 1){
			int parent = pos >> 1;
			if(a[pos] >= a[parent]) return;
			swap(a[pos],a[parent]);
			pos >>= 1;
		}
	}
	
	void add(int x){
		a[++size] = x;
		sift_up(size);
	}
	
	void del(){
		if(size == 0) return;
		swap(a[1],a[size]);
		size --;
		if(size > 0) sift_down(1);
	}
}h;

int n,op,x;

int main(){
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> op;
		if(op == 1){
			cin >> x;
			h.add(x);
		}
		else if(op == 2){
			cout << h.a[1] << '\n';
		}
		else{
			h.del();
		}
	}
	return 0;
}

