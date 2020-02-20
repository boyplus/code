#include <stdio.h>
int table[102][42],ans[40],t;
void Trav(int,int,int);
int main()
{
    int num,n,m;
    scanf("%d %d %d",&m,&n,&t);
    for(int i=1; i<=t; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&num);
            if(!num)
                table[i][j]=1;
        }
    }
    Trav(0,n,0);
    return 0;
}
void Trav(int y,int x,int dis)
{
    if(dis==t)
    {
        for(int i=0; i<t; i++)
            printf("%d\n",ans[i]);
        return;
    }
    if(table[y+1][x-1]==1)
    {
        ans[dis]=1;
        Trav(y+1,x-1,dis+1);
    }
    if(table[y+1][x]==1)
    {
        ans[dis]=3;
        Trav(y+1,x,dis+1);
    }
    if(table[y+1][x+1]==1)
    {
        ans[dis]=2;
        Trav(y+1,x+1,dis+1);
    }
    return;
}
