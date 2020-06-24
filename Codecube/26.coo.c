#include <stdio.h>
int num[1000002];
int qsum[1000002];
int main()
{
    int i,j,k,n,m,a,b,max=-1,max_dis;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        num[a]++;
        num[b]--;
        if(b>max_dis)
            max_dis = b;
    }
    qsum[0] = num[0];
    for(i=1;i<=max_dis;i++)
    {
        qsum[i] = qsum[i-1]+num[i];
        if(qsum[i]>max)
            max = qsum[i];
    }
    printf("%d",max);
    return 0;
}
