#include<stdio.h>
int main()
{
    int  a,b;
    int m=0;
    scanf("%d %d",&a,&b);
    if(a>=1 && b>=1 && a<=1000 && b<=1000)
    {
        if(b%a==0)
        {
            m = (b/a);
        }
        else
            m = (b/a)+1;
        if(a<b)
        {
            printf("%d\n",m);
        }
        if(a>b)
        {
            printf("2");
        }
    }

    return 0;
}
