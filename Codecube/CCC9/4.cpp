#include <cstdio>
int a[100000],b[100000];
int chk[5000010];
int main()
{
    long long sum=0;
    int i,j,k,m,n;
    scanf("%d",&n);
    for(i=0; i<n; ++i)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for(j=0; j<m; ++j)
        scanf("%d",&b[j]);
    for(i=0; i<n; ++i)
    {
        if(a[i] < 5000000)
        {
            if(chk[a[i]])
                sum = sum + chk[a[i]];
            else
            {
                for(j=0; j<m; ++j)
                    sum = sum + (a[i]^b[j]);
                chk[a[i]] = sum;
            }
        }
        else
        {
            for(j=0; j<m; ++j)
                sum = sum + (a[i]^b[j]);
        }
    }
    printf("%lld\n",sum);
    return 0;
}
