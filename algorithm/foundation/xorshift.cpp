#include <iostream>
#include <stdio.h>

using namespace std;

unsigned int seed = 123456789;		//全局种子 

inline unsigned int fast_rand(){	//xorshift伪随机数生成 
	seed ^= seed << 13;
	seed ^= seed >> 17;
	seed ^= seed << 5;
	return seed;
}

int l,r;

int main(){
	cin >> l >> r;
	int pos = l + fast_rand() % (r - l + 1);	//l-r之间的随机位置 
	return 0;
}
