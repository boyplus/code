#include <stdio.h>
int temp[1000000],d[1000000];
int main()
{
    int i,j,n,m,choose,count=0;
    scanf("%d %d",&n,&m);
    for(i=0; i<n; ++i)
        scanf("%d",&d[i]);
    for(i=0; i<m; ++i)
    {
        scanf("%d",&choose);
        if(i+1-temp[choose-1]>=d[choose-1])
        {
            ++count;
            temp[choose-1] = i+1;
        }
    }
    printf("%d",count);
    return 0;
}
