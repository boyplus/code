#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int i,j,c[a],d[b];
    int max=0,count1=0,count2=0;
    for(i=1; i<=a; i++)
    {
        if(a%i==0)
        {
            c[i]=i;
            count1++;
        }
    }
    for(j=1; j<=b; j++)
    {
        if(b%j==0)
        {
            d[j]=j;
            count2++;
        }
    }
    for(i=1; i<=count1; i++)
    {
        for(j=1; j<=count2; j++)
        {
            if(c[i]==d[j])
            {
                if(c[i]>max)
                {
                    max=c[i];
                }
            }
        }
    }
    printf("%d",max);
    return 0;
}
