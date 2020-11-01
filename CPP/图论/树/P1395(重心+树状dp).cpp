#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#define N 100001
using namespace std;
int dp[N],d[N],tot,n,m; //
int heads[N],siz[N];
int maxx;
bool used[N];
struct tree{
	int to,next;
}ed[N*2];
//¿ì¶Á 
inline void read(int &p)
{
	p=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;
}
//Á¬Í¼ 
inline void addin(int a,int b)
{
	ed[++tot].to=b;
	ed[tot].next=heads[a];
	heads[a]=tot;
	
	ed[++tot].to=a;
	ed[tot].next=heads[b];
	heads[b]=tot;
}

inline void dfs1(int a)
{
	siz[a]=1;
	//used[a]=true;
	for(int i=heads[a];i;i=ed[i].next)
	{
		int to=ed[i].to;
		if(used[to]) continue;
		d[to]=d[a]+1;
		used[to]=true;
		dfs1(to);
		siz[a]+=siz[to];
	}
}


inline void dfs2(int a,int b)
{
	dp[a]=dp[b]+n-2*siz[a];
	used[a]=true;
	for(int i=heads[a];i;i=ed[i].next)
	{
		int to=ed[i].to;
		if(used[to]) continue;
		dfs2(to,a);
	}
}



int main()
{
	read(n);
	for(int i=1;i<n;i++)
	{
		int a1,b1;
		read(a1);
		read(b1);
		addin(a1,b1);
	}
	d[1]=0;
	used[1]=true; 
	dfs1(1);
	for(int i=1;i<=n;i++)  maxx+=d[i];
	
	dp[1]=maxx;
	memset(used,0,sizeof(used));
	used[1]=true;
	for(int i=heads[1];i;i=ed[i].next)
	{
		int to=ed[i].to;
		dfs2(to,1);
	}
	int minn=dp[1],index=1;
	for(int i=2;i<=n;i++) 
	{
		if(dp[i]<minn) 
		{
			index=i;
			minn=dp[i];
		}
	}
	
	printf("%d %d",index,minn);
	return 0;
 } 
 
 /*
 
 9
 1 2
 2 3
 3 4
 3 5
 4 6
 4 7
 5 8
 5 9
 
 
 */ 
 
  
