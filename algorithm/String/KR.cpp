#include <iostream>
#include <cmath>
#define mod 1000000007
using namespace std;


int main() {
    string s,p;
    cin>>s>>p;		//s为主串,p为模式串		
    int n=s.length(),m=p.length();		//s,p的长度 
    int Hash_t=0,Hash_p=0;
    for(int i=0;i<m;i++){
    	Hash_p+=(p[i]-'a')*((int)pow(26,m-1-i)%mod)%mod;	//p的哈希值 
	}
	for(int i=0;i<m;i++){
    	Hash_t+=(s[i]-'a')*((int)pow(26,m-1-i)%mod)%mod;	//截取部分t的哈希值 
	}
	int f=0,loc=0;		//f标记是否找到,loc记录位置 
	for(int i=0;i<n-m+1;i++){
		if(Hash_t==Hash_p){		//哈希值相等 
			f=1;		//先记为1表示找到，后续比对不符则改回0 
			for(int j=0;j<m;j++){		//逐位比对 
				if(s[loc+j]!=p[j]){
					f=0;
				}
			}
		}
		if(f){
			break;
		}
		else if(loc<n-m){	//还有下一位，则更新Hash_t 
			Hash_t=(Hash_t-(s[loc]-'a')*((int)pow(26,m-1)%mod))%mod;	//删除头字符 
			Hash_t=Hash_t*26%mod;		//窗口右移 
			Hash_t=(Hash_t+(s[loc+m]-'a'))%mod;		//加入新字符 
			loc++;		//位置+1 
		}
	}
	if(f){
		cout<<"首字符位置在："<<loc;
	}
	else{
		cout<<"未查找到子串";
	}
    return 0;
}
