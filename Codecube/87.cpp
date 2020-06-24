#include<stdio.h>
#include <iostream>
using namespace std;
long long a[1000001];
int main()
{
    long long num,c,m,v=0,va=0,n;
    scanf("%lld",&n);
    scanf("%lld",&num);
    int max=-1;
    for(m=0; m<n; ++m)
    {
        scanf("%lld",&c);
        a[c]++;
    }
    long long sum=0;
    long long n1=0,n2=num;
    int mod = num%2;
    int nn = num/2;
    for(int i=n1;i<=nn;++i)
    {
        if(i == n2)
        {
            for(int j=1;j<a[i];++j)
            {
                sum+=j;
            }
        }
        else if(i+n2 == num)
        {
            sum = sum +(a[i]*a[n2]);
        }
        --n2;
    }
    printf("%lld",sum);
    return 0;
}

