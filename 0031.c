#include <stdio.h>
#include <math.h>
int main()
{
    int num[3]={0},i,j,count=0,temp=0;
    scanf("%d %d %d",&num[0],&num[1],&num[2]);
    int max = num[0];
    while(1)
    {
        for(i=0;i<3;i++)
        {
            if(num[i] >= max)
            {
                max = num[i];
                temp = i;
            }
        }
        if(num[temp]%2==1)
        {
            num[temp] = num[temp]-1;
            max = max-1;
        }
        num[temp] = num[temp]/2;
        max = max/2;
        count++;
        if(num[0]==1&&num[1]==1&&num[2]==1)
        {
            break;
        }
    }
    printf("%d\n",count);
    return 0;
}
