#include <stdio.h>
int x[5000],y[5000];
int main()
{
    int i,j,k,n,m,x1,y1,r,max=-1,n1,start_x,start_y;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0; i<k; ++i)
    {
        scanf("%d %d %d",&x1,&y1,&r);
        start_x = x1-r,start_y = y1-r;
        if(start_x<0)
            start_x=0;
        if(start_y<0)
            start_y=0;
        n1=x1+r;
        while(start_x<=n1)
        {
            ++x[start_x];
            ++start_x;
        }
        n1 = y1+r;
        while(start_y<=n1)
        {
            ++y[start_y];
            ++start_y;
        }
    }
    for(i=0; i<m; ++i)
        if(x[i]>max)
            max = x[i];
    for(i=0;i<n;i++)
        if(y[i]>max)
            max = y[i];
    printf("%d",max);
    return 0;
}
