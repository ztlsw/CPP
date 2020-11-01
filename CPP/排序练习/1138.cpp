#include<iostream> 
#include<cstdio>
#include<string>
#include<cstring>
#define N 10010
using namespace std;
int a[N],temp,n,k,count;
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
	read(n);read(k);
	for(int i=1;i<=n;i++)
	{
		read(temp);
		a[temp]++;
	}
	for(int i=1;i<N;i++)
	{
		if(a[i]!=0)
		{
			count++;
			if(count==k)
			{
				ztchange=true;
				printf("%d",i);
				break;
			}
		}
	}
	if(!ztchange) printf("NO RESULT");
	return 0;
}
