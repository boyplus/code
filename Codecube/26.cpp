#include <stdio.h>
int num[1000002];
int main()
{
    int i,j,k,n,m,a,b,max=-1,max_dis=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        num[a]++;
        num[b]--;
        if(b>max_dis)
            max_dis = b;
    }
    int temp = num[0];
    int sum_now=0;
    for(i=1;i<=max_dis;i++)
    {
        sum_now = temp+num[i];
        if(sum_now>max)
            max = sum_now;
        temp = sum_now;
    }
    printf("%d",max);
    return 0;
}
