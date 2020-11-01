#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<stack>
#include<algorithm>
#include<queue>
#define N 500050
#define M 10002
#define INF 998244353
using namespace std;
int n,s,m;
//int fld[M][M];
int heads[N],dis[N],tot;
struct node{
	int w,now;
	friend bool operator < (node a,node b)
	{
		return a.w<b.w;
	}
};
struct edge{
	int fro,to,val,next;
}ed[M];
priority_queue<node,vector<node>,less<node> >que;
int fu,fv,fw;
//快读 
inline void read(int &p)
{
	p=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;
}
//floyd(O(n^3))
/*inline void storefloyd()
{
	//初始化 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			fld[i][j]=INF;
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		read(fu);read(fv);read(fw);
		fld[fu][fv]=min(fw,fld[fu][fv]);//可以有效处理重边 
	}
	
}


inline void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i!=k&&fld[i][k]!=INF)
			{
				for(int j=1;j<=n;j++)
				{
					fld[i][j]=min(fld[i][j],fld[i][k]+fld[k][j]);
				}
			}
		}
	}
}

inline void printffloyd()
{
	fld[s][s]=0;
	for(int i=1;i<=n;i++) printf("%d ",fld[s][i]);
}*/
inline void addin(int a,int b)
{
	ed[++tot].to=b;
	ed[tot].fro=a;
	ed[tot].next=heads[a];
	heads[a]=tot;
}
//dijstra
inline void dijstra(int s)
{
	for(int i=1;i<=n;i++) dis[i]=INF;
	
	dis[s]=0;
	que.push((node){0,s});
	while(!que.empty())
	{
		int limw,limnow;
		limw=que.top().w;
		que.pop();
		for(int i=heads[lim.now])
	}
}



int main()
{
	read(n);read(m);read(s);
	//storefloyd();floyd();printffloyd();
	addedge();
	return 0;
	
 } 

