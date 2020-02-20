#include <stdio.h>
int main()
{
    int i,j,k,n;
    scanf("%d %d",&n,&k);
    int wheel[n];
    int prize[n];
    int walk[n];
    for(i=0; i<n; i++)
        scanf("%d",&prize[i]);
    for(i=0; i<n; i++)
        scanf("%d",&walk[i]);
    for(i=0; i<n; i++)
        wheel[i] = i+1;
    int tar=1,stop=0,sum[k],count=0,now=1;
    for(i=0; i<k; i++)
        sum[i] =0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<walk[i]; j++)
        {
            while(wheel[now-1] == 0)
            {
                now = now+1;
                if(now > n)
                    now = 1;
            }
            now = now+1;
            if(now > n)
                now = 1;
        }
        while(wheel[now-1] == 0)
        {
            now = now+1;
            if(now > n)
                now = 1;
        }
        stop = now;
        wheel[now-1] = 0;
        sum[tar-1] = sum[tar-1] + prize[stop-1];
        tar++;
        if(tar > k)
            tar = 1;
        now = stop;
    }
    for(i=0; i<k; i++)
        printf("%d\n",sum[i]);
    return 0;
}
