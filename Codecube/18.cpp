#include <stdio.h>
#include <limits.h>
int main()
{
    int min = INT_MAX,max = INT_MIN,i,n,num;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        if(num > max)
            max = num;
        if(num < min)
            min = num;
    }
    printf("%d\n%d",max,min);
    return 0;
}
