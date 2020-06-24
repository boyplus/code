#include <cstdio>
#include <limits.h>
int main()
{
    int n,num[3],i,j,round=0;
    scanf("%d",&n);
    for(i=0; i<3; i++)
        scanf("%d",&num[i]);
    for(i=0; i<n; i++)
    {
        int min = INT_MAX;
        for(j=0; j<3; j++)
            if(num[j] > num[round])
                if(num[j] < min)
                    min = num[j];
        if(min != INT_MAX)
            num[round] = num[round] + ((min - num[round])*2);
        round++;
        if(round > 2)
            round = 0;
    }
    for(j=0; j<3; j++)
        printf("%d\n",num[j]);
    return 0;
}
