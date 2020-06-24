#include <cstdio>
#include <limits.h>
int num[500010],n,k,edge=0;
int main()
{
    int i,j;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    int index = 0,temp = index+k;
    while(temp < n-1)
    {
        //Add value
        for(int i = edge+1;i<=temp;i++)
            num[i] = num[i] + num[index];
        edge = index+k;
        //Find min
        int min = INT_MAX,ans=0;
        for(i=index+1;i<=temp;i++)
        {
            if(num[i] <= min)
            {
                min = num[i];
                ans = i;
            }
        }
        index = ans;
        temp = index+k;
    }
    printf("%d\n",num[index]+num[n-1]);
    return 0;
}
