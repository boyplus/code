#include <cstdio>
char str[1010][1010];
int main()
{
    int i,j,k,m,n,count_aunt=0,count_des = 0;
    scanf("%d %d",&m,&n);
    for(i=0; i<m; ++i)
    {
        scanf("%s",&str[i]);
        for(j=0; j<n; ++j)
            if(str[i][j] == 'A')
                ++count_aunt;
    }
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
        {
            if(str[i][j] == 'x')
            {
                if(i > 0 && j>0)
                {
                    if(str[i-1][j-1] == 'A')
                    {
                        ++count_des;
                        str[i-1][j-1] = '.';
                    }
                }
                if(i>0)
                {
                    if(str[i-1][j+1] == 'A')
                    {
                        ++count_des;
                        str[i-1][j+1] = '.';
                    }
                }
                if(i>1 && j> 1)
                {
                    if(str[i-2][j-2] == 'A')
                    {
                        ++count_des;
                        str[i-2][j-2] = '.';
                    }
                }
                if(i >1)
                {
                    if(str[i-2][j+2] == 'A')
                    {
                        ++count_des;
                        str[i-2][j+2] = '.';
                    }
                }
                if(j > 0)
                {
                    if(str[i+1][j-1] == 'A')
                    {
                        ++count_des;
                        str[i+1][j-1] = '.';
                    }
                }
                if(j>1)
                {
                    if(str[i+2][j-2] == 'A')
                    {
                        ++count_des;
                        str[i+2][j-2] = '.';
                    }
                }
                if(str[i+1][j+1] == 'A')
                {
                    ++count_des;
                    str[i+1][j+1] = '.';
                }
                if(str[i+2][j+2] == 'A')
                {
                    ++count_des;
                    str[i+2][j+2] = '.';
                }
                str[i][j] = '.';
            }
            else if(str[i][j] == '+')
            {
                if(i>0)
                {
                    if(str[i-1][j] == 'A')
                    {
                        ++count_des;
                        str[i-1][j] = '.';
                    }
                }
                if(j>0)
                {
                    if(str[i][j-1] == 'A')
                    {
                        ++count_des;
                        str[i][j-1] = '.';
                    }
                }
                if(str[i][j+1] == 'A')
                {
                    ++count_des;
                    str[i][j+1] = '.';
                }
                if(str[i+1][j] == 'A')
                {
                    ++count_des;
                    str[i+1][j] = '.';
                }
                str[i][j] = '.';
            }
        }
    }
    printf("%d\n",count_aunt-count_des);
    for(i=0; i<m; ++i)
       printf("%s\n",str[i]);
    return 0;
}
