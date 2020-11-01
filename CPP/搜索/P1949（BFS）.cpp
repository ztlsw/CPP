#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<stack>
#include<algorithm>
#include<queue>
#define N 1000000
using namespace std;
int n,t,m;

struct node{
	int num;int gb;int dep;
}u,v;
queue<node>q1;
bool vis[N][7];   //数字，光标 
int sig[8]={0,100000,10000,1000,100,10,1};
//快读 
inline void read(int &p)
{
	p=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<3)+(p<<1)+(ch-'0'),ch=getchar();
}



int main()
{
	int mission,numberposnow,numberposfor,numberposfor1,numgb;
	read(u.num);read(mission);
	if(mission==u.num)
	{
		printf("0");
		return 0;
	}
	u.gb=1;u.dep=0;q1.push(u);
	while(!q1.empty())
	{
		u=q1.front();q1.pop();
		numberposnow=(u.num/sig[u.gb])%10;
		
		if(u.gb!=1)
		{
			//光标左移
			v=u;
			v.dep++;v.gb=u.gb-1;
			if(!vis[v.num][v.gb])
			{
				vis[v.num][v.gb]=true;
				q1.push(v);
			}
			//交换左端
			v=u;v.dep++;
			numberposfor=v.num/sig[1];
			v.num=v.num-numberposfor*sig[1]+numberposnow*sig[1]-numberposnow*sig[v.gb]+numberposfor*sig[v.gb];
			if(v.num==mission)
			{
				printf("%d",v.dep);
				return 0;
			}
			if(!vis[v.num][v.gb])
			{
				vis[v.num][v.gb]=true;
				q1.push(v);
			}
		}
		if(u.gb!=6)
		{
			v=u;
			//光标右移
			v.dep++;v.gb=v.gb+1;
			if(!vis[v.num][v.gb])
			{
				vis[v.num][v.gb]=true;
				q1.push(v);
			 } 
			 //光标交换
			 v=u;v.dep++;
			numberposfor1=v.num%10;
			v.num=v.num-numberposnow*sig[v.gb]+numberposfor1*sig[v.gb]-numberposfor1+numberposnow;
			if(v.num==mission)
			{
				printf("%d",v.dep);
				return 0;
			}
		}
		if(!vis[v.num][v.gb]){vis[v.num][v.gb]=1;q1.push(v);}
		if(numberposnow!=0)
		{
			v=u;
			v.dep++;
			v.num=v.num-sig[v.gb];
			if(v.num==mission)
			{
				printf("%d",v.dep);
				return 0;
			}
			if(!vis[v.num][v.gb])
			{
				vis[v.num][v.gb]=true;
				q1.push(v);
			}
		}
		if(numberposnow!=9)
		{
			v=u;
			v.dep++;
			v.num=v.num+sig[v.gb];
			if(v.num==mission)
			{
				printf("%d",v.dep);
				return 0;
			}
			if(!vis[v.num][v.gb])
			{
				vis[v.num][v.gb]=true;
				q1.push(v);
			}
		}
		
	}
	return 0;
}
