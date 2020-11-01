#include<iostream> 
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<stack>
#define N 1000001
using namespace std;
int a[N],temp,n,k;
list<int>lismin,lismax;
inline void smaller()
{
	for(int i=1;i<=n;i++)
	{
		
		if((!lismin.empty())&&(lismin.front()<=i-k)) lismin.pop_front();
		
		while((!lismin.empty())&&(a[lismin.back()]>a[i])) lismin.pop_back();
		
		lismin.push_back(i);
		
		if(i>=k) printf("%d ",a[lismin.front()]);
	}
}

inline void bigger()
{
	for(int i=1;i<=n;i++)
	{
		
		if((!lismax.empty())&&(lismax.front()<=i-k)) lismax.pop_front();
		
		while((!lismax.empty())&&(a[lismax.back()]<a[i])) lismax.pop_back();
		
		lismax.push_back(i);
		
		if(i>=k) printf("%d ",a[lismax.front()]);
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	
	for(int i=1;i<=n;i++)
	{
		int lib;
		scanf("%d",&lib);
		a[i]=lib;
	}
	//lismin.push_back(1);
	//lismax.push_back(1);
	
	smaller();
	printf("\n");
	bigger();
	return 0;
} 

