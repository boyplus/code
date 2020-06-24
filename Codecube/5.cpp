#include <stdio.h>
long long gcd(long long,long long);
long long lcm(long long,long long);
int main()
{
    long long num1,temp,num2;
    int i,j,k,n;
    scanf("%d",&n);
    scanf("%lld",&num1);
    long long ans = 1;
    for(i=0;i<n-1;i++)
    {
        scanf("%lld",&num2);
        ans = lcm(num1,num2);
        num1 = ans;
    }
    printf("%lld\n",ans);
    return 0;
}
long long lcm(long long num1,long long num2)
{
    long long my_gcd = gcd(num1,num2);
    long long my_lcm = (num1*num2)/my_gcd;
    return my_lcm;
}
long long gcd(long long num1,long long num2)
{
    if(num2!=0)
        return gcd(num2,num1%num2);
    return num1;
}
