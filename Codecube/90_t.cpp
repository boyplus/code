#include <cstdio>
char str[100][100];
int main()
{
    int i,j,k,m,n;
    scanf("%d %d",&n,&m);
    for(i=0; i<m; i++)
        scanf("%s",&str[i]);
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(str[i][j] == '>')
            {
                int temp_j = j+1;
                while(str[i][temp_j] == '.' || str[i][temp_j] == '|')
                {
                    if(str[i][temp_j] == '.')
                        str[i][temp_j] = '-';
                    else if(str[i][temp_j] == '|')
                        str[i][temp_j] = '+';
                    temp_j++;
                }
            }
            else if(str[i][j] == '<')
            {
                int temp_j = j-1;
                while(str[i][temp_j] == '.' || str[i][temp_j] == '|')
                {
                    if(str[i][temp_j] == '.')
                        str[i][temp_j] = '-';
                    else if(str[i][temp_j] == '|')
                        str[i][temp_j] = '+';
                    temp_j--;
                }
            }
            else if(str[i][j] == 'V')
            {
                int temp_i = i+1;
                while(str[temp_i][j] == '.' || str[temp_i][j] == '-')
                {
                    if(str[temp_i][j] == '.')
                        str[temp_i][j] = '|';
                    else if(str[temp_i][j] == '-')
                        str[temp_i][j] = '+';
                    temp_i++;
                }
            }
            else if(str[i][j] == '^')
            {
                int temp_i = i-1;
                while(str[temp_i][j] == '.' || str[temp_i][j] == '-')
                {
                    if(str[temp_i][j] == '.')
                        str[temp_i][j] = '|';
                    else if(str[temp_i][j] == '-')
                        str[temp_i][j] = '+';
                    temp_i--;
                }
            }
            else if(str[i][j] == 'B')
                str[i][j] = '*';
        }
    }
    for(i=0; i<m; i++)
        printf("%s\n",str[i]);
    return 0;
}
