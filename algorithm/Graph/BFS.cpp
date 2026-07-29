#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

struct loc{
	int x;
	int y;
	int step;
};


int main(){
	int m,n;
	cin>>m>>n;
	vector<vector<int>> maze(m,vector<int> (n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>maze[i][j];
		}
	}
	int dx[4]={0,0,1,-1};
	int dy[4]={1,-1,0,0};
	queue <loc> q;
	q.push({0,0,1});
	bool found=false;
	int result;
	while(!q.empty()){
		loc cur=q.front();
		q.pop();
		if(cur.x==m-1&&cur.y==n-1){
			result=cur.step;
			found=true;
			break;
		}
		for(int i=0;i<4;i++){
			int nx=cur.x+dx[i];
			int ny=cur.y+dy[i];
			if(nx>=0&&nx<m&&ny>=0&&ny<n&&maze[nx][ny]==0){
				maze[nx][ny]=cur.step+1;
				q.push({nx,ny,cur.step+1});
			}
		}
	}
	if(found){
		cout<<result;
	}
	else{
		cout<<"没有通路";
	}
	return 0;
} 
