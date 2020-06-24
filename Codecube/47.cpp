#include <cstdio>
#include <stdlib.h>
#include <limits.h>
int cmp(const void* a,const void* b)
{
    return ( *(int*)a - *(int*)b );
}
using namespace std;
int num[100010],n;
int main()
{
    int i,j,count=0,max = INT_MIN;
    scanf("%d",&n);
    for(i=0; i<n; ++i)
        scanf("%d",&num[i]);
    qsort(num,n,sizeof(int),cmp);
    int prev = -1;
    for(i=0; i<n; i++)
    {
        if(num[i] == prev)
        {
            count++;
            if(count > max)
                max = count;
        }
        else
            count = 0;
        prev = num[i];
    }
    if(max != INT_MIN)
        printf("%d\n",max+1);
    else
        printf("1\n");
    return 0;
}
