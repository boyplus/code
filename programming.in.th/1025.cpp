// Least Common Multiplier
#include <stdio.h>
long long lcm(long long,long long);
long long gcd(long long,long long);
int main()
{
    long long ans=1;
    long long n,num1,i,num2;
    scanf("%lld",&n);
    scanf("%lld",&num1);
    for(i=0;i<n-1;i++)
    {
        scanf("%lld",&num2);
        ans = lcm(num1,num2);
        num1 = ans;
    }
    printf("%lld",ans);
    return 0;
}
long long lcm(long long num1,long long num2)
{
    long long greate = gcd(num1,num2);
    long long lcm = (num1*num2)/greate;
    return lcm;
}
long long gcd(long long num1,long long num2)
{
    if(num2!=0)
        return gcd(num2,num1%num2);
    return num1;
}

