#include <stdio.h>
int main()
{
    int i,j,k,n,m,a,b;
    scanf("%d %d",&n,&m);
    int num[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        int temp[b],start=a-1;
        for(j=b-1;j>=0;j--)
        {
            temp[j] = num[start];
            start++;
            if(start>=n)
            {
                start = 0;
            }
        }
        start = a-1;
        for(j=0;j<b;j++)
        {
            num[start] = temp[j];
            start++;
            if(start>=n)
                start=0;
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",num[i]);
    return 0;
}
