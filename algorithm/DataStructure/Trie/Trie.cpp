#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int getNum(char c){
	if(c >= 'a' && c <='z') return (c - 'a');
	if(c >= 'A' && c <='Z') return (c - 'A' + 26);
	if(c >= '0' && c <='9') return (c - '0' + 52);
}

//未实现深拷贝 

struct Node{
	Node* sons[62];		//小写字母+大写字母+数字 
	int end;
	int pass;
	
	Node(){
		memset(sons,0,62*sizeof(Node*));
		end = 0;
		pass = 0;
	}
	
	~Node(){
		for(int i = 0;i < 62;i ++){
			delete sons[i];
		}
	}
};

struct Trie{
	Node *root;
	
	Trie(){
		root = new Node;
	}
	
	void insert(string s){			//插入 
		Node* cur=root;
		char c;
		int l = s.length(),pos;
		for(int i = 0;i < l;i ++){
			c = s[i];
			pos = getNum(c);
			if(!cur->sons[pos]){
				cur->sons[pos] = new Node;
			}
			cur = cur->sons[pos];
			cur->pass++;
			if(i == l - 1){
				cur->end++;
			}
		}
	}
	
	int count(string s){		//词频 
		Node* cur=root;
		char c;
		int l = s.length(),pos;
		for(int i = 0;i < l;i ++){
			c = s[i];
			pos = getNum(c);
			if(!cur->sons[pos]){
				return 0;
			}
			cur = cur->sons[pos];
			if(i == l - 1){
				return cur->end;
			}
		}
	}
	
	int countPrefix(string s){	//以s为前缀的词频 
		Node* cur=root;
		char c;
		int l = s.length(),pos;
		for(int i = 0;i < l;i ++){
			c = s[i];
			pos = getNum(c);
			if(!cur->sons[pos]){
				return 0;
			}
			cur = cur->sons[pos];
			if(i == l - 1){
				return cur->pass;
			}
		}
	}
	
	~Trie(){
		delete root;
	}
};

int main(){
	int T ,n ,q;
	string s;
	cin >> T;
	while(T --){
		cin >> n >> q;
		Trie tree;
		for(int i = 0;i < n;i ++){
			cin >> s;
			tree.insert(s);
		}
		for(int i = 0;i < q;i ++){
			cin >> s;
			cout << tree.countPrefix(s)<<'\n';
		}
	}
	return 0;
}
