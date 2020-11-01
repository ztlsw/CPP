#include<iostream> 
#include<cstdio>
#define N 10001
using namespace std;
int n,x,y;
int a[N][10];
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
		read(a[i][1]);
		read(a[i][2]);
		read(a[i][3]);
		read(a[i][4]);
	}
	read(x);read(y);
	while(n!=0)
	{
		if(x>=a[n][1]&&y>=a[n][2]&&x<=(a[n][1]+a[n][3])&&y<=(a[n][2]+a[n][4]))
		{
			printf("%d",n);
			break;
		} 
		else
		{
			n--;
			continue;
		} 
	}
	if(n==0) printf("-1");
	return 0;
}

