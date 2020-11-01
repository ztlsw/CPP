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
//��� 
inline void read(int &p)
{
	p=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;
}
//���ȶ������� 
struct node{
	int num1;
	int num2;
	friend bool operator<(node a,node b)
	{
		return a.num1<b.num1;           //��С�ں�����Ϊ�Ƚ�a��b��num1�Ĵ�С 
	}
}ed[N];
priority_queue<node>que;    //functionĬ��Ϊless��<�� 
//������ 
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
	//���ȶ��У���a1Ϊ��׼���� 
	for(int i=1;i<=n;i++)
	{
		node lim=que.top();
		que.pop();
		printf("%d %d\n",lim.num1,lim.num2);       //�Ӵ�С 
	}
	//���� 
	
	printf("\n");
	sort(ed+1,ed+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		printf("%d %d\n",ed[i].num1,ed[i].num2);      //ע�������ͬ������෴ 
	}                                                  //�Ӵ�С 
	return 0;
}
