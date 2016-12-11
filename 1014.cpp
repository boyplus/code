#include <stdio.h>
int num[4000]={0};
int num_a[100]={0};
int num_b[100]={0};
int main()
{
    int i,j,k,n,h,w;
    scanf("%d %d %d",&w,&h,&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&num_a[i],&num_b[i]);
    for(i=0;i<n;i++)
        for(j = num_a[i];j<=num_b[i]+num_a[i]-1;j++)
            num[j]++;
    int count_zero=0,count_one=0;
    for(i=0;i<w;i++)
    {
        if(num[i] == 0)
            count_zero++;
        else if(num[i] == 1)
            count_one++;
    }
    printf("%d %d",count_zero*h,count_one*h);
    return 0;
}
