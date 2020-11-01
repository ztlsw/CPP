#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#define N 100001
using namespace std;
int dp[N],d[N],tot,n,m; //
int heads[N],siz[N];
int maxx;
bool used[N];
struct tree{
	int to,next;
}ed[N*2];
//¿ì¶Á 
inline void read(int &p)
{
	p=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;
}



int main()
{
	
}
