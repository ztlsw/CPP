#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#define MAXN 1001100
using namespace std;
int N,M,K;
int fa[MAXN];
//¿ì¶Á 
inline void read(int &p)
{
	p=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;
}

struct node{
	int fro,to,weight;
	friend bool operator >(node a,node b)
	{
		return a.weight>b.weight;
	}
}ed[MAXN];

inline int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
priority_queue<node,vector<node>,greater<node> >que;
 int main()
 {
 	read(N);read(M);read(K);
 	for(int i=1;i<=M;i++)
 	{
 		read(ed[i].fro);read(ed[i].to);read(ed[i].weight);
 		que.push(ed[i]);
	 }
	 for(int i=1;i<=N;i++) fa[i]=i;
	 int num=0,ans=0;
	 
	 if(M<N-K)
	 {
	 	printf("0\n");
	 	return 0;
	 }
	 while(num<N-K)
	 {
	 	node u=que.top();
	 	que.pop();
	 	int x=u.fro,y=u.to;
	 	if(find(x)!=find(y))
	 	{
	 		fa[find(x)]=find(y);
	 		ans+=u.weight;
	 		num++;
		 }
	 }
	 printf("%d",ans);
	 return 0;
 }
