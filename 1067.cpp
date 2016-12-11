#include <stdio.h>
int main()
{
    int n,i,j,k,m,l,p;
    scanf("%d %d %d",&n,&m,&k);
    int num[m][n];
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
    int position_x[k],position_y[k];
    for(i=0; i<k; i++)
    {
        scanf("%d %d",&position_x[i],&position_y[i]);
    }
    int count=0;
    for(i=0; i<k; i++)
    {
        position_x[i]--;
        position_y[i]--;
        count =0;
        while(1)
        {
            if(num[position_y[i]][position_x[i]] == 1)
            {
                position_y[i]--;
                count++;
            }
            else if(num[position_y[i]][position_x[i]] == 2)
            {
                position_x[i]++;
                count++;
            }
            else if(num[position_y[i]][position_x[i]] == 3)
            {
                position_y[i]++;
                count++;
            }
            else if(num[position_y[i]][position_x[i]] == 4)
            {
                position_x[i]--;
                count++;
            }
            if(position_x[i] >=n)
            {
                printf("E\n");
                break;
            }
            if(position_x[i] <= -1)
            {
                printf("W\n");
                break;
            }
            if(position_y[i] >= m)
            {
                printf("S\n");
                break;
            }
            if(position_y[i] <= -1)
            {
                printf("N\n");
                break;
            }
            if(count > n*m)
            {
                printf("NO\n");
                break;
            }
        }
    }
    return 0;
}
