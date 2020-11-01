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
//¿ì¶Á 
inline void read(int &p)
{	
	p=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;
}
int n,m,t,mp[7][7],stx,sty,success;
char ch;
const int dx[]={0,1,1,-1,-1,2,2,-2,-2};
const int dy[]={0,2,-2,2,-2,1,-1,1,-1};
const int goal[7][7]={
	{0,0,0,0,0,0},
	{0,1,1,1,1,1},
	{0,0,1,1,1,1},
	{0,0,0,2,1,1},
	{0,0,0,0,0,1},
	{0,0,0,0,0,0},
};


inline evaluate()
{
	int cnt=0;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if(mp[i][j]!=goal[i][j]) cnt++;
		}
	}
	return cnt;
}


inline int safe(int x,int y)
{
	if(x<1||x>5||y<1||y>5) return 0;
	return 1;
}

inline void A_star(int dep,int x,int y,int maxdep)
{
	if(dep==maxdep)
	{
		if(!evaluate()) success=1;
		return ;
	}
	
	for(int i=1;i<=8;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(!safe(xx,yy)) continue;
		swap(mp[x][y],mp[xx][yy]);
		int eva=evaluate();
		if(eva+dep<=maxdep)
		{
			A_star(dep+1,xx,yy,maxdep);
		}
		swap(mp[x][y],mp[xx][yy]);
	}
}
int main()
{
	read(t);
	while(t--)
	{
		success=0;
		for(int i=1;i<=5;i++)
		{
			for(int j=1;j<=5;j++)
			{
				cin>>ch; ///
				if(ch=='*') mp[i][j]=2,stx=i,sty=j;  //Æðµã
				else mp[i][j]=ch-'0';
			}
		}
		
		if(!evaluate()){printf("0\n");continue;}
		for(int maxdep=1;maxdep<=15;maxdep++)
		{
			A_star(0,stx,sty,maxdep);
			if(success) {printf("%d\n",maxdep);goto ZAGER;}
		}
		
		printf("-1\n");
		ZAGER:;
	}
	return 0;
 } 
