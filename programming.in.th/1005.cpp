#include <stdio.h>
#include <math.h>
int main()
{
    int n,i,j,k=0,x=0;
    scanf("%d",&n);
    int num[n];
    int sum[n];
    int temp[n];
    for(i=0; i<n; i++)
    {
        scanf("%d",&num[i]);
        sum[i] = num[i];
        temp[i] = -128;
    }
    int max_sequence = num[0];
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            x=0;
            if(sum[i] >= max_sequence && sum[i] >0)
            {
                for(k=i; k<=j; k++)
                {
                    temp[x] = num[k];
                    x++;
                }
                max_sequence = sum[i];
            }
            sum[i] = sum[i]+num[j];
            x=0;
            if(sum[i] >= max_sequence  && sum[i] >0)
            {
                max_sequence = sum[i];
                for(k=i; k<=j; k++)
                {
                    temp[x] = num[k];
                    x++;
                }
            }
            x=0;
        }
        x=0;
    }
    int sum_2=0;
    x=0;
    if(max_sequence >0)
    {
        for(i=0; i<n; i++)
        {
            sum_2 = sum_2+temp[i];
            if(sum_2 == max_sequence)
            {
                for(x=0;x<=i;x++)
                    printf("%d ",temp[x]);
            }
        }
        printf("\n");
        printf("%d\n",max_sequence);
    }
    else
        printf("Empty sequence\n");
    return 0;
}
