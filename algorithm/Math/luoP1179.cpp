#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int L,R,cntL,cntR;

int GetTwo(int x){
	if(x <= 1) return 0;
	int ans = 0;
	for(long long m = 1;m <= x;m *= 10){
		int a = x / m,b = x % m;
		ans += (a + 7) / 10 * m + (a % 10 == 2) * (b + 1);
	}
	return ans;
}

int main(){
	scanf("%d %d",&L,&R);
	cntL = GetTwo(L - 1);
	cntR = GetTwo(R);
	printf("%d",cntR - cntL);
	return 0;
}
