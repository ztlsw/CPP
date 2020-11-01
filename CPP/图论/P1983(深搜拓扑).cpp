#include<iostream> 
#include<cstdio>
#include<string>
#include<cstring>
#define N 1111
using namespace std;
int m,n;
//¿ì¶Á 
inline void read(int &p)
{
	p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
}

int heads[N*2];
struct node{
	int next;
	int to;
}ed[2000*N];

int main()
{
	
}
