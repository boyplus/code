#include <stdio.h>
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    int num[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(i=0;i<=n-3;++i)
    {
        for(j=i+1;j<=n-2;++j)
        {
            for(k=j+1;k<=n-1;++k)
            {
                //printf("num %d %d %d\n",num[i],num[j],num[k]);
                if(num[i] + num[j] <=num[k])
                {
                    printf("yes");
                    return 0;
                }
            }
        }
    }
    printf("no");
    return 0;
}
