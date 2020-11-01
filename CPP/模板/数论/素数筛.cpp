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
//��� 
inline void read(int &p)
{
	p=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
	p*=f;
}
//ԭʼɸ���ж�����O(n*sqrt(n)) 
inline bool isprime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0) return false;
	return true;
 }
 
 
 //��ͨɸ������ɸ�� O(nloglogn)
 inline void isprime2()
 {
 	for(int i=2;i<=sqrt(N);i++)
 	{
 		if(used2[i]) continue;
 		for(int j=i*i;j<=N;j+=i) used2[j]=true;
	 }
 }

//ŷ��ɸ�� O(n)
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
/*   prime[]�����е������ǵ�����,��i������prime[j]����ôi*prime[j+1]��������϶���prime[j]����ĳ����ɸ����
   ��Ϊi�к���prime[j],prime[j]��prime[j+1]С����i=k*prime[j]����ôi*prime[j+1]=(k*prime[j])*prime
   [j+1]=k��*prime[j]������ȥ������ͬ�����Բ���ɸ��ȥ�ˡ���ˣ�������i%prime[j]==0�������֮ǰ�Լ���һ��
   ���������ʱ,prime[j]�ض���prime[j]*i����С���ӡ�*/
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
