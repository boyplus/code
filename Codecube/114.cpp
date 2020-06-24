#include <cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    for(int c=1; c<=t; c++)
    {
        long long i,j,k,m,n,count=0;
        scanf("%lld %lld",&m,&n);
        long long worng_max = n/20;
        for(i=0; i<=worng_max; i++)
        {
            long long time = i*20;
            long long time_send = n - time;
            if(time_send <= m)
                count++;
        }
        printf("Case #%d: %lld\n",c,count);
    }
    return 0;
}
