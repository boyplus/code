#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
vector <long long>cost1,cost2;
int main()
{
    long long i,j,k,m,n,num;
    scanf("%lld %lld",&n,&m);
    for(i=0; i<n; i++)
    {
        scanf("%lld",&num);
        cost1.push_back(num);
    }
    sort(cost1.begin(),cost1.end());
    for(i=0; i<m; i++)
    {
        scanf("%lld",&num);
        cost2.push_back(num);
    }
    sort(cost2.begin(),cost2.end());
    if(n==1 && m==1)
    {
        printf("%lld",cost1[0]+ cost2[0] + 100);
        return 0;
    }
    long long sum4 = INT_MAX,sum5 = INT_MAX;
    if(n==1)
        sum4 = cost1[0] + cost2[0] + 100;
    if(m==1)
        sum5 = cost1[0] + cost2[0] + 100;
    long long min=9999999999999;
    long long sum1=INT_MAX;
    if(n >1)
        sum1 = cost1[0] + cost1[1];
    long long sum2 = INT_MAX;
    if(m >1)
        sum2 = cost2[0] + cost2[1];
    long long sum3 = INT_MAX;
    sum3 = cost1[0] + 100 + cost2[0];
    if(sum1 < min)
        min = sum1;
    if(sum2 < min)
        min = sum2;
    if(sum3 < min)
        min = sum3;
    if(sum4 < min)
        min = sum4;
    if(sum5 < min)
        min = sum5;
    printf("%lld\n",min);
    return 0;
}
