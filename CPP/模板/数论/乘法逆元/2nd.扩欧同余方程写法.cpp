#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<stack>
#include<algorithm>
#include<queue>
#define MOD 1000000007
#define ll long long 
using namespace std;
ll n,t,p;
ll x,y;
//快读 
inline void read(ll &p)
{
	p=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<3)+(p<<1)+(ch-'0'),ch=getchar();
}
//即求ax+by=1同余方程,该方法可针对p非质数 
inline void exgcd(ll a,ll b)
{
	if(b==0)
	{
		x=1;y=0;
		return ;
	}
	exgcd(b,a%b);
	ll k1=x-a/b*y;
	x=y;
	y=k1;
	return ;
}

int main()
{
	read(n);read(p);
	for(ll i=1;i<=n;i++)
	{
		exgcd(i,p);
		x=(x%p+p)%p;
		printf("%lld\n",x);
	}
	return 0;
}
