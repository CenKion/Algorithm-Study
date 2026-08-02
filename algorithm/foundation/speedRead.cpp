#include <stdio.h>
#define mxsz 1<<22

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

struct IO {
	char buf[mxsz], * p1, * p2;
	IO() : p1(buf), p2(buf) {}
	inline char gc() {
		if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, mxsz, stdin);
		return p1 == p2 ? ' ' : *p1++;
	}
	inline int read() {
		int r = 0; char c = gc(); bool rev = 0;
		while (c < '0' || c>'9') rev |= (c == '-'), c = gc();
		while (c >= '0' && c <= '9') r = r * 10 + (c ^ 48), c = gc();
		return rev ? ~r + 1 : r;
	}
} io;

int main(){
	int a = read(), b = read();
	printf("%d , %d", a, b);
	a = io.read(),b = io.read(); 
	return 0;
}
