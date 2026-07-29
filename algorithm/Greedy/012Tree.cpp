#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(c!=a+1)
	{
		puts("-1");
		return;
	}
	if(a==0)
	{
		cout<<b<<"\n";
		return;
	}
	int ans=log2(a)+1;
	if(b==0)
	{
		cout<<ans<<"\n";
		return;
	}
	int x=1,f,z;
	while(true)
	{
		if(a<=x)
		{
			z=a*2+(x-a);
			f=x-a;
			break;
		}
		a-=x;
		x*=2;
	}
	b-=f;
	if(b<=0)
	{
		cout<<ans<<"\n";
		return; 
	}
	cout<<ans+(b+z-1)/z<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--) solve(); 
}


