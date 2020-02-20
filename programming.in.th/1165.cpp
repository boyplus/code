#include <cstdio>
using namespace std;
long long gcd(long long,long long);
int main()
{

    int i,j,k,n,count=2,count_2=0;
    scanf("%d",&n);
    long long num,my_gcd,temp,ans=1;
    scanf("%lld",&temp);
    for(i=1;i<n;i++)
    {
        scanf("%lld",&num);
        my_gcd = gcd(temp,num);
        temp = my_gcd;
    }
    while(my_gcd>1)
    {
        while(my_gcd%count==0)
        {
            my_gcd = my_gcd/count;
            count_2++;
        }
        ans = ans * (count_2+1);
        count_2=0;
        count++;
    }
    printf("%lld\n",ans);
    return 0;
}
long long gcd(long long a,long long b)
{
    if(b!=0)
        return gcd(b,a%b);
    return a;
}
