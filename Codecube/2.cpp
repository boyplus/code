//Greatest Common Divisor
#include <stdio.h>
using namespace std;
long long gcd(long long,long long);
int main()
{
    long long num1,num2,n,i,ans=1;
    scanf("%lld",&n);
    scanf("%lld",&num1);
    for(i=0;i<n-1;i++)
    {
        scanf("%lld",&num2);
        ans = gcd(num1,num2);
        num1 = ans;
    }
    printf("%lld\n",ans);
    return 0;
}
long long gcd(long long num1,long long num2)
{
    if(num2!=0)
        return gcd(num2,num1%num2);
    return num1;
}
