#include <stdio.h>
long long gcd(long long,long long);
int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    long long my_great = gcd(a,b);
    long long mul = a*b;
    long long lcs = mul/my_great;
    printf("%lld\n",lcs);
    return 0;
}
long long gcd(long long num1,long long num2)
{
    if(num2!=0)
        return gcd(num2,num1%num2);
    return num1;
}
