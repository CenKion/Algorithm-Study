#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

int main(){
	cout<<fixed<<setprecision(5)<<20.0/3<<'\n';//浮点数五位
	printf("%-6.3lf,%4.3lf\n",20.0/3,20.0/3); //左对齐6位，右对齐4位
	printf("%05d\n",4);		//右对齐5位，补0
	
	string st="123456";
	stringstream ss(st);
	int num;
	ss>>num;
	cout<<num<<'\n';
	
	string st2;
	int num2=456789;
	stringstream ss2;
	ss2<<num2;
	st2=ss2.str();
	cout<<st2<<'\n';
	
	
	return 0;
}
