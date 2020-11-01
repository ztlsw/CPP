#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <assert.h>
#define IOS ios::sync_with_stdio(false)
using namespace std;
#define inf (0x3f3f3f3f)
typedef long long int LL;


#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
const int maxn = 100000 + 20;
int b[maxn];
int a[maxn];
int book[maxn];
bool vis[maxn];
struct node {
    int val, pos;
    bool operator < (const struct node & rhs) const {
        if (val != rhs.val) return val > rhs.val;
        else return pos > rhs.pos;
    }
};
priority_queue<struct node>que;
void work() {
    while (!que.empty()) que.pop();
    memset(book, 0, sizeof book);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
        a[i] = b[i];
    }
    //ÀëÉ¢»¯ 
    sort(b+1,b+1+n);
    for (int i=1;i<= n;++i) {
        a[i] = lower_bound(b+1,b+1+n,a[i])-b;
        book[a[i]]++;
        a[i]+=book[a[i]]-1;
    }
    
    
    memset(vis,false,sizeof(vis));
    for (int i=1;i<=n;++i)
	{
        struct node t;
        t.pos=i;
        t.val=a[i];
        que.push(t);
        //assert(vis[a[i]]==false);
        vis[a[i]]=true;
    }
    
    
    int ans=0;
    int lef=-inf;
    int be=1;
    while (!que.empty())
	{
        struct node t=que.top();
        que.pop();
        if(t.pos<=lef) continue;
        lef=t.pos;
        int mx=-inf;
        while (true) 
		{
            int tmx = mx;
            for (int i=be;i<=lef;++i) mx=max(a[i],mx);
            if (tmx==mx)
			{
                be=mx+1;
                lef=mx;
                break;
            }
            be=lef+1;
            lef=mx;
        }
        ans++;
    }
    cout << ans << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        work();
        if (t) printf("\n");
    }
    return 0;
}
