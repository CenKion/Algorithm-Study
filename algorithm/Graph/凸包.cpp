#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point{
	int x;
	int y;
	Point(){};
	Point(int x,int y):x(x),y(y){}
	bool operator==(const Point&b){
		return x==b.x && y==b.y;
	}
};

bool compa_xy(const Point& a,const Point& b){
	if(a.x!=b.x){
		return a.x<b.x;
	}
	return a.y<b.y;
}

int cross(const Point &a,const Point& b,const Point& c){
	return (b.x-a.x)*(c.y-b.y)-(c.x-b.x)*(b.y-a.y);
}

bool collinear(const Point &a,const Point& b,const Point& c){
	return cross(a,b,c)==0;
}

vector <Point> convex(vector<Point> &pts){
	int n=pts.size();
	if(n<=2){
		return pts;
	}
	sort(pts.begin(),pts.end(),compa_xy);
	vector<Point> hull;
	for(int i=0;i<n;i++){
		while(hull.size()>=2&&cross(hull[hull.size()-2],hull.back(),pts[i])<=0){
			hull.pop_back();
		}
		hull.push_back(pts[i]);
	}
	int lowes=hull.size();
	for(int i=n-2;i>=0;i--){
		while(hull.size()>lowes&&cross(hull[hull.size()-2],hull.back(),pts[i])<=0){
			hull.pop_back();
		}
		hull.push_back(pts[i]);
	}
	hull.pop_back();
	return hull;
}

int main() {
    int n;
    cin>>n;
    vector<Point> hull;
    Point newp;
    for(int i=0;i<n;i++){
    	cin>>newp.x>>newp.y;
    	hull.push_back(newp);
	}
	if(n<=2){
		sort(hull.begin(),hull.end(),compa_xy);
		for(int i=0;i<n;i++){
			cout<<hull[i].x<<" "<<hull[i].y<<'\n';
		}
		return 0;
	}
	bool f=1;
	for(int i=2;i<n;i++){
		if(!collinear(hull[i-2],hull[i-1],hull[i])){
			f=0;
			break;
		}
	}
	if(f){
		cout<<hull[0].x<<' '<<hull[0].y<<'\n';
		cout<<hull[hull.size()-1].x<<' '<<hull[hull.size()-1].y;
	}
	else{
		vector <Point> ans=convex(hull);
		sort(ans.begin(),ans.end(),compa_xy);
		for(int i=0;i<ans.size();i++){
			cout<<ans[i].x<<" "<<ans[i].y<<'\n';
		}
	}
    return 0;
}



