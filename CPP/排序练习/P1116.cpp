#include<iostream> 
#include<cstdio>
#include<string>
#include<cstring>
#define N 1000001
using namespace std;
int temp,n,k,ans=0;
bool change;
int a[N];
//¿ì¶Á 
inline void read(int &p)
{
	p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
}

inline void maopao()
{
	for(int i=n;i>=1;i--)
	{
		k=i;
		change=false;
		for(int j=1;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				ans++;
				change=true;
			}
		}
		if(!change) break; 
	}
}


int main()
{
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	maopao();
	printf("%d",ans);
	return 0;
}

 
