#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int MergeSort(int* arr,int *tmp,int l,int r){
	if(l >= r) return 0;
	int mid = (l + r) >> 1;
	int inv_cnt = MergeSort(arr,tmp,l,mid) + MergeSort(arr,tmp,mid+1,r);
	int i = l,j = mid + 1 ,pos = l;
	while(i <= mid && j <= r){
		if(arr[i] <= arr[j]){
			tmp[pos ++] = arr[i ++];
			inv_cnt += j - 1 - mid;
		}
		else{
			tmp[pos ++] = arr[j ++];
		}
	}
	while(i <= mid){
		tmp[pos++] = arr[i++];
		inv_cnt += r -  mid;
	}
	while(j <= r){
		tmp[pos++] = arr[j++];
	}
	for(int k = l;k <=r;k ++){
		arr[k] = tmp[k];
	}
	return inv_cnt;
}

struct InvString{
	string s;
	int arr[55];
	int invCnt;
};

InvString arrS[105];
int tmp[55];

bool compa(const InvString & is1 ,const InvString & is2){
	return is1.invCnt < is2.invCnt;
}

int main(){
	int n ,m;
	cin >> n >>m;
	for(int i = 0;i < m;i ++){
		cin >> arrS[i].s;
		for(int j = 0;j < n;j++){
			arrS[i].arr[j] = arrS[i].s[j] - 'A';
		}
		arrS[i].invCnt = MergeSort(arrS[i].arr,tmp ,0,n-1);
	}
	sort(arrS,arrS+m,compa);
	for(int i = 0;i < m;i ++){
		cout << arrS[i].s <<'\n';
	}
	return 0;
}
