#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int d[30];
int arr[30];

int BinarySearch(int *a,int x,int l,int r){
	if(l >= r) return l;
	int mid = (l + r) >> 1;
	if(a[mid] < x) r = mid;
	else l = mid + 1;
	return BinarySearch(a,x,l,r);
}

int main(){
	int k;
	int maxLen = 1,pos;
	cin >> k;
	for(int i = 0;i < k;i ++){
		cin >> arr[i];
		if(i == 0) d[1] = arr[0];
		else if(arr[i] <= d[maxLen]){
			maxLen ++;
			d[maxLen] = arr[i];
		}
		else{
			pos = BinarySearch(d,arr[i],1,maxLen);
			d[pos] = arr[i];
		}
	}
	cout << maxLen;
	return 0;
}

