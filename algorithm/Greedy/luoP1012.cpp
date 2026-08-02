#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(string A,string B){
    return A + B > B + A;
}

string arr[25];

int main(){
	int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++){
        cin >> arr[i];
    }
    sort(arr + 1,arr + n + 1,cmp);
    string s;
    for(int i = 1;i <= n;i ++){
        s += arr[i];
    }
    cout << s;
	return 0;
}
