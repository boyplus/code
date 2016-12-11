#include <stdio.h>
#include <iostream>
using namespace std;
long long lcm(long long,long long);
long long gcd(long long,long long);
int main()
{
    long long ans=1;
    long long n,num1,i,num2;
    cin >> n;
    cin >> num1;
    for(i=0;i<n-1;i++)
    {
        cin >> num2;
        ans = lcm(num1,num2);
        num1 = ans;
    }
    cout << ans;
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
    long long max = num1;
    long long min = num2;
    if(num1<num2)
    {
        max = num2;
        min = num1;
    }
    long long temp = min;
    long long ans=1;
    for(long long i =min;i>=1;i--)
    {
        if(min%i==0 && max%i==0)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

