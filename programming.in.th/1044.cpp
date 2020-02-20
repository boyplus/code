#include <stdio.h>
int num[102][102];
int cost[102][102];
int sum_row_cost[102];
int sum_column_cost[102];
int sum_row[102];
int sum_column[102];
int sum_all=0;
int main()
{
    int i,j,k,n,m,max=-1;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&num[i][j]);
            sum_row[i] = sum_row[i] + num[i][j];
            sum_all+=num[i][j];
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&cost[i][j]);
            sum_row_cost[i] = sum_row_cost[i]+cost[i][j];
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            sum_column[i] = sum_column[i]+num[j][i];
            sum_column_cost[i] = sum_column_cost[i]+cost[j][i];
        }
    }
    for(i=1;i<=n;i++)
    {
        int my_sum = sum_all-sum_row[i]+sum_row_cost[i-1]+sum_row_cost[i+1];
        if(my_sum>max)
            max = my_sum;
    }
    for(i=1;i<=m;i++)
    {
        int my_sum = sum_all - sum_column[i]+sum_column_cost[i-1]+sum_column_cost[i+1];
        if(my_sum>max)
            max = my_sum;
    }
    printf("%d\n",max);
    return 0;
}
