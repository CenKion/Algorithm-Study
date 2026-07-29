#include <iostream>
#include <stdio.h>
#include <map>
#include <iomanip>
#include <random>

using namespace std;

void QuickSort1(int l, int r, int *arr) {
    if (l >= r) {
        return;
    }

    int x = arr[r];      // 基准值（最右元素）
    int i = l, j = r - 1; // 左指针 l，右指针 r-1（跳过基准）
    int tmp;

    while (i < j) {
        // 从左向右找第一个 >= x 的元素
        while (i < j && arr[i] < x) i++;
        // 从右向左找第一个 <= x 的元素
        while (i < j && arr[j] > x) j--;

        // 只有 i < j 时才交换（防止交叉后错换）
        if (i < j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            // ? 关键修复：交换后双指针向中间收缩，避免死循环
            i++;
            j--;
        }
    }

    // 将基准值放到正确位置（此时 i 是分界点）
    arr[r] = arr[i];
    arr[i] = x;

    // 递归排序左右两侧
    QuickSort1(l, i - 1, arr);
    // ? 关键修复：右半区起始应为 i+1，排除基准
    QuickSort1(i + 1, r, arr);
}

void QuickSort2(int l, int r, int *arr) {
    if (l >= r) {
        return;
    }
    int x = arr[r];
    int i = l;
    for(int j = l;j < r;j ++){
    	if(arr[j] < x){
    		swap(arr[i],arr[j]);
    		i ++;
		}
	}
    arr[r] = arr[i];
    arr[i] = x;
    QuickSort2(l, i - 1, arr);		//跳过基准值！！！不然个数为2个时会死循环 
    QuickSort2(i + 1, r, arr);
}

int arr[100];

int main() {
	int randomNum;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution <int> dist (1,100);
	
	for(int i = 0;i < 20;i ++){
		randomNum = dist(gen);
		arr[i] = randomNum;
		cout<<arr[i]<<' ';
	}
	cout <<'\n';
	QuickSort2(0 , 19 , arr);
	for(int i = 0;i < 20;i ++){
		cout << arr[i] << ' ';
	}
	
    return 0;
}
