#include <stdio.h>
int num[500000];
int main()
{
    int i,j,k,n,b;
    scanf("%d %d",&n,&b);
    int count_mul=2;
    int count=0;
    for(i=1; i<n; i++)
    {
        if(num[i]!=-1)
        {
            for(j=i; j<n; j+=count_mul)
                num[j] = -1;
            count++;
        }
        count_mul++;
    }
    if(b < count)
        printf("%d\n",count-b);
    else
        printf("%d\n",0);
    return 0;
}
