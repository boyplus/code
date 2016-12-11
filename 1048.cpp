#include <cstdio>
long long sum=0;
int main()
{
    int i,j,k,m,n;
    scanf("%d %d",&k,&n);
    for(i=0; i<n; ++i)
    {
        int num = i ^ (i+1);
        while(num >= 1)
        {
            sum = sum + num%2;
            num = num/2;
        }
    }
    printf("%d\n",sum);
    return 0;
}
