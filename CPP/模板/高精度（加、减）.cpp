#include<iostream> 
#include<cstdio>
#include<string>
#define N 1000001
using namespace std;
int a[N],b[N],c[N];
string s;
bool mytop,mymine;
int len,x;    //xΪ��λ ����λ 
//��� 
inline void read(int &p)
{
	p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=p*10+(ch-'0'),ch=getchar();
}

//�������� 
inline void mystore(int a[])
{
	cin>>s;
	a[0]=s.length();
	for(int i=1;i<=a[0];i++) a[i]=s[a[0]-i]-'0';
}


 //�߾��ȼӷ� 
inline void myaddin(int a[],int b[]) 
{
	len=max(a[0],b[0]);                      //��λ 
	for(int i=1;i<=len;i++) 
	{
		c[i]=a[i]+b[i]+x;
		if(c[i]>=10)
		{
			x=c[i]/10;
			c[i]%=10;
		}
		else x=0;
	}
	if(x!=0) c[++len]=1;
	for(int i=len;i>=1;i--) cout<<c[i];
}


//�߾��ȼ��� 
inline void myminus(int a[],int b[])        
{
	x=0;
	for(int i=1;i<=len;i++)
	{
		if(a[i]+x<b[i])
		{
			c[i]=a[i]+10-b[i]+x;
			x=-1;
		}
		else 
		{
			c[i]=a[i]-b[i]+x;
			x=0;
		}
	}
	if(mymine==false) printf("-");
	while(c[len]==0) len--;
	for(int i=len;i>=1;i--) cout<<c[i];              //��λ��ȥ�㡢�ж����� 
}

inline void judgeminus(int a[],int b[]) // �߾��ȼ����ж�����
{
	int lens=100;
	if(a[0]<b[0]){len=b[0];mymine=false;myminus(b,a);}
	else if (a[0]>b[0]) {len=a[0];mymine=true;myminus(a,b);}
	else 
	{
		len=a[0];
		lens=len;
		while (lens!=0)
		{
			if(a[lens]>b[lens]){mymine=true;myminus(a,b);break;}
			else if(b[lens]>a[lens]) {mymine=false;myminus(b,a);break;}
			else {lens--;continue;}
		}
	}
	if(lens==0) printf("0");
}


int main()
{
	mystore(a);
	mystore(b);
	//myaddin(a,b);
	judgeminus(a,b);
	return 0;
}




