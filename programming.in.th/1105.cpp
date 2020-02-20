#include <stdio.h>
int num[2000001];
int main()
{
    int i,j,k,n,m,v,max=-1,count=0;
    scanf("%d %d",&n,&k);
    for(i=0; i<n; ++i)
    {
        scanf("%d",&v);
        num[v]++;
    }
    for(i=2000000; i>=0; --i)
    {
        if(num[i])
        {
            ++count;
            if(count==k)
            {
                printf("%d\n",i);
                return 0;
            }
        }
    }
    return 0;
}
