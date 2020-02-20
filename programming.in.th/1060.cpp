#include <cstdio>
char str[200][200];
int s[21],h[21],max_high = -1,n,max_length = -1;
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d %d",&s[i],&h[i]);
        if(h[i] > max_high)
            max_high = h[i];
        int length = s[i] + ((h[i]*2)-1);
        if(length > max_length)
            max_length = length;
    }
    for(i=0; i<max_high; i++)
        for(j=0; j<max_length; j++)
            str[i][j] = '.';
    for(i=0; i<n; i++)
    {
        int top = max_high - h[i];
        int left = s[i] + h[i] - 2;
        int right = left+1;
        for(j=top; j<max_high; j++)
        {
            if(str[j][left] == '.')
                str[j][left] = '/';
            else
                str[j][left] = 'v';
            left--;
        }
        for(j=top; j<max_high; j++)
        {
            if(str[j][right] == '.')
                str[j][right] = '\\';
            else
                str[j][right] = 'v';
            right++;
        }
    }
    for(i=0; i<max_high; i++)
    {
        for(j=0; j<max_length; j++)
        {
            if(str[i][j] == '/' || str[i][j] == 'v')
            {
                int open = 1,temp_j = j+1;
                while(open >= 1&& temp_j < max_length)
                {
                    if(str[i][temp_j] == '\\'  || str[i][temp_j] == 'v')
                        open--;
                    if(str[i][temp_j] == '/')
                        open++;
                    if(open>=1)
                    {
                        str[i][temp_j] = 'X';
                        temp_j++;
                    }
                }
            }
        }
    }
    for(int i=0; i<max_high; i++)
    {
        for(int j=0; j<max_length; j++)
        {
            printf("%c",str[i][j]);
        }
        printf("\n");
    }
    return 0;
}
