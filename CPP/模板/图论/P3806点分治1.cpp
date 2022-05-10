#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#include<algorithm>
#include<queue>
#define N 10010
#define ll long long
using namespace std;
ll T,n,m;
ll heads[N],tot;
ll ask[N];
ll d[N],b[N];
pair<ll,int>g[N];
ll siz[N],wt[N];
bool ans[N],vis[N];
ll root,cnt;
struct node
{
	ll next;
	ll fro,too,val;
}ed[4*N];
//¿ì¶Á 
inline void read(ll &p)
{
	p=0;
	ll f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;
}

inline void addin(ll  a,ll b,ll w)
{
	ed[++tot].fro=a;
	ed[tot].too=b;
	ed[tot].next=heads[a];
	ed[tot].val=w;
	heads[a]=tot;
}

inline void Dfs(ll u,ll w,ll f,ll tp)
{
	g[++cnt].first=w;
	g[cnt].second=u;
	d[u]=cnt;
	b[u]=tp;
	for(int i=heads[u];i!=0;i=ed[i].next)
	{
		ll v=ed[i].too;
		if(v==f||vis[v]) continue;
		if(w==0) Dfs(v,w+ed[i].val,u,v);
		else Dfs(v,w+ed[i].val,u,tp);
	}
}

inline void calc(ll u,ll w)
{
	cnt=0;
	Dfs(u,w,0,u);
	sort(g+1,g+1+cnt);
	for(int i=1;i<=m;i++)
	{
		ll l=1,r=cnt;
		while(l<r)
		{
			if(ans[i]) break;
			ll limm=g[l].first+g[r].first;
			if(limm>ask[i]) r--;
			else if(limm<ask[i]) l++;
			else
			{
				if(b[g[l].second]!=b[g[r].second]) ans[i]=1;
				r--; 
			}
		}
	}
}
//????
inline void findroot(ll x,ll f,ll nown)
{
	siz[x]=1;wt[x]=0;
	for(int i=heads[x];i!=0;i=ed[i].next)
	{
		ll v=ed[i].too;
		if(v!=f&&!vis[v])
		{
			findroot(v,x,nown);
			siz[x]+=siz[v];
			wt[x]=max(wt[x],siz[v]);
		}
	}
	wt[x]=max(wt[x],nown-wt[x]);
	if(wt[root]>wt[x]) root=x;
}

inline void DFS(int x)
{
	vis[x]=1;
	calc(x,0);
	for(int i=heads[x];i!=0;i=ed[i].next)
	{
		ll v=ed[i].too;
		if(vis[v]) continue;
		root=0;
		wt[0]=N*2;
		findroot(v,x,siz[v]);
		DFS(root);
	}
}

int main()
{
//	freopen("P3806.in","r",stdin);
//	freopen("1.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<n;i++)
	{
		ll u,v,w;
		read(u);read(v);read(w);
		addin(u,v,w);
		addin(v,u,w);
	}
	for(int i=1;i<=m;i++) read(ask[i]);
	wt[0]=N*2;
	findroot(1,0,n);
	DFS(root);
	for(int i=1;i<=m;i++)
	{
		if(ans[i]) printf("AYE\n");
		else printf("NAY\n");
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
