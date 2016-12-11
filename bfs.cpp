#include <stdio.h>
#include <queue>
int link[1000][1000];
int main()
{
    std::queue<int> q;
    int n,a,b,count=0;
    //scanf("%d",&n);
    for(int i=0;a!=0;i++)
    {
        scanf("%d%d",&a,&b);
        link[a][b]=1;
    }
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
            printf("%d ",link[i][j]);
        }
        printf("\n");
    }
    int node = 1;
    while(1)
    {
        for(int i=node+1;i<=10;i++)
        {
            if(link[node][i]==1)
            {

            }
        }
    }
}

