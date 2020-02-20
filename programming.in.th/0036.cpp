#include <stdio.h>
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    long long ans=0;
    long long result_1=1;
    long long result_2=1;
    long temp = n/2;
    for(i=n; i>temp; i--)
        result_1*=i;
    if(n%2==1)
        temp++;
    for(i=1; i<=temp; i++)
        result_2*=i;
    ans = result_1/result_2;
    if(n%2==1)
        ans = ans*2;
    printf("%lld",ans);
    return 0;
}
