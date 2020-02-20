#include <stdio.h>
#include <iostream>
using namespace std;
long long num[1000000];
int main()
{
    long long i,j,k,n,m;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&num[i]);
    }
    unsigned long long start=n;
    unsigned long long sum_all=0;
    for(i=0;i<n;i++)
    {
        unsigned long long result=0;
        result =((start)*(start+1))/2;
        sum_all = sum_all +((num[i]*result)%2553);
        start--;
    }
    cout << sum_all%2553;
    return 0;
}
