#include <cstdio>
#include <limits.h>
#include <math.h>
int num[6000];
int main()
{
    int i,j,n,x,num1 = INT_MAX,num2 = INT_MAX;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        num[x]++;
    }
    bool chk1 = false,chk2 = false;
    for(i=2017;i>=0;i--)
    {
        if(num[i] == 1)
        {
            chk1 = true;
            num1 = i;
            break;
        }
    }
    for(i=2018;i<=4000;i++)
    {
        if(num[i] == 1)
        {
            chk2 = true;
            num2 = i;
            break;
        }
    }
    if(!chk1 && !chk2)
    {
        printf("-1");
        return 0;
    }
    int t1 = fabs(2017-num1),t2 = fabs(2017-num2);
    if(t1 < t2)
        printf("%d\n",num1);
    else
        printf("%d\n",num2);
    return 0;
}
