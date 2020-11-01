#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<stack>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
//该写法非常naive，且要求p为质数
ll n,t,m,p;
//快读 
inline void read(ll &p)
{
	p=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<3)+(p<<1)+(ch-'0'),ch=getchar();
}

inline ll ksm(ll a,ll b)
{
	ll ans=1,lim=a;
	while(b>0)
	{
		if(b&1) 
		{
			ans*=lim;
			ans%=p;
		}
		lim*=lim;
		lim%=p;
		b>>=1;
	}
	return ans;
 } 

int main()
{
	read(n);read(p);
	for(ll i=1;i<=n;i++)
	{
		printf("%lld\n",ksm(i,p-2));   
	}
	return 0;
}
