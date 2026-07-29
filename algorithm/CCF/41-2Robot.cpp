#include <iostream>
#include <stdio.h>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

struct task{
	double t;
	double a;
	double b;
	double efficiency;
};

string trimDouble(double val){
	ostringstream oss;
	oss << fixed << setprecision(6) <<val;
	string s = oss.str();
	
	while(!s.empty() && s.back() == '0'){
		s.pop_back();
	}
	if(s.back() == '.'){
		s = s + "0";
	}
	return s;
}

void QuickSortEff(task* arr,int l,int r){
	if(l >= r) return;
	task x = arr[r];
	int i = l;
	for(int j = l;j < r;j ++){
		if(arr[j].efficiency > x.efficiency){
			swap(arr[i],arr[j]);
			i++;
		}
	}
	arr[r] = arr[i];
	arr[i] = x;
	QuickSortEff(arr,l ,i -1);
	QuickSortEff(arr,i+1 ,r);
}

double dp[1005];
task Flex[205];
task Normal[205];
int main(){
	int n ,m ,FC = 0,NC = 0;
	double SumFa = 0 ,SumTime = 0;
	double rest = 0,tmpSum = 0;
	int flag = 0;
	cin >> n >> m;
	short int type;
	for(int i = 0;i < n;i ++){
		cin >> type;
		if(type == 0){
			cin >> Flex[FC].t >> Flex[FC].a >> Flex[FC].b;
			SumTime += Flex[FC].t;
			Flex[FC].efficiency = Flex[FC].b / Flex[FC].a;
			SumFa += Flex[FC].a;
			FC++;
		}
		else{
			cin >> Normal[NC].t >> Normal[NC].a >> Normal[NC].b;
			SumTime += Normal[NC].t;
			NC++;
		}
	}
	if(FC > 0){
		QuickSortEff(Flex,0,FC-1);
		while(flag < FC && tmpSum < 1){
			if(tmpSum + Flex[flag].a < 1){
				tmpSum += Flex[flag].a;
				dp[1] += Flex[flag].b;
				flag++;
			}
			else if(tmpSum + Flex[flag].a == 1){
				tmpSum += Flex[flag].a;
				dp[1] += Flex[flag].b;
				flag++;
				if(flag < FC) rest = Flex[flag].a;
				else rest = 0;
			}
			else{
				rest = Flex[flag].a - 1 + tmpSum;
				dp[1] += (1 - tmpSum)/Flex[flag].a * Flex[flag].b;
				break;
			}
		}
		for(int i = 2;i <= m;i ++){
			if(flag == FC){
				dp[i] = dp[i - 1];
			}
			else{
				if(rest > 1){
					dp[i] = dp[i - 1] + 1/Flex[flag].a * Flex[flag].b;
					rest -= 1;
				}
				else if(rest == 1){
					dp[i] = dp[i - 1] + 1/Flex[flag].a * Flex[flag].b;
					flag ++;
					if(flag < FC) rest = Flex[flag].a;
					else rest = 0;
				}
				else{
					dp[i] = dp[i-1] + rest/Flex[flag].a * Flex[flag].b;
					double gap = 1 - rest;
					flag++;
					rest = Flex[flag].a;
					while(flag < FC && gap > 0){
						if(rest > gap){
							dp[i] += gap/Flex[flag].a * Flex[flag].b;
							rest -= gap;
						}
						else if(rest == gap){
							dp[i] += rest/Flex[flag].a * Flex[flag].b;
							flag ++;
							if(flag < FC) rest = Flex[flag].a;
							else rest = 0;
						}
						else{
							gap -=rest;
							dp[i] += rest/Flex[flag].a * Flex[flag].b;
							flag ++;
							if(flag < FC) rest = Flex[flag].a;
							else rest = 0;
						}
					}
				}
			}
		}
	}
	if(NC > 0){
		for(int i = 0;i < NC;i ++){
			for(int j = m;j >= Normal[i].a;j --){
				if(dp[j - (int)Normal[i].a] + Normal[i].b > dp[j]){
					dp[j] = dp[j - (int)Normal[i].a] + Normal[i].b;
				}
			}
		}
	}
	cout << trimDouble(SumTime - dp[m]);
	
	return 0;
}



