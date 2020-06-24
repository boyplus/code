#include <stdio.h>
int main()
{
    int i,j,k,n,con_grat;
    scanf("%d",&con_grat);
    int num[5],sum=0;
    for(i=0;i<5;i++)
    {
        scanf("%d",&num[i]);
        //sum = sum+score[i];
    }
    int temp;
    for(i=0;i<5;i++)
    {
        temp = num[i];
         for(j=0;j<5;j++)
        {
            sum = sum+num[j];
        }
        if(sum == con_grat)
        {
            for(j=0;j<5;j++)
            {
                printf("%d ",num[j]);
            }
            return 0;
        }
        num[i] =0;
        sum=0;
        for(j=0;j<5;j++)
        {
            sum = sum+num[j];
        }
        if(sum == con_grat)
        {
            for(j=0;j<5;j++)
            {
                printf("%d ",num[j]);
            }
            return 0;
        }
        sum=0;
        num[i] = temp;
    }
    printf("-1");
    return 0;
}
