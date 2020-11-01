#include<iostream> 
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include <algorithm>
#define N 311
using namespace std;
int temp,n;
bool ztchange=false;
//¿ì¶Á 
inline void read(int &p)
{
	p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
}

struct student{
	int ztmath;
	int ztchinese;
	int ztenglish;
	int ztsum;
	int num;
}stu[N];

student tem;

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(stu[i].ztchinese);
		read(stu[i].ztmath);
		read(stu[i].ztenglish);
		stu[i].ztsum=stu[i].ztchinese+stu[i].ztenglish+stu[i].ztmath;
		stu[i].num=i;
	}
	
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<i;j++)
		{
			if((stu[j].ztsum<stu[j+1].ztsum)||((stu[j].ztsum==stu[j+1].ztsum)&&(stu[j].ztchinese<stu[j+1].ztchinese)))
			{
				tem=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=tem;
			}
		}
	}
	
	for(int i=1;i<=5;i++)
	{
		printf("%d ",stu[i].num);
		printf("%d\n",stu[i].ztsum);
	}
	return 0;
}
