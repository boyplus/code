#include <stdio.h>
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    char str[(3*n)-3][(2*n)+1];
    for(i=0;i<(3*n)-3;i++)
    {
        for(j=0;j<(2*n)+1;j++)
            str[i][j] = '-';
    }
    int count=n,all=n+1,count_2=0;
    for(i=0;i<n;i++)
    {
        for(j=count-count_2;j<all;j++)
            str[i][j] = '#';
        all++;
        count_2++;
    }
    for(i=n;i<n+n-1;i++)
        for(j=1;j<n*2;j++)
            str[i][j] = '#';
    count = 2;
    count_2 = (n*2)-3;
    all=0;
    for(i=i;i<(3*n)-4;i++)
    {
        for(j=count;j<count_2-all+2;j++)
            str[i][j] = '#';
        count++;
        all++;
    }
    count_2 = 2;
    for(i=n-1;i<n*2-3;i++)
    {
        str[i][count_2] = '-';
        count_2++;
    }
    count_2 =n*2-1;
    for(i=n-2;i<n*2-3;i++)
    {
        str[i][count_2] = '-';
        count_2--;
    }
    count = n*3-3;
    for(i=count;i>=count-n;i--)
        str[i][n] = '-';
    str[0][n] = '-';
    for(int i=0;i<(3*n)-3;i++)
    {
        for(int j=0;j<(n*2)+1;j++)
            printf("%c ",str[i][j]);
        printf("\n");
    }
    return 0;
}
