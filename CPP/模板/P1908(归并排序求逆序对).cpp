#include<iostream> 
#include<cstdio>
#include<string>
#include<cstring>
#define N 500050
#define ll long long
using namespace std;
ll a[N],re[N],temp,n,t;
ll ans;
//¿ì¶Á 
inline void read(ll &p)
{
	p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
}


inline void msort(ll l,ll r)
{
	if(l==r) return ;
	ll mid=(l+r)/2;
	msort(l,mid);
	msort(mid+1,r);
	ll i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r)
	{
		if(a[i]<=a[j])
		{
			re[k++]=a[i++];
		}
		else
		{
			re[k++]=a[j++];
			ans+=(j-k);
		}
	}
	while(i<=mid)
	{
		re[k++]=a[i++];
		//ans+=()
	}
	while(j<=r)
	{
		re[k++]=a[j++];
	}
	for(int i=l;i<=r;i++) a[i]=re[i];
}



int main()
{
	read(t);
	while(t--)
	{
		ans=0;
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	msort(1,n);
	//for(int i=1;i<=n;i++) printf("%lld ",a[i]);
	//printf("\n");
	//printf("%lld",ans);
	ll limm=n*(n-1)/2-1;
	if(ans>limm) printf("NO\n");
	else printf("YES\n");
	}
	return 0;
}
