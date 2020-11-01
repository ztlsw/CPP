#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#define N 1000001
using namespace std;
int a[N],re[N][17],temp,n,m;
bool ztchange=false;
//¿ì¶Á 
inline void read(int &p)
{
	p=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;
}

inline void dp()
{
	for(int i=1;i<=17;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			re[j][i]=max(re[j][i-1],re[j+(1<<(i-1))][i-1]);
}

inline int search1(int l,int r)
{
	int len=(int)(log(r-l+1)/log(2.0));
	return max(re[l][len],re[r-(1<<len)+1][len]);
}

int main()
{
	read(n); read(m);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		re[i][0]=a[i];
	}
	
	dp();
	
	while(m--)
	{
		int l,r;
		read(l);read(r);
		printf("%d\n",search1(l,r));
	}
	return 0;
}
