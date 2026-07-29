#include <stdio.h>

using namespace std;

const int BUFSIZE = 1<<21;
char buf[BUFSIZE], *p1 = buf , *p2 = buf;

#define getchar()(p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, BUFSIZE, stdin) ,p1 == p2) ? EOF : *p1++)

inline int read(){
	int x = 0, f = 1;
	char c = getchar();
	while(c < '0'|| c > '9'){
		if(c == '-'){
			f = -1;
		}
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x * f;
}

int main(){
	int a = read(), b = read();
	printf("%d , %d", a, b);
	
	return 0;
}
