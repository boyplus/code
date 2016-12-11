#include <cstdio>
#include <stdlib.h>
struct rice
{
    int weight;
    double cost;
};
rice data[100001];
int compare(const void* a,const void* b)
{
    rice *riceA = (rice*)a;
    rice *riceB = (rice*)b;
    if(riceA->cost < riceB->cost)
        return -1;
    if(riceA->cost > riceB->cost)
        return 1;
    return 0;
}
int main()
{
    int i,j,k,n,m,a,b,num,choose=0;
    scanf("%d",&n);
    for(i=0; i<n; ++i)
    {
        scanf("%d %d",&a,&b);
        data[i].weight = b;
        data[i].cost = double(a)/b;
    }
    qsort(data,n,sizeof(rice),compare);
    scanf("%d",&m);
    for(i=0; i<m; ++i)
    {
        scanf("%d",&num);
        double sum=0;
        while(num>0)
        {
            if(num > data[choose].weight)
            {
                sum = sum + (data[choose].cost*data[choose].weight);
                num = num - data[choose].weight;
                data[choose].weight = 0;
                ++choose;
            }
            else
            {
                sum = sum + (data[choose].cost*num);
                data[choose].weight = data[choose].weight - num;
                num = 0;
            }
        }
        printf("%.3f\n",sum);
    }
    return 0;
}
