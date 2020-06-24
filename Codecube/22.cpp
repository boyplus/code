#include <stdio.h>
int num[1001][1001]={0};
int main()
{
    int i,j,k,m,n,count=0,x,y,max_x=-1,max_y=-1,count_2=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        if(x > max_x)
            max_x = x;
        if(y > max_y)
            max_y = y;
        num[y][x]++;
    }
    for(i=0;i<=max_y;i++)
    {
        for(j=0;j<=max_x;j++)
        {
            if(num[i][j] == 1)
                count++;
            else if(num[i][j] > 1)
                count_2++;
        }
    }
    printf("%d\n",count+count_2);
    return 0;
}
