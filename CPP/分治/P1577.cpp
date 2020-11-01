#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<stack>
#include<algorithm>
#include<queue>
#define MAXN 100010
using namespace std;
int N,K;
double L[MAXN];
int l[MAXN];

inline void read(int &p)
{	
	p=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;
}

inline bool judge(int len)
{
	int num=0;
	for(int i=1;i<=N;i++) num+=l[i]/len;
	return num>=K;
}

int main()
{
	read(N);read(K);
	int INF=1e9+7;
	for(int i=1;i<=N;i++)
	{
		scanf("%lf",&L[i]);
		l[i]=int(L[i]*100);
	}
	int l=0,r=INF;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(mid==0) break;
		if(judge(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%.2f",r/100.0);
	return 0;
}
