#include<iostream> 
#include<cstdio>
#include<string>
#include<cstring>
#define N 10
using namespace std;
int temp,n;
int a[N];
//¿ì¶Á 
inline void read(int &p)
{
	p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
}


int main()
{
	read(a[1]);
	read(a[2]);
	read(a[3]);
	read(a[4]);
	for(int i=4;i>=1;i--)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	
	if(a[1]+a[2]>a[3]||a[2]+a[3]>a[4]) printf("TRIANGLE");
	else if(a[1]+a[2]==a[3]||a[2]+a[3]==a[4]) printf("SEGMENT");
	else printf("IMPOSSIBLE");
	return 0;
}
