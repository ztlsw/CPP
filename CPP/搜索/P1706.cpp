#include<iostream> 
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#define N 11
using namespace std;
int a[N],temp=1,n;
bool b[N];
//快读 
inline void read(int &p)
{
	p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
}

inline void print()
{
	for(int i=1;i<=n;i++)
	{
		printf("    %d",a[i]);
	}
	printf("\n");
}
inline void dfs(int x)
{
	if(x==n)
	{
		print();
		return;
	}
	for(int i=1;i<=n;i++)            //每一层 
	{
		if(!b[i])
		{
			b[i]=true;
			a[x+1]=i;                //第n层为某数
			dfs(x+1);
			a[x+1]=0;
			b[i]=false; 
		}
	}
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++) temp*=i;
	for(int i=1;i<=n;i++) a[i]=n-i+1;
	dfs(0);
	return 0;
}
