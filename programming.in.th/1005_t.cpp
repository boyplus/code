#include <cstdio>
int num[2501];
int my_sum[2501];
int main()
{
    int i,j,k,max_sum=-1,n,mark=0;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        scanf("%d",&num[i]);
    for(i=1; i<=n; i++)
    {
        my_sum[i] = my_sum[i-1] + num[i];
        if(my_sum[i]<0)
            my_sum[i] =0;
        if(my_sum[i] > max_sum)
        {
            max_sum = my_sum[i];
            mark = i;
        }
    }
    int start=0;
    for(i=mark; i>=0; i--)
    {
        if(my_sum[i]==0)
            break;
        start = i;
    }
    if(max_sum>0)
    {
        for(i=start; i<=mark; i++)
            printf("%d ",num[i]);
        printf("\n%d",max_sum);
    }
    else
        printf("Empty sequence");
    return 0;
}
