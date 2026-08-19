#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

int M,N,x,cnt,ans;
deque <int> Q;

int main(){
	cin >> M >> N;
	for(int i = 1;i <= N;i ++){
		cin >> x;
		if(cnt == 0){
			Q.push_back(x);
			cnt ++;
			ans ++;
		}
		else{
			bool f = 0;
			for(auto t : Q){
				if(t == x){
					f = 1;
					break;
				}
			}
			if(!f){
				if(cnt == M){
					Q.pop_front();
					Q.push_back(x);
				}
				else{
                    Q.push_back(x);
                    cnt ++;
                }
				ans ++;
			}
		}
	}
	cout << ans;
	return 0;
}
