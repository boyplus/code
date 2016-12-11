#include <cstdio>
int main()
{
    int i,j,n;
    long long sum=0;
    scanf("%d",&n);
    while(n>=15)
    {
        sum+=3000;
        n-=15;
    }
    if(n>=11)
    {
        sum+=3000;
        n = 0;
    }
    while(n>=5)
    {
        sum+=1500;
        n-=5;
    }
    if(n>=4)
    {
        sum+=1500;
        n-=4;
    }
    while(n>=2)
    {
        sum+=800;
        n-=2;
    }
    while(n--)
        sum+=500;
    printf("%lld\n",sum);
    return 0;
}
