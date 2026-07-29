/*小学期，同学们正在紧锣密鼓地备考九月的CCF-CSP考试，过程中需要大量的题目练习。有的同学做得又快又好，这能极大地激励其他同学。

假设有同学甲和同学乙，如果甲的做题时间小于等于乙的做题时间，并且甲的题目得分大于等于乙的题目得分，那么我们称乙受甲激励（如甲乙的做题时间和题目得分都相同则甲乙都不能受到激励）。一位同学可以被多位同学激励，也可以激励多位同学。

而这其中就可能有部分大佬是不受激励影响的人。现在我们提供了每位同学做题的时间和得分，请编写一个程序，按照升序输出所有未受激励影响的大佬的id。


【输入形式】

测试数据共 n + 1 行。

第一行输入一个正整数n

接下来n行每行两个正整数题ti、si，表示第i位同学做题的时间与得分，第i位同学的id即为i。

对于70% 的测试数据 1 ≤ n ≤ 1,000

对于100% 的测试数据 1 ≤ n ≤ 1,000,000, 1 ≤ ti ≤ 240, 1 ≤ si ≤ 500


【输出形式】

对于每组测试数据，输出若干行

按照id从小到大依次输出未受激励影响的同学的id，每行仅一个id*/

#include <cstdio>
#include <vector>
using namespace std;

const int MAXT = 240;

int best[MAXT + 1];
int pre[MAXT + 1];


int main() {
    int n;
    scanf("%d",&n);
    vector <int> t(n) , s(n);
    for(int i = 0;i < n;i ++){
    	scanf("%d %d",&t[i] ,&s[i]);
    	if(s[i] > best[t[i]]){
    		best[t[i]] = s[i];
		}
	}
	int cur = 0;
	for(int i = 1;i <= MAXT;i ++){
		pre[i] = cur;
		cur = max(pre[i] , best[i]);
	}
	for(int i = 0;i < n;i ++){
		if(pre[t[i]] < s[i] && best[t[i]] <= s[i]){
			printf("%d\n",i + 1);
		}
	}
    return 0;
}
