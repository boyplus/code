#include <cstdio>
char str[100010];
int main()
{
    int i,j,n;
    scanf("%d",&n);
    scanf("%s",&str);
    if(n==1 && str[0] == 'X')
    {
        printf("B");
        return 0;
    }
    for(i=0; i<n; ++i)
    {
        if(str[i] == 'B')
        {
            for(j=i-1; j>=0; --j)
            {
                if(str[j] == 'X')
                {
                    if(str[j+1] == 'B')
                    {
                        if(str[j-1] == 'X' || str[j-1] == 'G')
                            str[j] = 'W';
                        else if(str[j-1] == 'B')
                            str[j] = 'W';
                        else if(str[j-1] == 'W')
                            str[j] = 'G';
                    }
                    else if(str[j+1] == 'W')
                    {
                        if(str[j-1] == 'X' || str[j-1] == 'G')
                            str[j] = 'B';
                        else if(str[j-1] == 'W')
                            str[j] = 'B';
                        else if(str[j-1] == 'B')
                            str[j] = 'G';
                    }
                }
                else
                    break;
            }
        }
        else if(str[i] == 'W')
        {
            for(j=i-1; j>=0; --j)
            {
                if(str[j] == 'X')
                {
                    if(str[j+1] == 'W')
                    {
                        if(str[j-1] == 'X' || str[j-1] == 'G')
                            str[j] = 'B';
                        else if(str[j-1] == 'W')
                            str[j] = 'B';
                        else if(str[j-1] == 'B')
                            str[j] = 'G';
                    }
                    else if(str[j+1] == 'B')
                    {
                        if(str[j-1] == 'X' || str[j-1] == 'G')
                            str[j] = 'W';
                        else if(str[j-1] == 'B')
                            str[j] = 'W';
                        else if(str[j-1] == 'W')
                            str[j] = 'G';
                    }
                }
                else
                    break;
            }
        }
    }
    if(str[0] == 'X')
    {
        if(str[1] == 'W' || str[1] == 'X' || str[1] == 'G')
            str[0] = 'B';
        else if(str[1] == 'B' || str[1] == 'X' || str[1] == 'G')
            str[0] = 'W';
    }
    for(i=1; i<n; ++i)
    {
        if(str[i] == 'X')
        {
            if(str[i+1] == 'W')
            {
                if(str[i-1] == 'W')
                    str[i] = 'B';
                else if(str[i-1] == 'B')
                    str[i] = 'G';
            }
            else if(str[i+1] == 'B')
            {
                if(str[i-1] == 'B')
                    str[i] = 'W';
                else if(str[i-1] == 'W')
                    str[i] = 'G';
            }
            else if(str[i+1] == 'X')
            {
                if(str[i-1] == 'W')
                    str[i] = 'B';
                else if(str[i-1] == 'B')
                    str[i] = 'W';
            }
            else if(str[i+1] == 'G')
            {
                if(str[i-1] == 'W')
                    str[i] = 'B';
                else if(str[i-1] == 'B')
                    str[i] = 'W';
            }
        }
    }
    if(str[n-1] == 'X')
    {
        if(str[n-2] == 'B')
            str[n-1] = 'W';
        else if(str[n-2] == 'W')
            str[n-1] = 'B';
    }
    printf("%s",str);
    return 0;
}
