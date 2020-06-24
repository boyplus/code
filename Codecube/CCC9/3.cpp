#include <cstdio>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
struct po
{
    int x;
    int y;
} data[200000];
int cmp(const void* a,const void* b)
{
    po *poA = (po*)a;
    po *poB = (po*)b;
    return poB->y - poA->y;
}
int main()
{
    int i,j,k,m,n,q,h;
    scanf("%d",&q);
    for(i=0; i<q; i++)
    {
        scanf("%d %d",&n,&h);
        for(j=0; j<n; j++)
            scanf("%d %d",&data[j].x,&data[j].y);
        qsort(data,n,sizeof(po),cmp);
        int min = INT_MAX;
        bool chk = false;
        for(j=0;j<n;j++)
        {
            int now_node = n-1;
            while((data[j].y - data[now_node].y) >=h)
            {
                int num = data[j].x - data[now_node].x;
                if(num < 0)
                    num = num*-1;
                now_node--;
                if(num < min)
                    min = num;
                chk = true;
            }
        }
        if(chk)
            printf("%d\n",min);
        else
            printf("-1\n");
    }
    return 0;
}
