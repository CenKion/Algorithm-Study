#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

int main() {
	int n;
	double c;
	cin >> n >> c;
	cout << right << setw(8) << setfill('0') << n <<'\n';
	//printf("%08d\n" ,n);
	//cout << fixed << setprecision(2) << c <<'\n';
	printf("%.2lf", c);
    return 0;
}
