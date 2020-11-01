#include<iostream> 
#include<cstdio>
#include<string>
#include<cstring>
#define N 1000001
using namespace std;
int a[N],re[N],temp,n;
bool ztchange=false;
//快读 
inline void read(int &p)
{
	p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
}

//1.选择 
/*inline void xuanze()
{
	for(int i=1;i<=n;i++)
	{
		int k=i;
		for(int j=i+1;j<=n;j++) if(a[j]>a[k]) k=j;
		if(k!=i)
		{
		temp=a[i];
		a[i]=a[k];
		a[k]=temp;
		}
	}
}*/ 


//2.冒泡
/*inline void maopao()
{
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j]<a[j+1])
			{
				ztchange=true;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			 }
		}
		if(ztchange) ztchange=false;
		else break;
	}
}*/


//3.插入??
/*inline void charu()
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		
		for(j=i-1;j>=1;j--) if(a[j]>a[i]) break;
		if(j!=i-1)
		{
			temp=a[i];
			for(k=i-1;k>j;k--) a[k+1]=a[k];
			a[k+1]=temp;
		}
	}
}*/


//4.桶排序
/*inline void tong()
{
	int b[101];
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++) b[a[i]]++;
	for(int i=100;i>=1;i--)
	{
		while(b[i]!=0)
		{
			printf("%d ",i);
			b[i]--; 
		}
	}
}*/


//5.归并!    ---最稳 
/*inline void msort(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)/2;
	msort(l,mid);
	msort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r)
	{
		if(a[i]>=a[j]) re[k++]=a[i++];    //有等号顺序不变，没有等号会变，逆序对问题注意 
		else re[k++]=a[j++];
	}
	
	while(i<=mid) re[k++]=a[i++];
	
	while(j<=r) re[k++]=a[j++];
	
	for(int i=l;i<=r;i++) a[i]=re[i];
}*/
 
 
 //6.快排    ---最快 
/*inline void qsort(int l,int r)
{
	int i,j,mid;
	i=l;j=r;
	mid=a[(l+r)/2];
	while(i<=j)
	{
		while(a[i]>mid) i++;
		while(a[j]<mid) j--;
		if(i<=j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;j--;
		}
	}
	//for(int i=1;i<=n;i++)printf("%d ",a[i]);
	//printf("\n");
	if(l<j) qsort(l,j);
	if(i<r) qsort(i,r);
	
}*/ 
int main()
{
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	//xuanze();for(int i=1;i<=n;i++) printf("%d ",a[i]);
	//maopao();for(int i=1;i<=n;i++) printf("%d ",a[i]);
	//charu();for(int i=1;i<=n;i++) printf("%d ",a[i]);
	//tong(); 
	//msort(1,n);for(int i=1;i<=n;i++) 	printf("%d ",a[i]);
	qsort(1,n);for(int i=1;i<=n;i++) 	printf("%d ",a[i]);
	return 0;
}
