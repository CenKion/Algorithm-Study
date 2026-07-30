#include <iostream>
#include <sstream> 
#include <string>
using namespace std;

int main() {
	// std::to_string 数字转字符串 
	int num=123;
	string str = to_string(num);
	cout << str << '\n';
	
	// std::stoi 字符串转数字
	string str2 = "456";
	int num2 = stoi(str2);
	cout << num2 <<'\n';
	
	// stringstream 数字转字符串
	int num3 = 123;
	stringstream ss;
	ss << num;		// 将num写入stringstream
	string str3 = ss.str();		//获取字符串表示
	cout << str3 <<'\n';
	
	// stringstream 字符串转数字
	string str4 = "789";
	int num4;
	stringstream ss2(str4);
	ss2 >> num4;	//stringstream读取数字到num变量
	cout << num4 <<'\n'; 
	
    return 0;
}
