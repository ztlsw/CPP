#include<iostream> 
#include<cstdio>
#include<string>
#include<cstring>
#define N 20000001
using namespace std;
int b[N],num,n,ans,ztmax,pos,flor;
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
		if(b[i]==0) flor++;
		b[a]++;
		num++;
		if(a>ztmax) ztmax=a;
	}
	for(int i=1;i<=ztmax;i++)
	{
		if(b[i]!=0)
		{
			ans+=(i-pos)*6;
			ans+=5;
			pos=i;
		 }
	}
	printf("%d",(ans+num)+4*ztmax);
	return 0;
}
