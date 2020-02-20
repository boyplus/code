#include <cstdio>
#include <stdlib.h>
struct boom
{
    int y;
    int x;
} data[1000000];
int cmp(const void* a,const void* b)
{
    boom *boomA = (boom*)a;
    boom *boomB = (boom*)b;
    if(boomA->y > boomB->y)
        return 1;
    if(boomA->y < boomB->y)
        return -1;
    if(boomA->x > boomB->x)
        return -1;
}
bool chk[1000000];
int main()
{
    int i,k,j,n;
    scanf("%d",&n);
    for(i=0; i<n; ++i)
        scanf("%d %d",&data[i].y,&data[i].x);
    qsort(data,n,sizeof(boom),cmp);
    int max = -1,temp_y=-1;
    for(i=n-1;i>=0;--i)
    {
        if(data[i].x >= max)
        {
            chk[i] = true;
            max = data[i].x;
        }
    }
    for(i=0;i<n;++i)
        if(chk[i])
            printf("%d %d\n",data[i].y,data[i].x);
    return 0;
}
