#include <stdio.h>
#include <math.h>
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    int num[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    int max=0;
    int max_2=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            //printf("(%d,%d)",i,j);
            max = num[i]+num[j];
            if(max >= max_2)
            {
                max_2 = max;
                //printf("max = %d + %d = %d\n",num[i],num[j],max);
            }
        }
        //printf("\n");
        max =0;
    }
    printf("max_2 = %d\n",max_2);
    return 0;
}
