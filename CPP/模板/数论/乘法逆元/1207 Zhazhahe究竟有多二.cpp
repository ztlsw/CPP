#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll T,n,count1,ans;
//¿ì¶Á 
inline void read(ll &p)
{
	p=0;
	ll f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;

}


int main()
{
	read(T);
	while(T--)
	{
		read(n);
		count1=2;
		ans=0;
		while(n/count1!=0)
		{
			ans+=n/count1;
			count1<<=1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
