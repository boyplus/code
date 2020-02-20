#include <cstdio>
int n,k;
int ans[8];
bool ban[8],use[8];
void make(int);
int main()
{
    int i,j,x;
    scanf("%d %d",&n,&k);
    for(i=0; i<k; ++i)
    {
        scanf("%d",&x);
        ban[x] = true;
    }
    make(0);
    return 0;
}
void make(int now)
{
    if(now == n)
    {
        if(!ban[ans[0]])
        {
            for(int i=0; i<n; ++i)
                printf("%d ",ans[i]);
            printf("\n");
        }
    }
    else
    {
        for(int i=1; i<=n; ++i)
        {
            if(use[i] == false)
            {
                ans[now] = i;
                use[i] = true;
                make(now+1);
                use[i] = false;
            }
        }
    }
}
