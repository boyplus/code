#include <cstdio>
int wall[1000000];
int max_l[1000000];
int max_r[1000000];
int main()
{
    int i,j,k,n,m,max_now=-1;
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
       scanf("%d",&wall[i]);
       if(wall[i]>max_now)
       {
           max_l[i] = wall[i];
           max_now = wall[i];
       }
       else
           max_l[i] = max_now;
    }
    max_now = -1;
    for(i=n-1;i>0;--i)
    {
        if(wall[i] > max_now)
        {
            max_now = wall[i];
            max_r[i] = wall[i];
        }
        else
            max_r[i] = max_now;
    }
    --n;
    for(i=0;i<n;++i)
    {
        if(max_l[i] < max_r[i+1])
            printf("%d ",max_l[i]);
        else
            printf("%d ",max_r[i+1]);
    }
    return 0;
}
