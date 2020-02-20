#include<stdio.h>
#include<math.h>
int absolute(int);
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    int max1 = 0;
    int max2 =n;
    int check_g2 =0;
    if(n%2==0)
    {
        max1 = n-1;
    }
    if(n%2!=0)
    {
        max1 = n;
    }
    int g = n/2;
    if(n%2==1)
    {
        g = g+1;
    }
    int g_2 = g;
    int x[max2];
    int y[max2];
    for(i=0;i<max2;i++)
    {
        x[i] = absolute(g_2);
        g_2 = g_2-1;
        if(g_2 ==0)
        {
            g_2 = g_2-2;
        }
    }
    if(n%2==0)
    {
        x[n/2] = 1;
        for(i=(n/2)+1;i<n;i++)
        {
            x[i] = x[i]-1;
        }
    }
    g_2=g;
    for(i=0;i<max2;i++)
    {
        y[i] = g_2;
        if(g_2<=max1 && check_g2 ==0)
        {
            g_2 = g_2+1;
        }
        if(g_2 > max1 && check_g2==0)
        {
            g_2 = g_2 -1;
            check_g2 = 1;
        }
        if(check_g2 == 1)
        {
            g_2 = g_2-1;
        }
    }
    if(n%2==0)
    {
        y[g] = max1;
        for(i=g+1;i<max2;i++)
        {
            y[i] = y[i]+1;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<max1;j++)
        {
            if(x[i] == j+1 || y[i] ==j+1)
            {
                printf("*");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
    return 0;
}
int absolute(int a)
{
    if(a <0)
    {
        return a*-1;
    }
    else
    {
        return a;
    }
}
