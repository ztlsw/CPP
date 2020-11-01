#include<iostream> 
#include<cstdio>
#include<string>
#include<cstring>
#define N 200010
using namespace std;
int a[N],n;
int num;
bool ztchange=false;
//¿ì¶Á 
inline void read(int &p)
{
	p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
}

inline void qsort(int l,int r)
{
	int i,j,k,temp,mid;
	i=l;j=r;mid=a[(l+r)/2];
	while(i<=j)
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}
		
		if(j>=l) qsort(l,j);
		if(i<=r) qsort(i,r);
}
int main()
{
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	qsort(1,n);
	int rec=a[1];
	for(int i=1;i<=n;i++)
	{
		if(rec==a[i]) num++;
		else
		{
			printf("%d %d\n",rec,num);
			rec=a[i];
			num=1;
		}
	}
	printf("%d %d\n",rec,num);
	return 0;
}
