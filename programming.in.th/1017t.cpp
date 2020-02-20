#include <stdio.h>
int main()
{
    int i,j,k=0,n,x=0,y=0;
    scanf("%d",&n);
    int num[n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&num[i][j]);
    int sumr[n],sumc[n],sum_t1=0,sum_t2=0;
    for(i=0;i<n;i++)
    {
        sumr[i] = 0;
        sumc[i] =0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sumc[i] = sumc[i]+num[i][j];
            sumr[i] = sumr[i]+num[j][i];
        }
    }
    for(i=0;i<n;i++)
        sum_t1+=num[i][i];
    for(i=n-1;i>=0;i--)
        sum_t2+=num[i][i];
    if(sum_t1!=sum_t2)
    {
        printf("No");
        return 0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(num[i][j] < 0 || num[i][j] > n*n)
            {
                printf("No\n");
                return 0;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(num[i][j] == num[i][j+1])
            {
                printf("No\n");
                return 0;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(sumr[i] != sumc[j] || sumr[i]!=sumc[j] || sumc[i] != sumc[j] || sumr[i]!=sum_t1 || sumr[i]!=sum_t2 || sumc[i]!=sum_t1||sumc[i]!=sum_t2)
            {
                printf("No");
                return 0;
            }
        }
    }
    printf("Yes");
    return 0;
}
