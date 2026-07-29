#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(long long x,int* s,int m,int n){
	long long int tmp=0;
    int cnt=1;
	for(int i=0;i<n;i++){
		if(tmp+s[i]>x){
			cnt++;
			tmp=s[i];
			if(cnt>m){
				return false;
			}
		}
		else{
			tmp+=s[i];
		}
	}
	return true;
}

int main() {
	int n,m;
	long long int total=0,left=0,right,mid;
	cin>>n>>m;
	int* sequence= new int[n];
	for(int i=0;i<n;i++){
		cin>>sequence[i];
		total+=sequence[i];
		if(left<sequence[i]){
			left=sequence[i];
		} 
	}
	right=total;
	while(left<right){
		mid=(left+right)/2;
		if(check(mid,sequence,m,n)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	cout<<left;
    return 0;
}
