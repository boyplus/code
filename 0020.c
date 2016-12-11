//array 1 มิติ
#include<stdio.h>
int main()
{
    int i,a1[4],j,a2[4],a3[4],a4[4],a5[4];
    int sum1[5]={0};
    for(i=0;i<4;i++)
    {
        scanf("%d",&a1[i]);
        sum1[0]+=a1[i];
    }
    for(i=0;i<4;i++)
    {
        scanf("%d",&a2[i]);
        sum1[1]+=a2[i];
    }
    for(i=0;i<4;i++)
    {
        scanf("%d",&a3[i]);
        sum1[2]+=a3[i];
    }
    for(i=0;i<4;i++)
    {
        scanf("%d",&a4[i]);
        sum1[3]+=a4[i];
    }
    for(i=0;i<4;i++)
    {
        scanf("%d",&a5[i]);
        sum1[4]+=a5[i];
    }
    int max = -999;
    for(i=0;i<5;i++)
    {
        if(sum1[i] >= max)
            max = sum1[i];
    }
    for(i=0;i<5;i++)
    {
        if(sum1[i] == max)
            printf("%d ",i+1);
    }
    printf("%d",max);
    return 0;
}
