#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

stack <int> operand;
char c;
int x;

int result(char f,int a,int b){
	if(f == '+') return a + b;
	if(f == '-') return a - b;
	if(f == '*') return a * b;
	if(f == '/') return a / b;
}

int main(){
	while(cin >> c && c != '@'){
		if(c >= '0' && c <= '9') x = x * 10 + c - '0';
		else if(c == '.'){
			operand.push(x);
			x = 0;
		}
		else if(c == '+' || c == '-' || c == '*' || c == '/'){
			int a,b;
			b = operand.top();
			operand.pop();
			a = operand.top();
			operand.pop();
			operand.push(result(c,a,b));
		}
	}
	cout << operand.top();
	return 0;
}
