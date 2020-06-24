#include <stdio.h>
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    if(n%2==0)
    {
        printf("error\n");
        return 0;
    }
    int num_1 = (n/2)+1;
    int count_dok = n;
    //printf("count = %d\n",count_dok);
    for(i=0;i<num_1;i++)
    {
        for(j=0;j<i;j++)
        {
            printf(" ");
        }
        for(k=0;k<count_dok;k++)
        {
            printf("*");
        }
        count_dok-=2;
        printf("\n");
    }
    num_1--;
    int count_space = num_1-1;
    count_dok=3;
    for(i=0;i<num_1;i++)
    {
        for(j=0;j<count_space;j++)
        {
            printf(" ");
        }
        for(j=0;j<count_dok;j++)
        {
            printf("*");
        }
        count_dok+=2;
        count_space--;
        printf("\n");
    }
    return 0;
}
