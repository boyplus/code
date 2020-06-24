#include <cstdio>
#include <limits.h>
int qsum[1000100];
int main()
{
    int i,j,n,start,a,b,max=-1,min = INT_MAX;
    scanf("%d %d",&n,&start);
    for(i=0; i<n; i++)
    {
        scanf("%d %d",&a,&b);
        if(a < b)
        {
            qsum[a]++;
            qsum[b+1]--;
        }
        else
        {
            qsum[a+1]--;
            qsum[b]++;
        }
        if(b > max)
            max = b;
    }
    for(i=1; i<=max; i++)
        qsum[i] = qsum[i-1] + qsum[i];
    bool chk = false;
    for(i=0; i<=max; i++)
    {
        if(qsum[i] >= n)
        {
            chk = true;
            int diff = start - i;
            if(diff < 0)
                diff = -1* diff;
            if(diff < min)
                min = diff;
        }
    }
    if(chk)
        printf("%d\n",min);
    else
        printf("-1\n");
    return 0;
}
