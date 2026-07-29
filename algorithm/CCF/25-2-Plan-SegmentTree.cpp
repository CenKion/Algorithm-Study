#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

struct Node{
	int l;
	int r;
	int mid;
	int lazy;
	Node* left;
	Node* right;
	
	Node(int L,int R){
		l = L;
		r = R;
		mid = (l + r) >> 1;
		lazy = 0;
		if(L >= R){
			left = nullptr;
			right = nullptr;
		}
		else{
			left =new Node(L,mid);
			right = new Node(mid + 1,R);
		}
	}
	
	int find(int x){
		if(left == nullptr && right == nullptr) return lazy;
		if(left != nullptr) left->lazy += lazy;
		if(right != nullptr) right->lazy += lazy;
		lazy = 0;
		if(x <= mid) return left->find(x);
		return right->find(x);
	}
	
	void add(int L,int R){
		if(L <= l && R >= r){
			lazy ++;
			return;
		}
		if(left != nullptr) left->lazy += lazy;
		if(right != nullptr) right->lazy += lazy;
		lazy = 0;
		if(L <= mid && R > mid){
			left->add(L,mid);
			right->add(mid + 1,R);
			return;
		}
		if(R <= mid){
			left->add(L,R);
			return;
		}
		if(L > mid){
			right->add(L,R);
			return;
		}
	}
	
	
};

int main(){
	Node tree(0,200000);
	int n,m,k;
	cin >> n >> m >> k;
	int t ,c ,tmpL,tmpR;
	for(int i = 0;i < n;i ++){
		cin >> t >> c;
		tmpL = (t - c + 1 >= 0)?(t - c + 1):0;
		tmpR = t;
		tree.add(tmpL,tmpR);
	}
	int q;
	for(int i = 0;i < m;i ++){
		cin >> q;
        if(q + k>200000){
            cout<<0<<'\n';
            continue;
        }
		cout << tree.find(q + k) << '\n';
	}
	return 0;
}
