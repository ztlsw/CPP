#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;
char ch;
bool getans;
int n,m,t;
int mx[]={0,-1,-1,-2,-2,2,2,1,1};
int my[]={0,2,-2,1,-1,1,-1,-2,2};
int ys[10][10];
int aim[10][10]={
	{0,0,0,0,0,0},
	{0,1,1,1,1,1},
	{0,0,1,1,1,1},
	{0,0,0,2,1,1},
	{0,0,0,0,0,1},
	{0,0,0,0,0,0},
};
//快读 
inline void read(int &p)
{	
	p=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;
}
//估值函数
inline int gn()
{
	int count=0;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if(ys[i][j]!=aim[i][j]) count++;
		}
	}
	return count;
 }
//越界判定
inline bool judge(int xx,int yy)
{
	if(xx<1||xx>5||yy<1||yy>5) return false;
	return true;
 } 
 //IDE_STARDFS
 inline void IDE_STARDFS(int dep,int x,int y,int aimdep)
 {
 	if(dep==aimdep)
 	{
 		if(!gn()) getans=true;
 			return ;
	 }
 	for(int i=1;i<=8;i++)
 	{
 			int xx,yy;
 			xx=x+mx[i];yy=y+my[i];
 			if(!judge(xx,yy)) continue;
 			swap(ys[xx][yy],ys[x][y]);
 			int val=gn();
 			if(val+dep<=aimdep) IDE_STARDFS(dep+1,xx,yy,aimdep);
 			swap(ys[xx][yy],ys[x][y]);
	 }
 	
 }
int main()
{
	read(t);
	while(t--)
	{
		getans=false;
		int posx,posy;
		for(int i=1;i<=5;i++)
		{
			for(int j=1;j<=5;j++)
			{
				cin>>ch;
				if(ch=='*')
				{
					posx=i;posy=j;ys[i][j]=2;
				}
				else ys[i][j]=ch-'0';
			}
		}
		
		if(!gn())
		{
			printf("0\n");
			continue;
		}
		for(int i=1;i<=15;i++)
		{
			IDE_STARDFS(0,posx,posy,i);
			if(getans)
			{
				printf("%d\n",i);
				break;
			}
		}
		if(!getans) printf("-1\n");
	}
	return 0;
 } 
