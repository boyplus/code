#include <stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int one[n],three_four[n],one_two[n],one_four[n],one_eight[n];
    int one_=0,three_four_=0,one_two_=0,one_four_=0,one_eight_=0;
    float sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d %d",&one[i],&three_four[i],&one_two[i],&one_four[i],&one_eight[i]);
        sum = sum+(one[i]*1.0)+(three_four[i]*0.75)+(one_two[i]*0.5)+(one_four[i]*0.25)+(one_eight[i]*0.125);
    }
    int sum_2 = sum;
    float sum_3 = sum-sum_2*1.00;
    if(sum_3 !=0)
        printf("%d",sum_2+1);
    else
    printf("%d",sum_2);
    return 0;
}
