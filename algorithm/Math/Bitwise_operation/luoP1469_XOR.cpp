#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans,ai,n;

int main(){
	scanf("%d",&n);
    for(int i = 0;i < n;i ++){
        scanf("%d",&ai);
        ans ^= ai;
    }
    cout << ans;
	return 0;
}
