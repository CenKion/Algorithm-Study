#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int iter=0;
queue <char> Q;

void getPostOrder(char* pre, int preL, int preR,
                  char* in, int inL, int inR,
                  map<char, int>& inMap) {
    if (preL > preR) return;
    char rootVal = pre[preL];
    int rootPos = inMap[rootVal];
    int leftSize = rootPos - inL;
    // 左子树
    getPostOrder(pre, preL + 1, preL + leftSize,
                 in, inL, rootPos - 1, inMap);
    // 右子树
    getPostOrder(pre, preL + leftSize + 1, preR,
                 in, rootPos + 1, inR, inMap);
    // 后序：最后输出根
    cout<<rootVal;
}
char t[100];
char s[100];

int main() {
	int n;
	while(cin>>n&&cin>>t&&cin>>s){
		int slen=strlen(s);
		map <char,int> dict;
		for(int i=0;i<slen;i++){
			dict[s[i]]=i;
		}
		getPostOrder(t,0,slen-1,s,0,slen-1,dict);
		cout<<'\n'; 
	}
    return 0;
}
