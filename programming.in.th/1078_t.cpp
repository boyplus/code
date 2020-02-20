#include <stdio.h>
#include <stdlib.h>

int data[1000001];

int compare(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int a,n,l;
    long long int sum=0;

    scanf("%d",&n);
    for (a=0;a<n;a++)
        scanf("%d",&data[a]);

    qsort(data,n,sizeof(int),compare);
    printf("%lld",sum);

    return 0;
}
