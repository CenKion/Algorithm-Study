#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int N,a[100005];

void InsertionSort(int* a,int l,int r){		//插入排序，减少递归深度。 
	for(int i = l + 1;i <= r;i ++){
		int key = a[i],j = i - 1;
		while(j >= l && a[j] > key){
			a[j + 1] = a[j];
			j --;
		}
		a[j + 1] = key;
	}
}

int medianOfThree(int *a,int l,int r){		//三数取中 
	int mid = l + (r - l) / 2;
	if(a[l] > a[mid]) swap(a[l],a[mid]);
	if(a[l] > a[r]) swap(a[l],a[r]);
	if(a[mid] > a[r]) swap(a[l],a[r]);
	swap(a[mid],a[r]);
	return a[r];
}

void QuickSort(int* a,int l,int r){
	if(l >= r) return;
	if(r - l + 1 <= 16){
		InsertionSort(a,l,r);
		return;
	}
	int x = medianOfThree(a,l,r);
	int i = l,lt = l, gt = r;	//三路划分 
	while(i <= gt){
		if(a[i] < x){			//[l,lt-1]满足a[i] < x 
			swap(a[i],a[lt]);
			lt ++;
			i ++;
		}
		else if(a[i] > x){		//[gt + 1,r]满足a[i] > x 
			swap(a[i],a[gt]);
			gt--;
		}
		else i++;
	}
	QuickSort(a,l,lt - 1);
	QuickSort(a,gt + 1,r);
}

int main(){
	scanf("%d",&N);
	for(int i = 1;i <= N;i ++){
		scanf("%d",&a[i]);
	}
	QuickSort(a,1,N);
	for(int i = 1;i < N;i ++){
		printf("%d ",a[i]);
	}
	printf("%d",a[N]);
	return 0;
}
