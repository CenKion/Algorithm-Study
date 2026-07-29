#include <iostream>
using namespace std;

int min_height(int a,int b,int c){
	if(a!=c-1){
		return -1;
	}
	int h=0;
	while((1<<h)<c){
		h++;
	}
	int k=(1<<h)-c;
	if(b<=k){
		return h;
	}
	int addition=0;
	while(c*addition<b-k){
		addition++;
	}
	return h+addition;
}

int main(){
	int n,a,b,c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		cout<<min_height(a,b,c)<<'\n';
	}
	return 0;
}

