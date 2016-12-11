#include <cstdio>
#include <stdlib.h>
int compare(const void* a,const void *b)
{
    return ( *(int*)a - *(int*)b );
}
int num[1000001];
using namespace std;
int main()
{
    int i,j,k,n,m;
    scanf("%d",&n);
    for(i=0; i<n; ++i)
        scanf("%d",&num[i]);
    int now_end=n-1;
    qsort(num,n,sizeof(int),compare);
    int n_2 = n/2,dif;
    unsigned long long sum=0;
    for(i=0; i<n_2; ++i)
    {
        sum = sum+num[now_end] - num[i];
        --now_end;
    }
    printf("%llu\n",sum);
    return 0;
}
