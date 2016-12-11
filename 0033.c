#include <stdio.h>
int main()
{
    int n,i,j,k=0;
    scanf("%d",&n);
    int num[n];
    int max[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        max[i] =0;
    }
    int temp=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            if(num[i] >= num[j])
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(num[i] == num[j])
            {
                max[i]++;
            }
        }
    }
    int max_2 = max[0];
    for(i=0;i<n;i++)
    {
        if(max[i] >= max_2)
        {
            max_2 = max[i];
        }
    }
    int sam[n];
    int chk=0;
    int num_2[n];
    for(i=0;i<n;i++)
    {
        num_2[i] =0;
    }
    int x=0;
    for(i=0;i<n;i++)
    {
        if(max[i] == max_2)
        {
            sam[i] = num[i];
            for(k=0;k<i;k++)
            {
                if(sam[k] == num[i])
                {
                    chk = 1;
                }
            }
            if(chk==0)
            {
                num_2[x] =num[i];
               x++;
            }
            chk=0;
        }
    }
    for(i=0;i<x;i++)
    {
        for(j=i+1;j<x;j++)
        {
            if(num_2[i] >= num_2[j])
            {
                temp = num_2[i];
                num_2[i] = num_2[j];
                num_2[j] = temp;
            }
        }
    }
    for(i=0;i<x;i++)
    {
        printf("%d ",num_2[i]);
    }
    return 0;
}
