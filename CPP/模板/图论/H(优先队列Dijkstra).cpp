#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<stack>
#include<algorithm>
#include<queue>
#define N 200100
using namespace std;
int n,t,m,s,T;
//¿ì¶Á 
inline void read(int &p)
{
	p=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;
}
struct edge{
	int to,next,w;
}ed[N];

struct node{
	int dis,pos;
	friend bool operator > (node a,node b)
	{
		return a.dis>b.dis;
	}
};


priority_queue<node,vector<node>,greater<node> >que;
int heads[N],tot;
int mm[N],nn[N],last[N];
int dis[N];
bool vis[N];
inline void addin(int a,int b,int w)
{
	ed[++tot].to=b;
	ed[tot].next=heads[a];
	ed[tot].w=w;
	heads[a]=tot;
}

inline void DJ(int s)
{
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[s]=0;
	que.push((node){0,s});
	while(!que.empty())
	{
		node u=que.top();
		que.pop();
		if(vis[u.pos])continue;
		vis[u.pos]=true;
		for(int i=heads[u.pos];i!=0;i=ed[i].next)
		{
			int v=ed[i].to;
			if(dis[v]>dis[u.pos]+ed[i].w)
			{
				dis[v]=dis[u.pos]+ed[i].w;
				que.push((node){dis[v],v});
			}
		}
	}
	
}

int main()
{
	read(n);read(m);read(s);read(t);read(T);
	for(int i=1;i<=m;i++) read(mm[i]);
	for(int i=1;i<=n;i++)
	{
		if(i!=n)
		{
			addin(i,i+1,T);
			addin(i+1,i,T);
		}
		int limm;
		read(limm);
		if(last[limm]!=0) addin(last[limm],i,mm[limm]);
		last[limm]=i;
	}
	DJ(s);
	printf("%d\n",dis[t]);
	return 0;
}
