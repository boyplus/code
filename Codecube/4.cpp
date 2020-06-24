#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
long long gcd(long long,long long);
int main()
{
    long long i,j,k,n,sum=0;
    scanf("%lld",&n);
    vector <long long> my_num;
    long long num1,num2;
    scanf("%lld",&num1);
    my_num.push_back(num1);
    long long my_gcd = 1;
    for(i=0;i<n-1;i++)
    {
        scanf("%lld",&num2);
        my_num.push_back(num2);
        my_gcd = gcd(num1,num2);
        num1 = my_gcd;
    }
    for(i=0;i<n;i++)
        sum = sum+(my_num[i]/my_gcd);
    printf("%lld",sum);
    return 0;
}
long long gcd(long long num1,long long num2)
{
    if(num2!=0)
        return gcd(num2,num1%num2);
    return num1;
}
