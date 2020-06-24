#include <cstdio>
int main()
{
    long long n,sum=1,prev=1;
    scanf("%lld",&n);
    while(n--)
    {
        sum = sum*3;
        sum = sum+prev;
        prev = sum;
    }
    printf("%lld",sum);
    return 0;
}
