#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#define MAXN 200100
using namespace std;
int N,M,K;
int fa[MAXN];
//快读 
inline void read(int &p)
{
	p=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;
}

inline int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];               //改变的是fa[],不是x 
}

int main()
{
	read(N);read(M);
	for(int i=1;i<=N;i++) fa[i]=i;
	int X,Y,Z;
	while(M--)
	{
		read(Z);
		switch (Z)
			{
				case 1:{
					read(X);read(Y);
					fa[find(X)]=find(Y);
					break;
				}
				
				case 2:{
					read(X);read(Y);
					if(find(X)==find(Y)) printf("Y\n"); //比较fa[]可能造成遇见部分未压缩节点 
					else printf("N\n");
					break;
				}
			}
	}
	return 0;
}
