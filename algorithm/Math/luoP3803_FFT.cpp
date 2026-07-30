#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
using namespace std;

const int MAXN = 1 << 22; 
const double Pi = acos(-1.0);

inline int read(){
    char c = getchar();
    int x = 0, f = 1;
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

struct Complex{
    double x, y;
    Complex(double xx = 0, double yy = 0) : x(xx), y(yy) {}
};

Complex operator + (Complex a, Complex b) { return Complex(a.x+b.x, a.y+b.y); }
Complex operator - (Complex a, Complex b) { return Complex(a.x-b.x, a.y-b.y); }
Complex operator * (Complex a, Complex b) { return Complex(a.x*b.x - a.y*b.y, a.x*b.y + a.y*b.x); }

// 迭代 FFT（蝴蝶变换）
void fft(Complex *a, int limit, int type) {
    // 位逆序置换
    for (int i = 0, j = 0; i < limit; i++) {
        if (i < j) swap(a[i], a[j]);
        for (int k = limit >> 1; (j ^= k) < k; k >>= 1);
    }
    // 迭代合并
    for (int len = 2; len <= limit; len <<= 1) {
        double angle = 2.0 * Pi / len * type;
        Complex Wn(cos(angle), sin(angle));
        for (int i = 0; i < limit; i += len) {
            Complex w(1, 0);
            for (int j = 0; j < (len >> 1); j++, w = w * Wn) {
                Complex u = a[i + j];
                Complex v = w * a[i + j + (len >> 1)];
                a[i + j] = u + v;
                a[i + j + (len >> 1)] = u - v;
            }
        }
    }
}

Complex a[MAXN], b[MAXN];

int main() {
    int N = read(), M = read();
    for (int i = 0; i <= N; ++i) a[i].x = read();
    for (int i = 0; i <= M; ++i) b[i].x = read();

    int limit = 1;
    while (limit <= N + M) limit <<= 1;

    fft(a, limit, 1);
    fft(b, limit, 1);
    for (int i = 0; i <= limit; ++i) a[i] = a[i] * b[i];
    fft(a, limit, -1);

    for (int i = 0; i <= N + M; ++i)
        printf("%d ", (int)(a[i].x / limit + 0.5));
    return 0;
}

