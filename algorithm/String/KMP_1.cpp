#include <iostream>
#include <string>
using namespace std;
 
int main() {
	string s,t;
	cin>>s>>t;
	int n=s.length(),m=t.length();
	int* next=new int[m+1];
	next[0]=-1;
	int i=0,j=-1;
	while(i<m){
		if(j==-1||t[i]==t[j]){
			next[++i]=++j;
		}
		else{
			j=next[j];
		}
	}
	i=0;
	j=0;
	while(i+m<=n){
		while(j<m&&s[i+j]==t[j]){
			j++;
		}
		if(j==m){
			cout<<i+1<<'\n';
		}
		i+=(next[j]>0)?j-next[j]:1;
		j=(next[j]<0)?0:next[j];
	}
	for(i=1;i<m+1;i++){
		cout<<next[i]<<' ';
	}
    return 0;
}
