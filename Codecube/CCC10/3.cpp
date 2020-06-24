#include <cstdio>
#include <stdlib.h>
struct dat
{
    int power;
}data[10000][100000];
int cmp(const void* a,const void* b)
{
    dat *datA = (dat*)a;
    dat *datB = (dat*)b;
    return datA->power > datB->power;
}
int c[1000000];
int main()
{
    int i,j,k,m,n;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&data[i][j].power);
        }
    }
    for(i=0;i<n;i++)
    {
        qsort(data[i],m,sizeof(dat),cmp);
    }
    int round=0;
    for(i=0;i<m;i++)
    {
        int max = -1,ans=0;
        for(j=0;j<n;j++)
        {
            if(data[j][i].power > max)
            {
                max = data[j][i].power;
                ans = j;
            }
        }
        c[ans]++;
    }
    int max_now=-1,ans_now=0;
    for(i=0;i<n;i++)
    {
        if(c[i] > max_now)
        {
            max_now = c[i];
            ans_now = i;
        }
    }
    printf("%d\n",ans_now+1);
    return 0;
}
