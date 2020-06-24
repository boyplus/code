#include <stdio.h>
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    int count_space = n/2;
    int num_1 = n/2+1;
    int num=0;
    for(i=0;i<num_1;i++)
    {
        for(j=0;j<count_space;j++)
        {
            printf("-");
        }
        num = i*2+1;
        for(j=0;j<num;j++)
        {
            printf("*");
        }
        for(j=0;j<count_space;j++)
        {
            printf("-");
        }
        printf("\n");
        count_space--;
    }
    count_space = 1;
    num-=2;
    num_1--;
    for(i=0;i<num_1;i++)
    {
        for(j=0;j<count_space;j++)
        {
            printf("-");
        }
        for(j=0;j<num;j++)
        {
            printf("*");
        }
        for(j=0;j<count_space;j++)
        {
            printf("-");
        }
        count_space++;
        num-=2;
        printf("\n");
    }
    return 0;
}
