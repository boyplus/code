#include <cstdio>
#include <stdlib.h>
int num[1000000];
int cmp(const void* a,const void *b)
{
    return ( *(int*)b - *(int*)a );
}
int main()
{
    int i,j,k,m,n,w,max=-1,count=0;
    scanf("%d %d %d",&n,&w,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    qsort(num,n,sizeof(int),cmp);
    for(i=0;i<n;i++)
        printf("%d ",num[i]);
    max = num[0];
    for(i=0;i<n;i++)
    {
        if(num[i] == max)
        {
            count++;
        }
    }
    return 0;
}
