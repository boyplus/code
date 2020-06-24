#include <cstdio>
#include <stdlib.h>
#include <queue>
using namespace std;
int c[1000010];
struct compare
{
    bool operator()(const int& l, const int& r)
    {
        return l > r;
    }
};
priority_queue<int,vector<int>, compare > my_queue[1000000];
int main()
{
    int i,j,k,m,n,power;
    scanf("%d %d",&n,&m);
    for(i=0; i<n; ++i)
    {
        for(j=0; j<m; ++j)
        {
            scanf("%d",&power);
            my_queue[i].push(power);
        }
    }
    for(i=0; i<m; ++i)
    {
        int max=-1,ans=0;
        for(j=0; j<n; ++j)
        {
            if(my_queue[j].top() > max)
            {
                max = my_queue[j].top();
                ans = j;
            }
            my_queue[j].pop();
        }
        c[ans]++;
    }
    int max_now=-1,ans=0;
    for(i=0;i<=n;++i)
    {
        if(c[i] > max_now)
        {
            max_now = c[i];
            ans = i;
        }
    }
    printf("%d\n",ans+1);
    return 0;
}
