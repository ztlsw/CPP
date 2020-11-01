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
ll inv[20000528];
//¿ì¶Á 
inline void read(ll &p)
{
	p=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<3)+(p<<1)+(ch-'0'),ch=getchar();
}



int main()
{
	read(n);read(p);
	inv[1]=1;
	for(int i=2;i<p;i++) inv[i]=(p-p/i)*inv[p%i]%p;
	for(int i=1;i<=n;i++) printf("%lld\n",inv[i]);
	return 0;
}
