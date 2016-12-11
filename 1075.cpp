#include <cstdio>
#include <stdlib.h>
using namespace std;
long long qsum[100001];
struct Worm
{
    int data;
    int cost;
};
Worm worm[100001];
int compare(const void* a,const void* b)
{
    Worm *costA = (Worm*)a;
    Worm *costB = (Worm*)b;
    if(costA->cost < costB->cost)
        return 1;
    if(costA->cost > costB->cost)
        return -1;
    return 0;
}
int main()
{
    long long ans_cost=0,ans_data=0;
    double min =-1;
    int i,j,k,n,m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&worm[i].data,&worm[i].cost);
    qsort(worm,n,sizeof(Worm),compare);
    for(i=n-1;i>=0;i--)
        qsum[i] = qsum[i+1] + worm[i].data;
    for(i=0;i<n;i++)
    {
        double result = double(qsum[i])/worm[i].cost;
        if(result >= min)
        {
            min = result;
            ans_cost = worm[i].cost;
            ans_data = qsum[i];
        }
    }
    printf("%lld %lld\n",ans_data,ans_cost);
    return 0;
}
