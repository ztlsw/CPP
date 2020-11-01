#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;
int N,nowused=1e9+9,M;
int minn[16],minb[16];
int cnt=1;
//¿ì¶Á 
inline void read(int &p)
{	
	p=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;
}

inline void dfs(int dep,int N,int ri,int hi,int Q)
{
	if(dep==M)
	{
		if(N==0)
			if(Q<nowused) nowused=Q;
		 return ;
	}
	if(Q+2*N/ri>nowused) return ;    
	if(Q+minb[M-dep]>=nowused) return ;
	if(minn[M-dep]>N) return ;
	for(int i=ri-1;i>=M-dep;i--)
	{
		for(int j=M-dep;j*i*i<=N&&j<hi;j++)
		{
			dfs(dep+1,N-i*i*j,i,j,Q+2*i*j);
		}
	}
}



int main()
{
	read(N);read(M);
	for(int i=1;i<=M;i++)
	{
		minn[i]=minn[i-1]+i*i*i;  
		minb[i]=minb[i-1]+2*i*i;
	}
	int num=sqrt(N);
	for(int i=num;i>=M;i--)
	{
		for(int j=M;j*i*i<=N;j++)
		{
			dfs(1,N-i*i*j,i,j,i*i+2*i*j);
		}
	}
	if(nowused==1e9+9)
	{
		printf("0\n");
		return 0;
	}
	else
	{
		printf("%d\n",nowused);
		return 0;
	}
	return 0;
}


