#include<stdio.h>
int main()
{
    unsigned int length=100000,k,i,j,val=0;
    scanf("%d",&length);
    unsigned int a[length];
    for(i=0;i<length;i++)
    {
        a[i] = i+1;
        scanf("%d",&a[i]);
    }
    for(i=0;i<length;++i)
    {
        for(j=0;j<=i;++j)
        {
            for(k=0;k<=j;++k)
            {
                val+=a[k];
            }
        }
    }
    printf("%d",val);
    return 0;
}
