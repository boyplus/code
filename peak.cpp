#include <cstdio>
#include <vector>
#include <stdlib.h>
int compare(const void* a,const void* b)
{
    int *aa = (int*)a;
    int *bb = (int*)b;
    return bb-aa;
}
using namespace std;
int num[5000000];
vector<int> vec;
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&num[i]);
    }
    for(i=1; i<=n; i++)
    {
        if(num[i]>=num[i-1]&&num[i]>=num[i+1])
        {
            vec.push_back(num[i]);
        }
    }
    int my_size = vec.size();
    qsort(&vec[0],my_size,sizeof(int),compare);
    for(i=0;i<=k;i++)
    {
        printf("%d ",vec[i]);
    }
}
