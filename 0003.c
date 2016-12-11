#include<stdio.h>
int main()
{
    unsigned int i,a,x,y;
    scanf("%d %d",&x,&y);
     int num1[x][y];
     int num2[x][y];
     int sum[x][y];
    for(i=0;i<x;i++)
    {
        for(a=0;a<y;a++)
        {
            scanf("%d",&num1[i][a]);
            sum[i][a] = 0;
        }
    }
    for(i=0;i<x;i++)
    {
        for(a=0;a<y;a++)
        {
            scanf("%d",&num2[i][a]);
        }
    }
    for(i=0;i<x;i++)
    {
        for(a=0;a<y;a++){
            sum[i][a]+=num1[i][a]+num2[i][a];
            printf("%d ",sum[i][a]);
        }
            printf("\n");
    }
    return 0;
}
