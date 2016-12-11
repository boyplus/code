#include <stdio.h>
#include <limits.h>
int s[2000001];
int main()
{
    int i,j,k,n,m,max=INT_MIN,num;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        s[num]++;
        if(num>max)
            max = num;
    }
    for(i=max;i>=0;i--)
    {
        if(s[i]!=0)
            printf("%d ",i);
    }
    return 0;
}
