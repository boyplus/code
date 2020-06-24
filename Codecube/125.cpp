#include <stdio.h>
int main()
{
    int i,j,k,n,count=0;;
    scanf("%d",&n);
    char str[n+1];
    scanf("%s",str);
    for(i=0;i<n-4;i++)
    {
        if(str[i] == 'S' && str[i+1] == 'H' && str[i+2] == 'I' && str[i+3] == 'F' && str[i+4] == 'T')
        {
            str[i] = '1';
            str[i+1] = '1';
            str[i+2] = '1';
            str[i+3] = '1';
            str[i+4] = '1';
            count++;
        }
    }
    for(i=0;i<n-7;i++)
    {
        if(str[i] == 'S' && str[i+1] == 'P' && str[i+2] == 'A' && str[i+3] == 'C' && str[i+4] == 'E'
           && str[i+5] == 'B' && str[i+6] == 'A' && str[i+7] == 'R')
        {
            str[i] = '1';
            str[i+1] = '1';
            str[i+2] = '1';
            str[i+3] = '1';
            str[i+4] = '1';
            str[i+5] = '1';
            str[i+6] = '1';
            str[i+7] = '1';
            count++;
        }
    }
    for(i=0;i<n;i++)
    {
        if(str[i] == 'Q' || str[i] == 'W' || str[i] == 'E' || str[i] == 'A' || str[i] == 'S' || str[i] == 'D' || str[i] == 'V')
        {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
