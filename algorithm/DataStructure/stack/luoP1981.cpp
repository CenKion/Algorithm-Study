#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

stack <long long> number;
stack <char> operators;
char c;
long long x;

int main(){
	while(cin >> c){
		if(c >= '0' && c <= '9'){
			x = x * 10 + c - '0';
		}
		else if(c == '+' || c == '*'){
			if(!operators.empty() && operators.top() == '*'){
				x = (x * number.top()) % 10000;
				number.pop();
				number.push(x);
				x = 0;
				operators.pop();
				operators.push(c);
			}
			else{
				number.push(x);
				operators.push(c);
				x = 0;
			}
		}
	}
	while(!operators.empty()){
		if(operators.top() == '+'){
			x = (x + number.top()) % 10000;
		}
		else if(operators.top() == '*'){
			x = (x * number.top()) % 10000;
		}
		operators.pop();
		number.pop();
	}
	cout << x % 10000;
	return 0;
}
