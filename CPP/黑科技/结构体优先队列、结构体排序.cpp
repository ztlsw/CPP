#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<stack>
#include<algorithm>
#include<queue>
#define N 1000001
#define ll long long
using namespace std;
int n;
//快读 
inline void read(int &p)
{
	p=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;
}
//优先队列重载 
struct node{
	int num1;
	int num2;
	friend bool operator<(node a,node b)
	{
		return a.num1<b.num1;           //将小于号重载为比较a与b的num1的大小 
	}
}ed[N];
priority_queue<node>que;    //function默认为less“<” 
//排序函数 
inline int cmp(node a,node b)
{
	if(a.num1==b.num1) return a.num2>b.num2;
	return a.num1>b.num1;
}


int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(ed[i].num1);
		read(ed[i].num2);
		que.push(ed[i]);
	}
	int num=que.size();
	printf("\n");
	//优先队列，以a1为基准排序 
	for(int i=1;i<=n;i++)
	{
		node lim=que.top();
		que.pop();
		printf("%d %d\n",lim.num1,lim.num2);       //从大到小 
	}
	//排序 
	
	printf("\n");
	sort(ed+1,ed+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		printf("%d %d\n",ed[i].num1,ed[i].num2);      //注意符号相同，结果相反 
	}                                                  //从大到小 
	return 0;
}
