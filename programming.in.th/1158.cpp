#include <cstdio>
int num[1001][1001];
int sum_r[1001][1001];
int qsum[1001][1001];
int main()
{
    int i,j,k,n,m,max=-1;
    scanf("%d %d %d",&m,&n,&k);
    for(i=1;i<=m;++i)
    {
        for(j=1;j<=n;++j)
        {
            scanf("%d",&num[i][j]);
            sum_r[i][j] = sum_r[i][j-1]+num[i][j];
        }
    }
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            qsum[j][i] = qsum[j-1][i] + sum_r[j][i];
    for(i=k;i<=m;++i)
    {
        for(j=k;j<=n;++j)
        {
            int my_sum = qsum[i][j]-qsum[i][j-k]-qsum[i-k][j]+qsum[i-k][j-k];
            if(my_sum>max)
                max = my_sum;
        }
    }
    printf("%d\n",max);
    return 0;
}
