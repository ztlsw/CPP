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
priority_queue<int>que;
int n;
bool used2[N];
int ans,cnt;
bool used3[N];
int prime[N];
//快读 
inline void read(int &p)
{
	p=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;
}
//原始筛法判断素数O(n*sqrt(n)) 
inline bool isprime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0) return false;
	return true;
 }
 
 
 //普通筛（埃氏筛） O(nloglogn)
 inline void isprime2()
 {
 	for(int i=2;i<=sqrt(N);i++)
 	{
 		if(used2[i]) continue;
 		for(int j=i*i;j<=N;j+=i) used2[j]=true;
	 }
 }

//欧拉筛法 O(n)
inline void isprime3()
{
	int cnt=0;
	for(int i=2;i<=N;i++)
	{
		if(!used3[i])
		{
			cnt++;
			prime[cnt]=i;
		}
		for(int j=1;i*prime[j]<=N&&j<=cnt;j++)
		{
			used3[prime[j]*i]=true;
			if(i%prime[j]==0) break;
		}
	}
}
/*   prime[]数组中的素数是递增的,当i能整除prime[j]，那么i*prime[j+1]这个合数肯定被prime[j]乘以某个数筛掉。
   因为i中含有prime[j],prime[j]比prime[j+1]小，即i=k*prime[j]，那么i*prime[j+1]=(k*prime[j])*prime
   [j+1]=k’*prime[j]，接下去的素数同理。所以不用筛下去了。因此，在满足i%prime[j]==0这个条件之前以及第一次
   满足改条件时,prime[j]必定是prime[j]*i的最小因子。*/
int main()
{
	read(n);
	if(isprime(n)) printf("Checked\n");
	else  printf("Wrong\n");
	
	isprime2();
	
	if(!used2[n]) printf("Checked\n");
	else  printf("Wrong\n");
	
	isprime3();
	if(!used3[n]) printf("Checked\n");
	else printf("Wrong\n");
	return 0;
}
