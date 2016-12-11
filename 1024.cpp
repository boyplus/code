#include <stdio.h>
#include <limits.h>
using namespace std;
int num[1000],sum[1000];
int main()
{
    int ans_min = INT_MAX;
    int ans_start = 0,ans_end=0;
    int i,j,k,n,m;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&num[i]);
        sum[i] = sum[i-1]+num[i];
    }
    int n_2=n-2,n_3=n-1,s1,s2,s3,temp;
    for(i=1; i<=n_2; i++)
    {
        s1 = sum[i];
        for(j=i+1;j<=n_3;j++)
        {
            int min=INT_MAX,max=INT_MIN;
            s2 = sum[j] - sum[i];
            s3 = sum[n] - sum[j];
            if(s1>max)
                max = s1;
            if(s2>max)
                max = s2;
            if(s3>max)
                max = s3;
            if(s1<min)
                min = s1;
            if(s2<min)
                min = s2;
            if(s3<min)
                min = s3;
            temp = max-min;
            if(temp==0)
            {
                printf("%d %d\n",i+1,j+1);
                return 0;
            }
            if(temp<ans_min)
            {
                ans_min = temp;
                ans_start = i;
                ans_end = j;
            }
        }
    }
    printf("%d %d\n",ans_start+1,ans_end+1);
    return 0;
}
