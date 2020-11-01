#include<iostream> 
#include<cstdio>
#include<string>
#include<cstring>
#define N 101
using namespace std;
int n,m,t;
int ax,ay,bx,by,tx,ty;
bool pos[N][N];
int ans;
//¿ì¶Á 
inline void read(int &p)
{
	p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
}

inline void dfs(int x,int y)
{
	if(x<1||y<1||x>n||y>m) return ;
	if(x==bx&&y==by)
	{
		ans++;
		return ;
	}
	if(!pos[x][y])
	{
		pos[x][y]=true;
		dfs(x+1,y);
		dfs(x,y+1);
		dfs(x-1,y);
		dfs(x,y-1);
		pos[x][y]=false;
	}
	else return;
}
int main()
{
	read(n);read(m);read(t);
	read(ax);read(ay);read(bx);read(by);
	for(int i=1;i<=t;i++)
	{
		read(tx);read(ty);
		pos[tx][ty]=true;
		if(tx==bx&&ty==by)
		{
			printf("0");
			return 0;
		}
	}
	dfs(ax,ay);
	printf("%d",ans);
	return 0;
}
