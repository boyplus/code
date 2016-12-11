#include <cstdio>
int sum_col_down[1002][1002],sum_col_up[1002][1002];
int main()
{
    int i,j,k,m,n;
    scanf("%d",&k);
    for(int x=0; x<k; x++)
    {
        scanf("%d %d",&m,&n);
        char str[1002][1002];
        for(i=0; i<m; ++i)
            scanf("%s",&str[i]);
        int t = m-1;
        for(i=0; i<n; ++i)
        {
            sum_col_down[0][i] = str[0][i] - 48;
            sum_col_up[t][i] = str[t][i] - 48;
        }
        for(i=0; i<n; ++i)
        {
            for(j=1; j<m; ++j)
            {
                if(str[j][i]!= '0')
                    sum_col_down[j][i] = sum_col_down[j-1][i] + (str[j][i] - 48);
                else
                    sum_col_down[j][i] = 0;
            }
        }
        for(i=0; i<n; ++i)
        {
            for(j=m-2; j>=0; --j)
            {
                if(str[j][i]!= '0')
                    sum_col_up[j][i] = sum_col_up[j+1][i] + (str[j][i]-48);
                else
                    sum_col_up[j][i] = 0;
            }
        }
        int count=0,max=-1;
        for(i=0; i<m; ++i)
        {
            count = 0;
            for(j=0; j<n; ++j)
            {
                if(str[i][j] == '1')
                    ++count;
                else
                    count = 0;
                int my_sum = count + sum_col_up[i][j];
                if(my_sum > max)
                    max = my_sum;
            }
            count = 0;
            for(j=n-1; j>=0; --j)
            {
                if(str[i][j] == '1')
                    ++count;
                else
                    count = 0;
                int my_sum = count + sum_col_up[i][j];
                if(my_sum > max)
                    max = my_sum;
            }
        }
        for(i=0; i<m; ++i)
        {
            count = 0;
            for(j=0; j<n; ++j)
            {
                if(str[i][j] == '1')
                    count++;
                else
                    count = 0;
                int my_sum = count + sum_col_down[i][j];
                if(my_sum > max)
                    max = my_sum;
            }
            count =0;
            for(j=n-1; j>=0; --j)
            {
                if(str[i][j] == '1')
                    ++count;
                else
                    count = 0;
                int my_sum = count + sum_col_down[i][j];
                if(my_sum > max)
                    max = my_sum;
            }
        }
        printf("%d\n",max-1);
    }
    return 0;
}
