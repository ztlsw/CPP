#include<iostream> 
#include<cstdio>
#include<string>
#include<cstring>
#define N 1000001
using namespace std;
int temp,n,ans=0;
int b[1111];
bool ztchange=false;
//¿ì¶Á 
inline void read(int &p)
{
	p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
}



int main()
{
	
	read(n);
	for(int i=1;i<=n;i++)
	{
		int a;
		read(a);
		if(b[a]==0) ans++;
		b[a]++;
	}
	printf("%d\n",ans);
	for(int i=1;i<=1001;i++)
	{
		if(b[i]!=0)
		{
			printf("%d ",i);
			continue;
		}
	 }
	return 0;
}
