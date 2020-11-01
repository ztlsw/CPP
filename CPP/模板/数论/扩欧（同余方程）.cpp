#include <iostream>
#include<cstdio>
#include<algorithm>
#include <cstring>
#include<cmath> 
#include <stack>
#define N 5000050
using namespace std;
int a,b,x,y;
void read(int & p)  
{  
    p=0;
    char c=getchar();  
    while(c<'0' or c>'9') c=getchar();  
    while(c>='0' and c<='9')  
        p=p*10+(c-'0'),c=getchar();  
}  
void tuozhan(int a,int b)
{
    if(b==0)
    {
        x=1,y=0;
        return ;
        }
        else
        {
            tuozhan(b,a%b);
            int k1=x-a/b*y;
            int k2=y;
            x=y;
            y=k1;
            return ;
            }
}
int main()
{
    read(a);read(b);
    tuozhan(a,b);
    printf("%d",(x+b)%b);
    return 0;
}
