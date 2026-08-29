#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXY = 3 * 1e6 + 5;
const int MAXN = 1.5 * 1e5 + 5;
int n,maxY,dp[MAXY],ans;

struct Node{
	int left,right;
	bool operator < (const Node& b) const{
		return right < b.right;
	}
}nodes[MAXN];

struct BIT{
	int c[MAXY];
	int lowbit(int x){
		return x & -x;
	}
	public:
	void update(int pos,int k){
		while(pos <= maxY){
			c[pos] = max(c[pos],k);
			pos += lowbit(pos);
		}
	}
	
	int query(int pos){
		int result = 0;
		while(pos > 0){
			result = max(result,c[pos]);
			pos -= lowbit(pos);
		}
		return result;
	}
}t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> nodes[i].left >> nodes[i].right;
		nodes[i].left ++;
		nodes[i].right ++;
		maxY = max(maxY,nodes[i].right);
	}
	sort(nodes + 1,nodes + 1 + n);
	for(int i = 1;i <= n;i ++){
		int tmpx = nodes[i].left,tmpy = nodes[i].right;
		int tmp = t.query(tmpx - 1) + tmpy - tmpx + 1;
		if(dp[tmpy] < tmp){
			dp[tmpy] = tmp;
			t.update(tmpy,tmp);
			ans = max(ans,tmp);
		}
	}
	cout << ans;
	return 0;
}

