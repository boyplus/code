#include <cstdio>
#include <stdlib.h>
struct mission
{
    long long energy;
    long long exp;
    double val;
}data[100000];
int compare(const void* a,const void* b)
{
    mission *missionA = (mission*)a;
    mission *missionB = (mission*)b;
    if(missionB->val > missionA->val)
        return 1;
    return -1;
}
int main()
{
    long long i,j,n;
    scanf("%lld",&n);
    for(i=0;i<n;++i)
    {
        scanf("%lld %lld",&data[i].energy,&data[i].exp);
        data[i].val = (data[i].exp) - (2*data[i].energy);
    }
    qsort(data,n,sizeof(mission),compare);
    long long max_now = -1 * n *n,count=n-1,sum_exp=0,sum_energy=0;
    for(i=0;i<n;++i)
    {
        long long temp_exp = data[i].exp + sum_exp;
        long long temp_energy = data[i].energy + sum_energy;
        long long temp_cost = count*count;
        long long sum_all = (temp_exp) - 2*(temp_energy) - (temp_cost);
        if(sum_all >= max_now)
        {
            max_now = sum_all;
            sum_exp = temp_exp;
            sum_energy = temp_energy;
            --count;
        }
        else
            break;
    }
    printf("%lld\n",max_now);
    return 0;
}
